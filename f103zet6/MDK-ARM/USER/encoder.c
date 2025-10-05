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
extern volatile int g_timx_encode_count[4] ; //��¼�������
/* Private variables ---------------------------------------------------------*/

/* Private function declarat ions ---------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/**
 * @brief ����������
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
 * @brief ���������㺯��
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
 * @brief       ����ٶȼ���
 * @param       encode_now����ǰ�������ܵļ���ֵ
 *              ms�������ٶȵļ�����ж�1ms����һ�Σ�����50��50ms����һ���ٶ�
 * @retval      ��
 */
uint16_t line_number[4] = {13,13,13,13};
void speed_computer(int32_t encode_now, uint8_t ms,uint8_t wheel_number)
{
    uint8_t i = 0, j = 0;
    float temp = 0.0;
    static uint8_t sp_count[4] ={0}, k[4] = {0};
    static float speed_arr[4][10] = {0.0};                     /* �洢�ٶȽ����˲����� */

    if (sp_count[wheel_number] == ms)                                     /* 50ms����һ���ٶ� */
    {
        /* ������ת�� 
           ��һ��������50ms�����仯��
           �ڶ��� ������1min�ڼ����仯����g_encode.speed * ((1000 / 50) * 60 ��
           ������ �����Ա�������תһȦ�ļ�����������Ƶ���� * �������ֱ��ʣ�
           ���Ĳ� �����Լ��ٱȼ��ɵó����ת��
        */
        g_encode[wheel_number].encode_now = encode_now;                                /* ȡ����������ǰ����ֵ */
        g_encode[wheel_number].speed = (g_encode[wheel_number].encode_now - g_encode[wheel_number].encode_old);    /* �������������ֵ�ı仯�� */
        
        speed_arr[wheel_number][k[wheel_number]++] = (float)(g_encode[wheel_number].speed * ((1000 / ms) * 60.0) / 4/line_number[wheel_number] / 51 );    /* ������ת�� */
        
        g_encode[wheel_number].encode_old = g_encode[wheel_number].encode_now;          /* ���浱ǰ��������ֵ */

        /* �ۼ�10���ٶ�ֵ�����������˲�*/
        if (k[wheel_number] == 10)
        {
            for (i = 10; i >= 1; i--)                       /* ð������*/
            {
                for (j = 0; j < (i - 1); j++) 
                {
                    if (speed_arr[wheel_number][j] > speed_arr[wheel_number][j + 1])    /* ��ֵ�Ƚ� */
                    { 
                        temp = speed_arr[wheel_number][j];                /* ��ֵ��λ */
                        speed_arr[wheel_number][j] = speed_arr[wheel_number][j + 1];
                        speed_arr[wheel_number][j + 1] = temp;
                    }
                }
            }
            
            temp = 0.0;
            
            for (i = 2; i < 8; i++)                         /* ȥ�����߸ߵ����� */
            {
                temp += speed_arr[wheel_number][i];                       /* ���м���ֵ�ۼ� */
            }
            
            temp = (float)(temp / 6);                       /*���ٶ�ƽ��ֵ*/
            
            /* һ�׵�ͨ�˲�
             * ��ʽΪ��Y(n)= qX(n) + (1-q)Y(n-1)
             * ����X(n)Ϊ���β���ֵ��Y(n-1)Ϊ�ϴ��˲����ֵ��Y(n)Ϊ�����˲����ֵ��qΪ�˲�ϵ��
             * qֵԽС����һ������Ա������Ӱ��Խ����������Խƽ�ȣ����Ƕ����ٶȱ仯����ӦҲ��Խ��
             */
            g_motor_data[wheel_number].speed = (float)( ((float)1 * temp) );
            k[wheel_number] = 0;
        }
        sp_count[wheel_number] = 0;
    }
    sp_count[wheel_number] ++;
}
/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
