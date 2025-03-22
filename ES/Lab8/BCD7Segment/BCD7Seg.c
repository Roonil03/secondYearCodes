#include <LPC17xx.h>

#define DIGIT_MASK (0xF << 23)   //P1.23-P1.26 for digit select
#define SEG_MASK (0xFF << 4)     //P0.4-P0.11 for segments
#define SW_PIN (1 << 12)         //P2.12 for switch

unsigned int digits[4] = {0,0,0,0};
unsigned int current_digit = 0;
unsigned char up_count = 1;

const unsigned char seven_seg[10] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void TIMER1_IRQHandler(void)
{
    if(up_count)
    {
        digits[0]++;
        if(digits[0] > 9) {
            digits[0] = 0;
            digits[1]++;
            if(digits[1] > 9) {
                digits[1] = 0;
                digits[2]++;
                if(digits[2] > 9) {
                    digits[2] = 0;
                    digits[3]++;
                    if(digits[3] > 9)
                        digits[3] = 0;
                }
            }
        }
    }
    else
    {
        if(digits[0] == 0) {
            digits[0] = 9;
            if(digits[1] == 0) {
                digits[1] = 9;
                if(digits[2] == 0) {
                    digits[2] = 9;
                    if(digits[3] == 0)
                        digits[3] = 9;
                    else
                        digits[3]--;
                }
                else
                    digits[2]--;
            }
            else
                digits[1]--;
        }
        else
            digits[0]--;
    }    
    LPC_TIM1->IR = 1;
}

int main(void)
{
    LPC_PINCON->PINSEL0 &= ~(0xFF << 8);    //P0.4-P0.11 as GPIO
    LPC_GPIO0->FIODIR |= SEG_MASK;          //Segments as output
    LPC_PINCON->PINSEL3 &= ~(0xFF << 14);   //P1.23-P1.26 as GPIO
    LPC_GPIO1->FIODIR |= DIGIT_MASK;        //Digit select as output
    LPC_PINCON->PINSEL4 &= ~(0x3 << 24);    //P2.12 as GPIO
    LPC_GPIO2->FIODIR &= ~SW_PIN;           //Switch as input
    LPC_TIM1->PR = 0;                       //No prescaler
    LPC_TIM1->MR0 = 25000000;              //1 second delay
    LPC_TIM1->MCR = 3;                      //Interrupt and reset on match
    LPC_TIM1->TCR = 1;                      //Start timer
    while(1)
    {
        up_count = (LPC_GPIO2->FIOPIN & SW_PIN) ? 1 : 0;
        LPC_GPIO1->FIOCLR = DIGIT_MASK;
        LPC_GPIO1->FIOSET = (1 << (23 + current_digit));
        LPC_GPIO0->FIOCLR = SEG_MASK;
        LPC_GPIO0->FIOSET = (seven_seg[digits[current_digit]] << 4);
        current_digit = (current_digit + 1) % 4;
    }
}