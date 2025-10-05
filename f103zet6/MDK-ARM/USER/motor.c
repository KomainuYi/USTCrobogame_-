/**
 * @file motor.c
 * @author ustc_ghy_24@mail.ustc.edu.cn
 * @brief ����������-ֱ���������
 * @version 0.0
 * @date 2025-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Includes ------------------------------------------------------------------*/

#include "motor.h"

/* Private macros ------------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function declarations ---------------------------------------------*/


/**
 * @brief �޷�����
 * 
 * @tparam Type 
 * @param x ��������
 * @param Min ��Сֵ
 * @param Max ���ֵ
 */


//PA10��B,PA9 ��A���Ƶ��lf����PD15����PWM�����ٶ�
//PA12��B,PA11��A���Ƶ��lb����PD14����PWM�����ٶ�
//PC2 ��B,PC3 ��A���Ƶ��rf����PD13����PWM�����ٶ�
//PC0 ��B,PC1 ��A���Ƶ��rb����PD12����PWM�����ٶ�
//32767->max speed


//-----------------------------------------------------
void lf_motor_pwm_set(int num)
{
    if(num==0)//ֹͣ
		{
      HAL_GPIO_WritePin(LF_B_GPIO_Port,LF_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LF_A_GPIO_Port,LF_A_Pin, GPIO_PIN_RESET);
		}
		else if(num > 0)//��ת
		{
			HAL_GPIO_WritePin(LF_B_GPIO_Port,LF_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LF_A_GPIO_Port,LF_A_Pin, GPIO_PIN_RESET);
		}
		else if(num < 0)//��ת
		{
			HAL_GPIO_WritePin(LF_B_GPIO_Port,LF_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LF_A_GPIO_Port,LF_A_Pin, GPIO_PIN_SET);
		}
		__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,(num>0)?num:-num);
			
}
//-----------------------------------------------------
void lb_motor_pwm_set(int num)
{
    if(num==0)//ֹͣ
		{
			HAL_GPIO_WritePin(LB_B_GPIO_Port,LB_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LB_A_GPIO_Port,LB_A_Pin, GPIO_PIN_RESET);
		}
		
		else if(num > 0)//��ת
		{
		 	HAL_GPIO_WritePin(LB_B_GPIO_Port,LB_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LB_A_GPIO_Port,LB_A_Pin, GPIO_PIN_RESET);
		}
		else if(num < 0)//��ת
		{
			HAL_GPIO_WritePin(LB_B_GPIO_Port,LB_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LB_A_GPIO_Port,LB_A_Pin, GPIO_PIN_SET);
		}
		__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,(num>0)?num:-num);		
}
//-----------------------------------------------------
void rf_motor_pwm_set(int num)
{
    if(num==0)//ֹͣ
		{
			HAL_GPIO_WritePin(RF_B_GPIO_Port,RF_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(RF_A_GPIO_Port,RF_A_Pin, GPIO_PIN_RESET);
		}
		else if(num > 0)//��ת
		{
			HAL_GPIO_WritePin(RF_B_GPIO_Port,RF_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(RF_A_GPIO_Port,RF_A_Pin, GPIO_PIN_RESET);
		}
		else if(num < 0)//��ת
		{
			HAL_GPIO_WritePin(RF_B_GPIO_Port,RF_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(RF_A_GPIO_Port,RF_A_Pin, GPIO_PIN_SET);
		}
		__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,(num>0)?num:-num);		
}

//-----------------------------------------------------
void rb_motor_pwm_set(int num)
{
    if(num==0)//ֹͣ
		{
			HAL_GPIO_WritePin(RB_B_GPIO_Port,RB_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(RB_A_GPIO_Port,RB_A_Pin, GPIO_PIN_RESET);
		}
		else if(num > 0)//��ת
		{
			HAL_GPIO_WritePin(RB_B_GPIO_Port,RB_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(RB_A_GPIO_Port,RB_A_Pin, GPIO_PIN_RESET);
		}
		else if(num < 0)//��ת
		{
			HAL_GPIO_WritePin(RB_B_GPIO_Port,RB_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(RB_A_GPIO_Port,RB_A_Pin, GPIO_PIN_SET);
		}
		__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,(num>0)?num:-num);		
}







//��������ֵ����ʱ������


//PB6 PE0����lf��������ֵ��PE0Ϊexit��
//PB7 PE1����lb��������ֵ��PE1Ϊexit��
//PB8 PE2����rf��������ֵ��PE2Ϊexit��
//PB9 PE3����rb��������ֵ��PE3Ϊexit��
int Motor_Counter_lf(int counter)
{
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==GPIO_PIN_RESET)
	{
	  counter++;
	}
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==GPIO_PIN_SET)
	{
	  counter--;
	}
	return(counter);
}

int Motor_Counter_lb(int counter)
{
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7)==GPIO_PIN_RESET)
	{
	  counter++;
	}
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7)==GPIO_PIN_SET)
	{
	  counter--;
	}
	return(counter);
}

int Motor_Counter_rf(int counter)
{
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_8)==GPIO_PIN_RESET)
	{
	  counter--; //only this is oppiste
	}
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_8)==GPIO_PIN_SET)
	{
	  counter++;
	}
	return(counter);
}


int Motor_Counter_rb(int counter)
{
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_9)==GPIO_PIN_RESET)
	{
	  counter--;
	}
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_9)==GPIO_PIN_SET)
	{
	  counter++;
	}
	return(counter);
}


void pid_pwm_set(int lf,int lb,int rf,int rb)
{

	lf_PID_Init(&g_speed_pid[0]);
	lb_PID_Init(&g_speed_pid[1]);
	rf_PID_Init(&g_speed_pid[2]);
	rb_PID_Init(&g_speed_pid[3]);
	   target_speed[0]=lf;
	   target_speed[1]=lb;
	   target_speed[2]=rf;
	   target_speed[3]=rb;
}


void motor(int left,int right)
{
	 pid_pwm_set(left*32767/100,left*32767/100,right*32767/100,right*32767/100);
	
}

void lefttranslation(int speed)
{
	   pid_pwm_set(-speed*32767/100,speed*32767/100,speed*32767/100,-speed*32767/100);
}


void stop()
{
	k=0;
	pid_pwm_set(0,0,0,0);
	
}
