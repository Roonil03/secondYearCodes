#include <LPC17xx.h>
#include <stdlib.h>
#include <stdio.h>

#define RS_CTRL 0x08000000 // P0.27
#define EN_CTRL 0x10000000 // P0.28  
#define DT_CTRL 0x07800000 // P0.23 to P0.26 data lines

unsigned long int temp1=0, temp2=0, i, j;
unsigned char flag1 = 0, flag2 = 0;
unsigned char die_result = 0;
unsigned char die_pressed = 0;
char display_msg[20];

void lcd_write(void);
void port_write(void);
void delay_lcd(unsigned int);
void lcd_init(void);
void lcd_clear(void);
void lcd_puts(char *str);
void lcd_gotoxy(unsigned char x, unsigned char y);
unsigned int generate_random_seed(void);

unsigned long int init_command[] = {0x30,0x30,0x30,0x20,0x28,0x0c,0x06,0x01,0x80};

int main(void)
{
    LPC_PINCON->PINSEL1 &= 0xFC03FFFF;
    LPC_GPIO0->FIODIR = DT_CTRL | RS_CTRL | EN_CTRL;     
    LPC_PINCON->PINSEL4 &= ~(3<<24); 
    LPC_PINCON->PINSEL4 |= (1<<24);  
    LPC_SC->EXTMODE |= (1<<2);   
    LPC_SC->EXTPOLAR &= ~(1<<2); 
    LPC_SC->EXTINT |= (1<<2);    
    NVIC_EnableIRQ(EINT2_IRQn);
    lcd_init();
    delay_lcd(50000);
    srand(generate_random_seed());
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_puts("DIE TOSS READY");
    lcd_gotoxy(0,1);
    lcd_puts("Press SW2 to toss");    
    while(1)
    {
        if(die_pressed == 1)
        {
            die_pressed = 0;
            die_result = (rand() % 6) + 1;
            srand(generate_random_seed());
            lcd_clear();
            lcd_gotoxy(0,0);
            lcd_puts("DIE RESULT:");            
            lcd_gotoxy(0,1);
            sprintf(display_msg, "   >>> %d <<<", die_result);
            lcd_puts(display_msg);
            for(i=0; i<500000; i++);
            lcd_clear();
            lcd_gotoxy(0,0);
            lcd_puts("DIE TOSS READY");
            lcd_gotoxy(0,1);
            lcd_puts("Press SW2 to toss");
        }
        for(i=0; i<1000; i++);
    }
}

void EINT2_IRQHandler(void)
{
    LPC_SC->EXTINT |= (1<<2);
    die_pressed = 1;           
}

void lcd_init(void)
{
    flag1 = 0;
    for(i=0; i<9; i++)
    {
        temp1 = init_command[i];
        lcd_write();
        delay_lcd(50000);
    }
}

void lcd_clear(void)
{
    flag1 = 0;
    temp1 = 0x01;
    lcd_write();
    delay_lcd(50000);
}

void lcd_gotoxy(unsigned char x, unsigned char y)
{
    flag1 = 0;
    if(y == 0)
        temp1 = 0x80 + x;
    else
        temp1 = 0xC0 + x;
    lcd_write();
    delay_lcd(5000);
}

void lcd_puts(char *str)
{
    flag1 = 1; 
    i = 0;
    while(str[i] != '\0')
    {
        temp1 = str[i];
        lcd_write();
        delay_lcd(5000);
        i++;
    }
}

void lcd_write(void)
{
    flag2 = (flag1 == 1) ? 0 : ((temp1 == 0x30) || (temp1 == 0x20)) ? 1 : 0;
    temp2 = temp1 & 0xf0;
    temp2 = temp2 << 19;
    port_write();    
    if(flag2 == 0)
    {
        temp2 = temp1 & 0x0f;
        temp2 = temp2 << 23;
        port_write();
    }
}

void port_write(void)
{
    LPC_GPIO0->FIOPIN = temp2;    
    if(flag1 == 0)
        LPC_GPIO0->FIOCLR = RS_CTRL;
    else
        LPC_GPIO0->FIOSET = RS_CTRL;        
    LPC_GPIO0->FIOSET = EN_CTRL;
    delay_lcd(25);
    LPC_GPIO0->FIOCLR = EN_CTRL;
    delay_lcd(30000);
}

void delay_lcd(unsigned int r1)
{
    unsigned int r;
    for(r=0; r<r1; r++);
    return;
}

unsigned int generate_random_seed(void)
{
    return (unsigned int)(LPC_TIM0->TC ^ LPC_TIM1->TC);
}
