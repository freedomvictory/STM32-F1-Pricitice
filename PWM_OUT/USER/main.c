#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 

uint16_t arr = (uint16_t)(899*80*10);

	
 int main(void)
 {		
 	u16 led0pwmval=0;
	u8 dir=1;	
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
 	TIM3_PWM_Init(arr ,0);	 //不分频。PWM频率=72000000/900/80/10=0.1khz
   	while(1)
	{
 										 
		TIM_SetCompare3(TIM3,arr/2);
		delay_ms(1000);
	  TIM_SetCompare3(TIM3,arr/3);	
    delay_ms(1000);		
		
	}	 
 }

