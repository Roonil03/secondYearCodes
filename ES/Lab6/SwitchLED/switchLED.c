#include <LPC17xx.h>

#define LED_PIN (1 << 4)
#define SWITCH_PIN (1 << 12)

int main(void)
{
    LPC_PINCON->PINSEL0 = (0x0 << 8);
    LPC_GPIO0->FIODIR |= LED_PIN;    
    LPC_PINCON->PINSEL4 = (0x0 << 24);
    LPC_GPIO2->FIODIR &= ~SWITCH_PIN;   
    while(1)
    {
        if(!(LPC_GPIO2->FIOPIN & SWITCH_PIN))
        {
            LPC_GPIO0->FIOSET = LED_PIN;
        }
        else
        {
            LPC_GPIO0->FIOCLR = LED_PIN;
        }
    }
}