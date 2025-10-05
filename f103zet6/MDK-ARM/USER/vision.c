//////////////////////////////////////////////////////////////////////////////////	 

//////////////////////////////////////////////////////////////////////////////////
#include "vision.h"
uint8_t visionmessage[2]={0,0};

void vision_target()
{
       HAL_UART_Receive(&huart5,visionmessage,1,1000);
			  if(visionmessage[0]=='1')
				{
					motor(-20,20);
					HAL_Delay(200);
        }
				if(visionmessage[0]=='2')
				{
					motor(20,-20);
					HAL_Delay(200);
        }
				if(visionmessage[0]=='3')
				{
					motor(0,0);
					HAL_Delay(20000);
        }
				
				



}