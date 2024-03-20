#include "stm32f10x.h"                  //Device header
#include "delay.h"
#include "OLED.h"
#include "pwm.h"
#include "timer.h"
#include "pid.h"
#include "motor.h"
#include "encoder.h"

int SpeedNow = 0;

int SpeedSet = 300;

int main(void)
{
	NVIC_PriorityGroupConfig(2); //=====设置中断分组
	Encoder_Init_TIM3();            //=====初始化编码器1接口
	
	Motor_Init(7199,0);             //=====初始化PWM 10KHZ，用于驱动电机 如需初始化驱动器接口
	
	TIM2_Int_Init(50-1,7200-1);     //=====定时器初始化 5ms一次中断

	PID_Init();						//=====PID参数初始化
	
	//闭环速度控制
	while(1)
	{
		//给速度设定值，想修改速度，就更该SpeeSet变量的值
		pid_Task.speedSet  = SpeedSet;
		
		//给定速度实时值
		pid_Task.speedNow  = SpeedNow;
		
		//执行PID控制函数
		Pid_Ctrl(&motor);
		
		//根据PID计算的PWM数据进行设置PWM
		Set_Pwm(motor);
		

	} 
}

//5ms 定时器中断服务函数 --> 计算速度实时值
void TIM2_IRQHandler(void)                            //TIM2中断
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);   //清除TIMx的中断待处理位
		
		Get_Motor_Speed(&SpeedNow);					  //计算电机速度
		
	}
}

