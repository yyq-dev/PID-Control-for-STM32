#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);

    GPIO_ResetBits(GPIOB,GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);
}

void LED1_ON(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_9);
}

void LED1_OFF(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_9);
}

void LED1_Turn(void)
{
    if (GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_9) == 0)
    {
        GPIO_SetBits(GPIOB,GPIO_Pin_9);
    }
    else
    {
        GPIO_ResetBits(GPIOB,GPIO_Pin_9);
    }
}

void LED2_ON(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_8);
}

void LED2_OFF(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_8);
}

void LED2_Turn(void)
{
    if (GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_8) == 0)
    {
        GPIO_SetBits(GPIOB,GPIO_Pin_8);
    }
    else
    {
        GPIO_ResetBits(GPIOB,GPIO_Pin_8);
    }
}

void LED3_ON(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_7);
}

void LED3_OFF(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_7);
}

void LED3_Turn(void)
{
    if (GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_7) == 0)
    {
        GPIO_SetBits(GPIOB,GPIO_Pin_7);
    }
    else
    {
        GPIO_ResetBits(GPIOB,GPIO_Pin_7);
    }
}