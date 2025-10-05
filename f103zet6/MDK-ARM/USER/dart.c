
#include "dart.h"

void launch(int speed)   //use step motor & frc wheel to launch
{        //
	        	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);//正转
	     
					
					//left&right frction wheel speed 100max 50zero
				 __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,speed);  //lb
	       __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,speed);  //lf
	       __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,speed);  //rf
				 __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,speed);  //rb
	     	//stepmotor PWM
	       HAL_Delay(3000);
		     __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,250);
		     HAL_Delay(1600);
				//shutdown frction wheel&stepmotor
				
	
		     HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);//反转归位
				 HAL_Delay(1600);
				 __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);//停止
	
	       __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
	       __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,0);
	       __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,0); 
				 __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,0);
}

void catchdart(int num)
{

	//$DGT:0-10,1! 调用动作 G0000~G0010 组 1 次， 若为0 次则代表循环执行前提是动作已存储
	  if(num==0)
		{			
			uint8_t action_cmd[] ="{G0001#000P1700T1500!#001P2167T1500!#002P2500T1500!#003P2000T1500!#004P1500T1500!#005P1500T1500!}";
       HAL_UART_Transmit(&huart4, action_cmd, sizeof(action_cmd), 1000); 
	   
		}
		if(num==1)
		{
			uint8_t action_cmd[] = "$DGT:2-11,1!"; // 动作组1调用指令
			HAL_UART_Transmit(&huart4, action_cmd, sizeof(action_cmd), 1000); 
			 HAL_Delay(17000);
			
		}
		if(num==2)    
		{
			uint8_t action_cmd[] = "$DGT:13-22,1!"; // 动作组1调用指令
			HAL_UART_Transmit(&huart4, action_cmd, sizeof(action_cmd), 1000); 
			 HAL_Delay(17000);
		}
		if(num==3)
		{
			uint8_t action_cmd[] = "$DGT:23-32,1!"; // 动作组1调用指令
			HAL_UART_Transmit(&huart4, action_cmd, sizeof(action_cmd), 1000); 
			 HAL_Delay(17000);
		}
		if(num==4)
		{
			uint8_t action_cmd[] = "$DGT:33-42,1!"; // 动作组1调用指令
			HAL_UART_Transmit(&huart4, action_cmd, sizeof(action_cmd), 1000); 
			 HAL_Delay(17000);
		}
		if(num==5)
		{
			uint8_t action_cmd[] = "$DGT:43-55,1!"; // 动作组1调用指令
			HAL_UART_Transmit(&huart4, action_cmd, sizeof(action_cmd), 1000); 
			 HAL_Delay(17000);
		}
		if(num==6)
		{
			uint8_t action_cmd[] = "$DGT:56-68,1!"; // 动作组1调用指令
			HAL_UART_Transmit(&huart4, action_cmd, sizeof(action_cmd), 1000); 
			 HAL_Delay(17000);
		}
  
	
}

