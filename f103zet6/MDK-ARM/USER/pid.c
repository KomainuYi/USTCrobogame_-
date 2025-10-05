/**
 * @file pid.c
 * @author gjc
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Includes ------------------------------------------------------------------*/
#include "pid.h"
/* Private macros ------------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
PIDController g_speed_pid[4];
/* Private function declarations ---------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/


/*                 PID 算法                  */

/*****0*****1*****
       *****
	   *****
	   *****
	  2*****3******/
/**
 * @brief       pid初始化
 * @param       无
 * @retval      无
 */
// 初始化PID控制器 具体参数待测
void lf_PID_Init(PIDController *pid) {
    pid->kp = 1.00f;
    pid->ki = 0.20f;
    pid->kd = 0.00f;
    pid->integral = 0;
    pid->prev_error = 0;
}

void lb_PID_Init(PIDController *pid) {
    pid->kp = 1.00f;
    pid->ki = 0.20f;
    pid->kd = 0.00f;
    pid->integral = 0;
    pid->prev_error = 0;
}

void rf_PID_Init(PIDController *pid) {
    pid->kp = 1.00f;
    pid->ki = 0.20f;
    pid->kd = 0.00f;
    pid->integral = 0;
    pid->prev_error = 0;
}

void rb_PID_Init(PIDController *pid) {
    pid->kp = 1.00f;
    pid->ki = 0.20f;
    pid->kd = 0.00f;
    pid->integral = 0;
    pid->prev_error = 0;
}


// 更新PID控制器
float PID_Update(PIDController* pid, float setpoint, float actual, float dt) {
    float error = setpoint - actual;
    
    // 比例项
    float proportional = pid->kp * error;
    
    // 积分项
    pid->integral += error * dt;
    float integral = pid->ki * pid->integral;
    
    // 微分项
    float derivative = pid->kd * (error - pid->prev_error) / dt;
    pid->prev_error = error;
    
    // 计算控制输出
    return proportional + integral + derivative;
}

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
