/**
 * @file .h
 * @author ustc_ghy_24@mail.ustc.edu.cn
 * @brief encoder
 * @version 0.1
 * @date 2022-07-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef  _ENCODER_H_
#define  _ENCODER_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"
#include "tim.h"
#include "motor.h"
/* Exported macros -----------------------------------------------------------*/
/* �����������ṹ�� */
typedef struct 
{
  int encode_old;                  /* ��һ�μ���ֵ */
  int encode_now;                  /* ��ǰ����ֵ */
  float speed;                     /* �������ٶ� */
} ENCODE_TypeDef;

/* Exported types ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported function declarations --------------------------------------------*/
int32_t lf_gtim_get_encode(void);
int32_t rf_gtim_get_encode(void);
int32_t lb_gtim_get_encode(void);
int32_t rb_gtim_get_encode(void);
void speed_computer(int32_t encode_now, uint8_t ms,uint8_t wheel_number);
#endif  

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
