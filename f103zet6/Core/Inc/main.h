/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
#include "pid.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern int counter[4];
extern int target_speed[4];
extern int k;
extern int currentime;
extern int time;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RB_B_Pin GPIO_PIN_0
#define RB_B_GPIO_Port GPIOC
#define RB_A_Pin GPIO_PIN_1
#define RB_A_GPIO_Port GPIOC
#define RF_B_Pin GPIO_PIN_2
#define RF_B_GPIO_Port GPIOC
#define RF_A_Pin GPIO_PIN_3
#define RF_A_GPIO_Port GPIOC
#define LF_A_Pin GPIO_PIN_9
#define LF_A_GPIO_Port GPIOA
#define LF_B_Pin GPIO_PIN_10
#define LF_B_GPIO_Port GPIOA
#define LB_A_Pin GPIO_PIN_11
#define LB_A_GPIO_Port GPIOA
#define LB_B_Pin GPIO_PIN_12
#define LB_B_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
