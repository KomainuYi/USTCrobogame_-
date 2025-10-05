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


/*                 PID �㷨                  */

/*****0*****1*****
       *****
	   *****
	   *****
	  2*****3******/
/**
 * @brief       pid��ʼ��
 * @param       ��
 * @retval      ��
 */
// ��ʼ��PID������ �����������
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


// ����PID������
float PID_Update(PIDController* pid, float setpoint, float actual, float dt) {
    float error = setpoint - actual;
    
    // ������
    float proportional = pid->kp * error;
    
    // ������
    pid->integral += error * dt;
    float integral = pid->ki * pid->integral;
    
    // ΢����
    float derivative = pid->kd * (error - pid->prev_error) / dt;
    pid->prev_error = error;
    
    // ����������
    return proportional + integral + derivative;
}

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
