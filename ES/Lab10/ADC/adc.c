#include<LPC17xx.h>
#include<stdio.h>

#define RS_CTRL 0x08000000
#define EN_CTRL 0x10000000
#define DT_CTRL 0x07800000

unsigned long int temp1=0, temp2=0, i;
unsigned char flag1=0, flag2=0;
unsigned long int init_command[] = {0x30,0x30,0x30,0x20,0x28,0x0c,0x06,0x01,0x80};

void lcd_write(void);
void port_write(void);
void delay_lcd(unsigned int);
void lcd_init(void);
void lcd_clear(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_puts(char *str);

int main(void)
{
    unsigned long adc4_temp, adc5_temp;
    unsigned int diff_value;
    char diff_str[10];
    char msg1[15] = {"ADC Difference:"};
    LPC_SC->PCONP |= (1<<15);
    lcd_init();    
    LPC_PINCON->PINSEL3 |= 0x30000000;
    LPC_PINCON->PINSEL3 |= 0xC0000000;
    LPC_SC->PCONP |= (1<<12);    
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_puts(&msg1[0]);
    
    while(1)
    {
        LPC_ADC->ADCR = (1<<4)|(1<<21)|(1<<24);
        while((adc4_temp = LPC_ADC->ADGDR) == 0x80000000);
        adc4_temp = LPC_ADC->ADGDR;
        adc4_temp >>= 4;
        adc4_temp &= 0x00000FFF;        
        LPC_ADC->ADCR = (1<<5)|(1<<21)|(1<<24);
        while((adc5_temp = LPC_ADC->ADGDR) == 0x80000000);
        adc5_temp = LPC_ADC->ADGDR;
        adc5_temp >>= 4;
        adc5_temp &= 0x00000FFF;        
        if(adc5_temp > adc4_temp)
            diff_value = adc5_temp - adc4_temp;
        else
            diff_value = adc4_temp - adc5_temp;        
        sprintf(diff_str,"%04d",diff_value);        
        lcd_gotoxy(0,1);
        lcd_puts(&diff_str[0]);        
        for(i=0;i<200000;i++);
    }
}

void lcd_init(void)
{
    LPC_GPIO0->FIODIR = DT_CTRL | RS_CTRL | EN_CTRL;
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
