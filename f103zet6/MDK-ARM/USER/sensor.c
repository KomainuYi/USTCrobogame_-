//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ���������������;
//��������Ψһ��վ��http://www.weilaishijiejiqiren.icoc.me/
//��Ƭ������Ⱥ��439190573
//�Ա��꣺https://shop130205202.taobao.com
//�޸����ڣ�2018/10/31
//�汾��V3.0
//��Ȩ���У�����ؾ���
//δ�����������ϵ��
//////////////////////////////////////////////////////////////////////////////////
#include "sensor.h"


//bool digtal(int channel)//1-8	  ��ȡXͨ������ֵ
//{
//	bool value = 0;
//	switch(channel) 
//	{
//		case 1:  
//			if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_0)==GPIO_PIN_SET) value = 1;
//			else value = 0;  
//			break;  
//		case 2: 
//			if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_1)==GPIO_PIN_SET) value = 1;
//			else value = 0;  
//			break;  
//		case 3: 
//			if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_2)==GPIO_PIN_SET) value = 1;
//			else value = 0;  
//			break;   
//		case 4:  
//			if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_3)==GPIO_PIN_SET) value = 1;
//			else value = 0;  
//			break;   
//		case 5:
//			if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_4)==GPIO_PIN_SET) value = 1;
//			else value = 0;  
//			break;
//		case 6:  
//			if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_5)==GPIO_PIN_SET) value = 1;
//			else value = 0;  
//			break;  
//		case 7: 
//			if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_6)==GPIO_PIN_SET) value = 1;
//			else value = 0;  
//			break;  
// 		case 8: 
// 			if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_7)==GPIO_PIN_SET) value = 1;
// 			else value = 0;  
// 			break;   
//	}
//	return value; 
//}


bool digtal(int channel) // 1-8 ��ȡXͨ������ֵ
{
    bool value = 0;
    GPIO_PinState pinState;
    uint16_t pin;
    
    // ͨ�������ŵ�ӳ��
    switch(channel) 
    {
        case 1: pin = GPIO_PIN_0; break;
        case 2: pin = GPIO_PIN_1; break;
        case 3: pin = GPIO_PIN_2; break;
        case 4: pin = GPIO_PIN_3; break;
        case 5: pin = GPIO_PIN_4; break;
        case 6: pin = GPIO_PIN_5; break;
        case 7: pin = GPIO_PIN_6; break;
        case 8: pin = GPIO_PIN_7; break;
        default: return 0; // ��Чͨ������0
    }
    
    // ��β���ȥ����
    int highCount = 0;
    const int samples = 5; // ��������
    
    for(int i = 0; i < samples; i++) {
        pinState = HAL_GPIO_ReadPin(GPIOF, pin);
        if(pinState == GPIO_PIN_SET) {
            highCount++;
        }
        // ������ʱ������������ȡ
        HAL_Delay(1);
    }
    
    // �������������80%�Ĳ���Ϊ�����ж�Ϊ�ߵ�ƽ
    value = (highCount * 100 / samples) > 90;
    
    return value;
		
		
}


