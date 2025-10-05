/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
#include "Line.h"
#include "dart.h"
#include "pid.h"
#include <string.h>
#include "vision.h"
#include "sensor.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int counter[4]={0,0,0,0};
int timecounter=0,k=0;
int  precounter[4],target_speed[4];
float speed[4];
uint8_t receiveData[1];
int currentime=0,time=0;

float temp[4],temp2[4];
int temp3[10];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void frictionwheelinit()
{
	 //left&right frction wheel init
					HAL_Delay(2000);
					 __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,2000); 
					 __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,2000);
	         __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,2000); 
					 __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,2000);
		      HAL_Delay(2000);
		      __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1000);  
		      __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,1000);
	        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,1000); 
		      __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,1000);
		      HAL_Delay(2000);
	
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_UART4_Init();
  MX_UART5_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
	
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
	
	HAL_TIM_Base_Start_IT(&htim3);
	
	lf_PID_Init(&g_speed_pid[0]);
	lb_PID_Init(&g_speed_pid[1]);
	rf_PID_Init(&g_speed_pid[2]);
	rb_PID_Init(&g_speed_pid[3]);
  frictionwheelinit();

	

launch(2000);
  
//time=currentime;
 

	     
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		
  
		
//		temp3[0]=D1;
//		temp3[1]=D2;
//		temp3[2]=D2;
//		temp3[3]=D3;
//		temp3[4]=D4;
//		temp3[5]=D5;
//		temp3[6]=D6;
//		temp3[7]=D7;
//		temp3[8]=D8;
		
	
	//track_zhixian2();
		//vision_target();
		


		
	


	
		
  
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) //1ms 100%对应的速度为6
{
	 					 
   if(htim==&htim3)
	 {
		 currentime++;
		 timecounter++;
		 
		      
		     if(timecounter>=40)
				 {
					 timecounter=0;
					
					 for(int i=0;i<=3;i++) 
					 {
					 speed[i]=-(float)(counter[i]-precounter[i])/561.0f/0.04f;     //1rad=561pulse  speed:rad/s
					 precounter[i]=counter[i];  
           temp[i]=PID_Update(&g_speed_pid[i],(float)(target_speed[i]*6.00f/32767.00),speed[i],0.04);
					 temp2[i]=(float)(target_speed[i]*6.00f/32767);
					 }
					 
					 
					 
					   
					 lf_motor_pwm_set(target_speed[0]); 
					 lb_motor_pwm_set(target_speed[1]);  
					 rf_motor_pwm_set(target_speed[2]);
		    	 rb_motor_pwm_set(target_speed[3]);
					 
				 }
		
		 
		 
	 }
		    
		 
	 
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
