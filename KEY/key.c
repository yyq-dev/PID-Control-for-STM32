#include "stm32f10x.h"
#include "Delay.h"

void KEY_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitTypeDef GPIO_InitStr;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStr.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStr.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
    GPIO_Init(GPIOA,&GPIO_InitStr);
}

uint8_t Key_GetNum(void)
{
    uint8_t KeyNum = 0;
    if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10) == 0)
    {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10) == 0)
        Delay_ms(20);
        KeyNum = 1;
    }

    if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0)
        {
            Delay_ms(20);
            while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0)
            Delay_ms(20);
            KeyNum = 2;
        }

    if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1)
        {
            Delay_ms(20);
            while (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
            Delay_ms(20);
            KeyNum = 3;
        }

    return KeyNum;
}
