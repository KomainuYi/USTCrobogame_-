/**
 * @file encoder.c
 * @author gjc
 * @brief 
 * @version 0.1
 * @date 2022-07-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Includes ------------------------------------------------------------------*/
#include "encoder.h"
/* Private macros ------------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

ENCODE_TypeDef g_encode[4];
Motor_TypeDef g_motor_data[4];
extern volatile int g_timx_encode_count[4] ; //记录溢出次数
/* Private variables ---------------------------------------------------------*/

/* Private function declarat ions ---------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/**
 * @brief 编码器计数
 * @note  
 * 
 * @param 
 * @return 
 */

int32_t lf_gtim_get_encode(void)
{
	return(int32_t)(__HAL_TIM_GET_COUNTER(&htim2)+g_timx_encode_count[0] * 65536);
}

int32_t rf_gtim_get_encode(void)
{
	return(int32_t)(__HAL_TIM_GET_COUNTER(&htim3)+g_timx_encode_count[1] * 65536);
}

int32_t lb_gtim_get_encode(void)
{
	return(int32_t)(__HAL_TIM_GET_COUNTER(&htim4)+g_timx_encode_count[2] * 65536);
}

int32_t rb_gtim_get_encode(void)
{
	return(int32_t)(__HAL_TIM_GET_COUNTER(&htim5)+g_timx_encode_count[3] * 65536);
}

/**
 * @brief 编码器置零函数
 * @note  
 * 
 * @param 
 * @return 
 */

void lf_encode_zero(void)
{
	g_timx_encode_count[0] = 0;
}

/**
 * @brief       电机速度计算
 * @param       encode_now：当前编码器总的计数值
 *              ms：计算速度的间隔，中断1ms进入一次，这里50即50ms计算一次速度
 * @retval      无
 */
uint16_t line_number[4] = {13,13,13,13};
void speed_computer(int32_t encode_now, uint8_t ms,uint8_t wheel_number)
{
    uint8_t i = 0, j = 0;
    float temp = 0.0;
    static uint8_t sp_count[4] ={0}, k[4] = {0};
    static float speed_arr[4][10] = {0.0};                     /* 存储速度进行滤波运算 */

    if (sp_count[wheel_number] == ms)                                     /* 50ms计算一次速度 */
    {
        /* 计算电机转速 
           第一步：计算50ms计数变化量
           第二步 ；计算1min内计数变化量：g_encode.speed * ((1000 / 50) * 60 ，
           第三步 ：除以编码器旋转一圈的计数次数（倍频倍数 * 编码器分辨率）
           第四步 ：除以减速比即可得出电机转速
        */
        g_encode[wheel_number].encode_now = encode_now;                                /* 取出编码器当前计数值 */
        g_encode[wheel_number].speed = (g_encode[wheel_number].encode_now - g_encode[wheel_number].encode_old);    /* 计算编码器计数值的变化量 */
        
        speed_arr[wheel_number][k[wheel_number]++] = (float)(g_encode[wheel_number].speed * ((1000 / ms) * 60.0) / 4/line_number[wheel_number] / 51 );    /* 保存电机转速 */
        
        g_encode[wheel_number].encode_old = g_encode[wheel_number].encode_now;          /* 保存当前编码器的值 */

        /* 累计10次速度值，后续进行滤波*/
        if (k[wheel_number] == 10)
        {
            for (i = 10; i >= 1; i--)                       /* 冒泡排序*/
            {
                for (j = 0; j < (i - 1); j++) 
                {
                    if (speed_arr[wheel_number][j] > speed_arr[wheel_number][j + 1])    /* 数值比较 */
                    { 
                        temp = speed_arr[wheel_number][j];                /* 数值换位 */
                        speed_arr[wheel_number][j] = speed_arr[wheel_number][j + 1];
                        speed_arr[wheel_number][j + 1] = temp;
                    }
                }
            }
            
            temp = 0.0;
            
            for (i = 2; i < 8; i++)                         /* 去除两边高低数据 */
            {
                temp += speed_arr[wheel_number][i];                       /* 将中间数值累加 */
            }
            
            temp = (float)(temp / 6);                       /*求速度平均值*/
            
            /* 一阶低通滤波
             * 公式为：Y(n)= qX(n) + (1-q)Y(n-1)
             * 其中X(n)为本次采样值；Y(n-1)为上次滤波输出值；Y(n)为本次滤波输出值，q为滤波系数
             * q值越小则上一次输出对本次输出影响越大，整体曲线越平稳，但是对于速度变化的响应也会越慢
             */
            g_motor_data[wheel_number].speed = (float)( ((float)1 * temp) );
            k[wheel_number] = 0;
        }
        sp_count[wheel_number] = 0;
    }
    sp_count[wheel_number] ++;
}
/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
