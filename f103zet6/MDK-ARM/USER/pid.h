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

#ifndef _PID_H
#define _PID_H

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "tim.h"
#include "gpio.h"
/* Exported macros -----------------------------------------------------------*/

// PID�ṹ��
typedef struct {
    float kp;           // ����ϵ��
    float ki;           // ����ϵ��
    float kd;           // ΢��ϵ��
    float integral;     // ������
    float prev_error;   // ��һ�����
    float output;       // ���ֵ
} PIDController;

/* Exported types ------------------------------------------------------------*/

extern PIDController g_speed_pid[4];

/* Exported variables --------------------------------------------------------*/

/* Exported function declarations --------------------------------------------*/

// ��������
void lf_PID_Init(PIDController *pid);
void lb_PID_Init(PIDController *pid);
void rf_PID_Init(PIDController *pid);
void rb_PID_Init(PIDController *pid);
float PID_Update(PIDController* pid, float setpoint, float actual, float dt);


#endif

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
