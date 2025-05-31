#include <LPC17xx.h>

unsigned char col, row, flag, key;
unsigned long int temp, var1, temp3, i;
unsigned int pwm_values[4] = {3000, 7500, 15000, 22500};

void pwm_init(void);
void scan(void);
void read_keyboard(void);
void set_led_intensity(unsigned char key_pressed);

int main(void)
{
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF;
    LPC_PINCON->PINSEL4 &= 0xF00FFFFF;
    LPC_GPIO2->FIODIR |= 0x00003C00;
    LPC_GPIO1->FIODIR &= 0xF87FFFFF;    
    pwm_init();    
    while(1)
    {
        read_keyboard();
        for(i=0; i<1000; i++);
    }
}

void pwm_init(void)
{
    LPC_SC->PCONP |= (1<<6);
    LPC_PINCON->PINSEL3 &= ~(0x0000C000);
    LPC_PINCON->PINSEL3 |= 0x00008000;
    LPC_PWM1->PCR = 0x00001000;
    LPC_PWM1->MCR = 0x00000002;
    LPC_PWM1->MR0 = 30000;
    LPC_PWM1->MR4 = 0x00000100;
    LPC_PWM1->LER = 0x000000FF;
    LPC_PWM1->TCR = 0x00000002;
    LPC_PWM1->TCR = 0x00000009;
}

void read_keyboard(void)
{
    var1 = 0x00000400;
    LPC_GPIO2->FIOCLR = 0x00003C00;
    LPC_GPIO2->FIOSET = var1;    
    flag = 0;
    scan();   
    if(flag == 1)
    {
        key = col;
        set_led_intensity(key);
        for(i=0; i<100000; i++);
    }
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

void set_led_intensity(unsigned char key_pressed)
{
    if(key_pressed <= 3)
    {
        LPC_PWM1->MR4 = pwm_values[key_pressed];
        LPC_PWM1->LER = 0x000000FF;
    }
}
