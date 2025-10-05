/**
 * @file motor.h
 * @author ustc_ghy_24@mail.ustc.edu.cn
 * @brief 霍尔编码器-直流电机控制
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

// PID结构体
typedef struct {
    float kp;           // 比例系数
    float ki;           // 积分系数
    float kd;           // 微分系数
    float integral;     // 积分项
    float prev_error;   // 上一次误差
    float output;       // 输出值
} PIDController;

/* Exported types ------------------------------------------------------------*/

extern PIDController g_speed_pid[4];

/* Exported variables --------------------------------------------------------*/

/* Exported function declarations --------------------------------------------*/

// 函数声明
void lf_PID_Init(PIDController *pid);
void lb_PID_Init(PIDController *pid);
void rf_PID_Init(PIDController *pid);
void rb_PID_Init(PIDController *pid);
float PID_Update(PIDController* pid, float setpoint, float actual, float dt);


#endif

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
