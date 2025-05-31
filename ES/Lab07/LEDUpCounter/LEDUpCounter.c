#include <LPC17xx.h>

unsigned int count = 0;
unsigned int i;

int main(void)
{
    LPC_PINCON->PINSEL0 &= 0xFF0000FF; //Configure P0.4-P0.11 as GPIO
    LPC_GPIO0->FIODIR |= 0x00000FF0;   //Set as outputs
    while(1)
    {
        LPC_GPIO0->FIOCLR = 0x00000FF0;     
        LPC_GPIO0->FIOSET = (count << 4);            
        //for(i=0; i<500000; i++);   //Delay        
        count++;
        if(count > 255)   //Reset counter after 255
            count = 0;
    }
}