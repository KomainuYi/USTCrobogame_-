/**
 * @file motor.h
 * @author ustc_ghy_24@mail.ustc.edu.cn
 * @brief ����������-ֱ���������
 * @version 0.1
 * @date 2025-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _MOTOR_H
#define _MOTOR_H

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "pid.h"
/* Exported macros -----------------------------------------------------------*/



/* Exported types ------------------------------------------------------------*/


typedef struct 
{
          /*���״̬*/
  float speed;            /*���ʵ���ٶ�*/
  int32_t motor_pwm;      /*���ñȽ�ֵ��С */
  float location;		  /*���λ��*/
} Motor_TypeDef;


/* Exported variables --------------------------------------------------------*/

/* Exported function declarations --------------------------------------------*/

int Motor_Counter_lf(int counter);
int Motor_Counter_lb(int counter);
int Motor_Counter_rf(int counter);
int Motor_Counter_rb(int counter);

void pid_pwm_set(int a,int b,int c,int d);

void lf_motor_pwm_set(int num);
void rf_motor_pwm_set(int num);
void lb_motor_pwm_set(int num);
void rb_motor_pwm_set(int num);

void motor(int left,int right);
void lefttranslation(int speed);
void stop(void);
#endif

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
