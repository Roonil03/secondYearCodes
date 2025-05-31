#include <LPC17xx.h>

#define D0 0xF87FFFFF
#define D1 0xF8FFFFFF  
#define D2 0xF97FFFFF
#define D3 0xF9FFFFFF
#define OFF 0xFA7FFFFF

unsigned char array_dec[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int dig1 = 9, dig2 = 9, dig3 = 9, dig4 = 9;
unsigned int dig_count = 0x01;
unsigned int temp1 = 0x00;
unsigned long int temp2 = 0x00000000;
unsigned long int i = 0;
unsigned char one_sec_flag = 0x00;

void display(void);
void timer_init(void);
void TIMER0_IRQHandler(void);

int main(void)
{
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF;    
    LPC_GPIO0->FIODIR |= 0x00000FF0;
    LPC_GPIO1->FIODIR |= 0x07800000;    
    timer_init();    
    while(1)
    {
        dig_count++;
        if(dig_count == 0x05)
        {
            dig_count = 0x01;
        }        
        if(one_sec_flag == 0xFF)
        {
            one_sec_flag = 0x00;
            
            if(dig1 == 0)
            {
                dig1 = 9;
                if(dig2 == 0)
                {
                    dig2 = 9;
                    if(dig3 == 0)
                    {
                        dig3 = 9;
                        if(dig4 == 0)
                        {
                            dig4 = 9;
                        }
                        else
                        {
                            dig4--;
                        }
                    }
                    else
                    {
                        dig3--;
                    }
                }
                else
                {
                    dig2--;
                }
            }
            else
            {
                dig1--;
            }
        }        
        display();        
        for(i = 0; i < 500; i++);
    }
}

void timer_init(void)
{
    LPC_SC->PCONP |= (1 << 1);
    LPC_TIM0->MR0 = 100000000;
    LPC_TIM0->MCR = 0x03;
    LPC_TIM0->TCR = 0x02;
    LPC_TIM0->TCR = 0x01;
    NVIC_EnableIRQ(TIMER0_IRQn);
}

void TIMER0_IRQHandler(void)
{
    LPC_TIM0->IR = 0x01;
    one_sec_flag = 0xFF;
}

void display(void)
{
    if(dig_count == 0x01)
    {
        temp1 = dig1;
        LPC_GPIO1->FIOPIN = D0;
    }
    else if(dig_count == 0x02)
    {
        temp1 = dig2;
        LPC_GPIO1->FIOPIN = D1;
    }
    else if(dig_count == 0x03)
    {
        temp1 = dig3;
        LPC_GPIO1->FIOPIN = D2;
    }
    else if(dig_count == 0x04)
    {
        temp1 = dig4;
        LPC_GPIO1->FIOPIN = D3;
    }    
    temp1 &= 0x0F;
    temp2 = array_dec[temp1];
    temp2 = temp2 << 4;    
    LPC_GPIO0->FIOPIN = temp2;    
    for(i = 0; i < 500; i++);    
    LPC_GPIO0->FIOCLR = 0x00000FF0;
}
