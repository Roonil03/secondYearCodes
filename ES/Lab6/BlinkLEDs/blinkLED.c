#include <LPC17xx.h>

void delay_ms(unsigned int ms);

int main(void) 
{
    SystemInit();
    
    LPC_PINCON->PINSEL0 &= ~(0x3 << 8);
    LPC_GPIO0->FIODIR = (1 << 4);
    
    while(1) 
    {
        LPC_GPIO0->FIOSET = 1<<4;
        //delay_ms(500);
        
        LPC_GPIO0->FIOCLR = 1<<4;
        //delay_ms(500);
    }
}

void delay_ms(unsigned int ms) 
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 12000; j++);
}