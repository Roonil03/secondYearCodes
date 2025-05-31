#include <LPC17xx.h>
#include <stdio.h>

#define RS_CTRL 0x08000000 // P0.27
#define EN_CTRL 0x10000000 // P0.28  
#define DT_CTRL 0x07800000 // P0.23 to P0.26 data lines

unsigned char col, row, flag, key;
unsigned long int temp, var1, temp3, i;
unsigned char keypad_matrix[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
unsigned char ascii_code[16] = {'0','1','2','3','4','5','6','7','8','9','+','-','*','/','=','C'};

unsigned char operand1 = 0, operand2 = 0, operator = 0;
unsigned char input_state = 0; // 0=waiting for A, 1=waiting for operator, 2=waiting for B, 3=waiting for =
int result = 0;
char display_buffer[20];

void scan(void);
void lcd_init(void);
void lcd_write(void);
void port_write(void);
void delay_lcd(unsigned int);
void lcd_clear(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_puts(char *str);
void process_key(unsigned char pressed_key);
void display_expression(void);

unsigned long int temp1=0, temp2=0;
unsigned char flag1=0, flag2=0;
unsigned long int init_command[] = {0x30,0x30,0x30,0x20,0x28,0x0c,0x06,0x01,0x80};

int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();
    
    // Configure keyboard pins
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF; // P1.23 to P1.26 GPIO (columns)
    LPC_PINCON->PINSEL4 &= 0xF00FFFFF; // P2.10 to P2.13 GPIO (rows)
    LPC_GPIO2->FIODIR |= 0x00003C00;   // P2.10 to P2.13 output (rows)
    LPC_GPIO1->FIODIR &= 0xF87FFFFF;   // P1.23 to P1.26 input (columns)
    
    LPC_PINCON->PINSEL1 &= 0xFC03FFFF; 
    LPC_GPIO0->FIODIR = DT_CTRL | RS_CTRL | EN_CTRL;
    
    lcd_init();
    delay_lcd(50000);
    
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_puts("CALCULATOR READY");
    lcd_gotoxy(0,1);
    lcd_puts("Enter: A op B =");
    
    while(1)
    {
        for(row=1; row<5; row++)
        {
            if(row == 1)
                var1 = 0x00000400;     // P2.10
            else if(row == 2)
                var1 = 0x00000800;     // P2.11
            else if(row == 3)
                var1 = 0x00001000;     // P2.12
            else if(row == 4)
                var1 = 0x00002000;     // P2.13                
            LPC_GPIO2->FIOCLR = 0x00003C00;
            LPC_GPIO2->FIOSET = var1;            
            flag = 0;
            scan();
            
            if(flag == 1)
            {
                key = row * 4 + col - 4;
                if(key < 16)
                {
                    unsigned char pressed_char = ascii_code[key];
                    process_key(pressed_char);
                    for(i=0; i<100000; i++);
                }
                break;
            }
        }
        for(i=0; i<1000; i++);
    }
}

void process_key(unsigned char pressed_key)
{
    switch(input_state)
    {
        case 0:
            if(pressed_key >= '0' && pressed_key <= '9')
            {
                operand1 = pressed_key - '0';
                input_state = 1;
                display_expression();
            }
            else if(pressed_key == 'C')
            {
                operand1 = operand2 = operator = 0;
                input_state = 0;
                result = 0;
                lcd_clear();
                lcd_gotoxy(0,0);
                lcd_puts("CALCULATOR READY");
                lcd_gotoxy(0,1);
                lcd_puts("Enter: A op B =");
            }
            break;            
        case 1: 
            if(pressed_key == '+' || pressed_key == '-')
            {
                operator = pressed_key;
                input_state = 2;
                display_expression();
            }
            else if(pressed_key == 'C')
            {
                operand1 = operand2 = operator = 0;
                input_state = 0;
                result = 0;
                lcd_clear();
                lcd_gotoxy(0,0);
                lcd_puts("CALCULATOR READY");
                lcd_gotoxy(0,1);
                lcd_puts("Enter: A op B =");
            }
            break;            
        case 2: 
            if(pressed_key >= '0' && pressed_key <= '9')
            {
                operand2 = pressed_key - '0';
                input_state = 3;
                display_expression();
            }
            else if(pressed_key == 'C')
            {
                operand1 = operand2 = operator = 0;
                input_state = 0;
                result = 0;
                lcd_clear();
                lcd_gotoxy(0,0);
                lcd_puts("CALCULATOR READY");
                lcd_gotoxy(0,1);
                lcd_puts("Enter: A op B =");
            }
            break;            
        case 3: 
            if(pressed_key == '=')
            {
                if(operator == '+')
                    result = operand1 + operand2;
                else if(operator == '-')
                    result = operand1 - operand2;
                lcd_clear();
                lcd_gotoxy(0,0);
                sprintf(display_buffer, "%d %c %d = %d", operand1, operator, operand2, result);
                lcd_puts(display_buffer);
                lcd_gotoxy(0,1);
                lcd_puts("Press C to clear");
                
                input_state = 4; // Result displayed state
            }
            else if(pressed_key == 'C')
            {
                operand1 = operand2 = operator = 0;
                input_state = 0;
                result = 0;
                lcd_clear();
                lcd_gotoxy(0,0);
                lcd_puts("CALCULATOR READY");
                lcd_gotoxy(0,1);
                lcd_puts("Enter: A op B =");
            }
            break;
            
        case 4: // Result displayed, waiting for clear
            if(pressed_key == 'C')
            {
                operand1 = operand2 = operator = 0;
                input_state = 0;
                result = 0;
                lcd_clear();
                lcd_gotoxy(0,0);
                lcd_puts("CALCULATOR READY");
                lcd_gotoxy(0,1);
                lcd_puts("Enter: A op B =");
            }
            break;
    }
}

void display_expression(void)
{
    lcd_clear();
    lcd_gotoxy(0,0);    
    sprintf(display_buffer, "Expr: ");    
    if(input_state >= 1)
        sprintf(display_buffer + 6, "%d", operand1);
    if(input_state >= 2)
        sprintf(display_buffer + 7, " %c", operator);
    if(input_state >= 3)
        sprintf(display_buffer + 9, " %d", operand2);
    if(input_state >= 3)
        sprintf(display_buffer + 11, " =");
    
    lcd_puts(display_buffer);
    lcd_gotoxy(0,1);
    lcd_puts("Continue input...");
}

void scan(void)
{
    temp3 = LPC_GPIO1->FIOPIN;
    temp3 &= 0x07800000;
    
    if(temp3 != 0x00000000)
    {
        flag = 1;
        if(temp3 == 0x00800000)
            col = 0;
        else if(temp3 == 0x01000000)
            col = 1;
        else if(temp3 == 0x02000000)
            col = 2;
        else if(temp3 == 0x04000000)
            col = 3;
    }
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
