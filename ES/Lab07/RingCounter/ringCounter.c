#include <LPC17xx.h>

unsigned int i;
unsigned long LED = 0x00000010;  //Initial LED pattern at P0.4
#define SW2_PIN (1 << 12)        //P2.12 for switch

int main(void)
{
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;  //P0.4-P0.11 as GPIO
    LPC_GPIO0->FIODIR |= 0x00000FF0;    //LEDs as output

    LPC_PINCON->PINSEL4 &= ~(0x3 << 24); //P2.12 as GPIO
    LPC_GPIO2->FIODIR &= ~SW2_PIN;       //SW2 as input
    LPC_PINCON->PINMODE4 |= (0x3 << 24); //Pull-down for SW2

    LPC_GPIO0->FIOCLR = 0x00000FF0;      //Clear all LEDs initially
    LPC_GPIO0->FIOSET = LED;             //Set first LED

    while(1)
    {
        if(LPC_GPIO2->FIOPIN & SW2_PIN)  //If switch pressed
        {
            for(i=0; i<200000; i++);     //Debounce delay

            LPC_GPIO0->FIOCLR = 0x00000FF0;
            LED <<= 1;                    //Shift LED pattern left

            if(LED > 0x00000800)         //If beyond P0.11
                LED = 0x00000010;        //Reset to P0.4

            LPC_GPIO0->FIOSET = LED;     //Display new LED pattern
            
            while(LPC_GPIO2->FIOPIN & SW2_PIN); //Wait for key release
        }
    }
}