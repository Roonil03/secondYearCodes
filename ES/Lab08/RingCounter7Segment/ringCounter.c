#include <LPC17xx.h>

#define D0   0xF87FFFFF
#define D1   0xF8FFFFFF
#define D2   0xF97FFFFF
#define D3   0xF9FFFFFF
#define OFF  0xFA7FFFFF

unsigned char ring_patterns[4] = {0x06, 0x5B, 0x4F, 0x66};
unsigned char binary_segments[4] = {0x060, 0x5B0, 0x4F0, 0x660};

unsigned int dig1 = 0, dig2 = 0, dig3 = 0, dig4 = 0;
unsigned int dig_count = 0x01;
unsigned int ring_delay_count = 0;
unsigned int temp1 = 0x00;
unsigned long int temp2 = 0x00000000;
unsigned long int i = 0;
unsigned char ring_advance_flag = 0x00;

void delay(void);
void display(void);
void advance_ring_counter(void);

int main(void)
{    
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF;    
    LPC_GPIO0->FIODIR |= 0x00000FF0;
    LPC_GPIO1->FIODIR |= 0x07800000;    
    dig1 = 0;
    dig2 = 1;
    dig3 = 2;
    dig4 = 3;    
    while(1)
    {
        delay();
        
        dig_count++;
        if(dig_count == 0x05)
        {
            dig_count = 0x01;
        }
        
        if(ring_advance_flag == 0xFF)
        {
            ring_advance_flag = 0x00;
            advance_ring_counter();
        }
        
        display();
    }
}

void advance_ring_counter(void)
{
    dig1++;
    if(dig1 >= 4) dig1 = 0;
    
    dig2++;
    if(dig2 >= 4) dig2 = 0;
    
    dig3++;
    if(dig3 >= 4) dig3 = 0;
    
    dig4++;
    if(dig4 >= 4) dig4 = 0;
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
    temp1 &= 0x03;
    temp2 = binary_segments[temp1];
    temp2 = temp2 << 4;    
    LPC_GPIO0->FIOPIN = temp2;    
    for(i = 0; i < 500; i++);    
    LPC_GPIO0->FIOCLR = 0x00000FF0;
}

void delay(void)
{
    unsigned int i;    
    for(i = 0; i < 1000; i++);    
    ring_delay_count++;    
    if(ring_delay_count >= 500)
    {
        ring_advance_flag = 0xFF;
        ring_delay_count = 0x00;
    }
}
