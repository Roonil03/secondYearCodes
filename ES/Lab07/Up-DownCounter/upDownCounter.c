#include <LPC17xx.h>

unsigned char count = 0;
unsigned int i;
#define SW2_PIN (1 << 12)   //P2.12 for switch

int main(void)
{
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;  //P0.4-P0.11 as GPIO
    LPC_GPIO0->FIODIR |= 0x00000FF0;    //LEDs as output
    LPC_PINCON->PINSEL4 &= ~(0x3 << 24); //P2.12 as GPIO
    LPC_GPIO2->FIODIR &= ~SW2_PIN;       //SW2 as input
    while(1)
    {
        LPC_GPIO0->FIOCLR = 0x00000FF0;
        LPC_GPIO0->FIOSET = (count << 4);
        for(i=0; i<200000; i++);
        if(LPC_GPIO2->FIOPIN & SW2_PIN)
        {
            count++;            //Up counter
        }
        else
        {      //Down counter
                count--;
        }
    }
}