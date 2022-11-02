//hamitcandinc c2000 led blink code

#include<F28x_Project.h>

#define LED4 23
#define LED5 34

void gpio_setup(void);

int main(void)
{
    InitSysCtrl();
    InitGpio();
    gpio_setup();

    GPIO_WritePin(LED4,0);
    GPIO_WritePin(LED5,0);
    DELAY_US(10000);

    for(;;)
    {
        GPIO_WritePin(LED4,1);
        DELAY_US(50000);
        GPIO_WritePin(LED4,0);
        GPIO_WritePin(LED5,1);
        DELAY_US(50000);
        GPIO_WritePin(LED5,0);
    }
}


void gpio_setup(void)
{
    GPIO_SetupPinMux(LED4,GPIO_MUX_CPU1,0);
    GPIO_SetupPinOptions(LED4,GPIO_OUTPUT,GPIO_PUSHPULL);

    GPIO_SetupPinMux(LED5,GPIO_MUX_CPU1,0);
    GPIO_SetupPinOptions(LED5,GPIO_OUTPUT,GPIO_PUSHPULL);
}
