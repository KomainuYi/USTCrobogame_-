//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其他用途
//技术资料唯一网站：http://www.weilaishijiejiqiren.icoc.me/
//单片机交流群：439190573
//淘宝店：https://shop130205202.taobao.com
//修改日期：2018/10/31
//版本：V3.0
//版权所有，盗版必究。
//未来世界机器人系列
//////////////////////////////////////////////////////////////////////////////////
#include "sensor.h"


//bool digtal(int channel)//1-8	  获取X通道数字值
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


bool digtal(int channel) // 1-8 获取X通道数字值
{
    bool value = 0;
    GPIO_PinState pinState;
    uint16_t pin;
    
    // 通道到引脚的映射
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
        default: return 0; // 无效通道返回0
    }
    
    // 多次采样去抖动
    int highCount = 0;
    const int samples = 5; // 采样次数
    
    for(int i = 0; i < samples; i++) {
        pinState = HAL_GPIO_ReadPin(GPIOF, pin);
        if(pinState == GPIO_PIN_SET) {
            highCount++;
        }
        // 短暂延时，避免连续读取
        HAL_Delay(1);
    }
    
    // 多数表决：超过80%的采样为高则判定为高电平
    value = (highCount * 100 / samples) > 90;
    
    return value;
		
		
}


