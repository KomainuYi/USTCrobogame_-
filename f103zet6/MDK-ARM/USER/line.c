//////////////////////////////////////////////////////////////////////////////////	 

#define XXX 20
#define XXM 15
#define XX 10
#define XM 5
#define X 4
#define M 3
#define LOW 2
#define ZERO 0
#include "Line.h"



/*************************************
*函数名称：track_zhixian1()
*函数功能：直线循迹
*参数：
*说明：
*			
**************************************/
unsigned char result = 0;
int crosscount=0,state=0;   //1下面左上角，3上面右上角,2
uint8_t track_receiveData[1];
int track_temp;
int launchspeed[5]={1123,1125,1129,1132,1134};           //{1122,1124,1128,1132,1134};   //
int angle[5]={30,0,0,20,15};                           //{25,0,0,30,15};                     
int dartposition[3]={2,3,4};

void track_zhixian1()
{
	 
     result = 0;
    // 将每个布尔值设置到相应的位
    if(D1) result |= 0x80; // 设置第7位 (1000 0000)
    if(D2) result |= 0x40; // 设置第6位 (0100 0000)
    if(D3) result |= 0x20; // 设置第5位 (0010 0000)
    if(D4) result |= 0x10; // 设置第4位 (0001 0000)
    if(D5) result |= 0x08; // 设置第3位 (0000 1000)
    if(D6) result |= 0x04; // 设置第2位 (0000 0100)
    if(D7) result |= 0x02; // 设置第1位 (0000 0010)
    if(D8) result |= 0x01; // 设置第0位 (0000 0001)
	
	
	
	switch(result)
	{                                         //8765 4321
		case 0xFE:		motor(0,40);	break;      //1111 1110
		case 0xFC:		motor(10,40);	break;      //1111 1100
		case 0xFD:		motor(15,40);	break;      //1111 1101
		case 0xF9:		motor(20,40);	break;      //1111 1001
		case 0xFB:		motor(25,40);	break;      //1111 1011
		case 0xF3:		motor(25,40);	break;      //1111 0011
		case 0xF7:		motor(38,40);	break;      //1111 0111
		case 0xE7:		motor(40,40);	break;      //1110 0111		//正中间位置
		case 0xEF:		motor(40,38);	break;      //1110 1111			
		case 0xCF:		motor(40,25);	break;      //1100 1111
		case 0xDF:		motor(40,25);	break;      //1101 1111
		case 0x9F:		motor(40,20);	break;      //1001 1111
		case 0xBF:		motor(40,15);	break;      //1011 1111
		case 0x3F:		motor(40,10);	break;      //0011 1111
		case 0x7F:		motor(40,0);	break;      //0111 1111
		
		default :			motor(20,20);	break;

}



}

void track_turnright(int forward,int right,int delay)
{
	           motor(20,20);  
						 HAL_Delay(forward);  //about 700
	            pid_pwm_set(10000,10000,-10000,-10000);
//						 lf_motor_pwm_set(10000);
//		         lb_motor_pwm_set(10000);
//		 
//		         rf_motor_pwm_set(-10000);
//             rb_motor_pwm_set(-10000);
		         HAL_Delay(right);  //about 1800
	            motor(0,0);
	             HAL_Delay(delay);  //about 500
	          
}

void track_turnleft(int forward,int right,int delay)
{
	           motor(20,20);
						 HAL_Delay(forward);
	 pid_pwm_set(-10000,-10000,10000,10000);
//						 lf_motor_pwm_set(-10000);
//		         lb_motor_pwm_set(-10000);
//		 
//		         rf_motor_pwm_set(10000);
//             rb_motor_pwm_set(10000);
		         HAL_Delay(right);
	            motor(0,0);
	             HAL_Delay(delay);
	
}	

void track_straightline()
{
	if((D4 == 0)&&(D5 == 0))    
	{
		motor(XXX,XXX);
	}
	else if((D4 == 0)&&(D5 != 0))   
	{
		motor(XXM,XXX);
	}
	else if((D4 != 0)&&(D5 == 0))   
	{
		motor(XXX,XXM);
	}
	else if((D3 == 0)&&(D4 == 0))   
	{
		motor(XX,XXX);
	}
	else if((D5 == 0)&&(D6 == 0))   
	{
		motor(XXX,XX);
	}
	else if((D3 == 0)&&(D4 != 0))    
	{
		motor(XM,XXX);
	}
	else if((D5 != 0)&&(D6 == 0))   
	{
		motor(XXX,XM);
	}
	else if((D2 == 0)&&(D3 == 0))   
	{
		motor(X,XXX);
	}
	else if((D6 == 0)&&(D7 == 0))   
	{
		motor(XXX,X);
	}
	else if((D2 == 0)&&(D3 != 0))    
	{
		motor(M,XXX);
	}
	else if((D6 != 0)&&(D7 == 0))  
	{
		motor(XXX,M);
	}
	else if((D1 == 0)&&(D2 == 0))   
	{
		motor(LOW,XXX);
	}
	else if((D7 == 0)&&(D8 == 0))   
	{
		motor(XXX,LOW);
	}
	else if((D1 == 0)&&(D2 != 0))    
	{
		motor(0,XXX);
	}	
	else if((D7 !=0)&&(D8 == 0))   
	{
		motor(XXX,0);
	}
	else   
	{
		motor(XXX,XXX);
	}
}


void statezero()
{
	   track_straightline();
		
	    if(crosscount==0&&D4==0&&D3==0&&D2==0&&D1==0)  //第一个L型路口
	   {
		 crosscount=1;
		 track_turnleft(700,1800,500);
	   }
		 
	    if(crosscount==1&&D4==0&&D3==0&&D2==0&&D1==0)  //第二个L型路口
	  {
		crosscount++;
		motor(20,20);
		HAL_Delay(800);
				pid_pwm_set(10000,10000,-10000,-10000);
		HAL_Delay(800);
			motor(0,0);
		HAL_Delay(500);
	  }
	if(crosscount==2&&D4!=0&&D5!=0&&D3!=0&&D6!=0  )  //Y路口
	{
		crosscount++;
		
	
			pid_pwm_set(-10000,-10000,10000,10000);
//		lf_motor_pwm_set(-10000);
//		lb_motor_pwm_set(-10000);
//		 
//		rf_motor_pwm_set(10000);
//    rb_motor_pwm_set(10000);
		HAL_Delay(600);
	}
	
	   if(crosscount==3&&D4==0&&D5==0&&D7==0&&D2==0)   //飞镖区的十字路口
	  {
		  crosscount=4;
		  motor(20,20);
	  	HAL_Delay(1000);
			pid_pwm_set(10000,10000,-10000,-10000);
//		  lf_motor_pwm_set(10000);
//		  lb_motor_pwm_set(10000);
//		 
//		  rf_motor_pwm_set(-10000);
//      rb_motor_pwm_set(-10000);
		  HAL_Delay(1600);
			
			
  	}
	
	   if(crosscount==4&&D4==0&&D3==0&&D2==0)  //飞镖区的L型路口
	 {
		  
		
		  lefttranslation(20);
		 
		  
		  HAL_Delay(2800);
		 
		  motor(20,20);
	  	HAL_Delay(2400);
		  state=1;
		  crosscount=0;
		  
		 time=currentime;
		
	 }
	 
     
}

void stateone()
{
	 
	    
	   
	    motor(-20,-20);
	
	   if(currentime-time==1000)
		 {
			     lefttranslation(10);
					 HAL_Delay(200);
		 }
	    
		 if(D3==0&&D4==0&&D5==0&&D6==0)
		 {
				 crosscount++;
			 
			 
			 
			 if(crosscount==1||crosscount==3)
			 {
				 motor(20,20);
				 HAL_Delay(100);
			 }
			 
//			  if(crosscount==1)
//				{
//					motor(-20,-20);
//					HAL_Delay(0);
//				}
//				if(crosscount==4)
//				{
//					motor(20,20);
//					HAL_Delay(20);
//				}
			 
			 
			 motor(0,0);
			  
			  
				if(crosscount==dartposition[0]||crosscount==dartposition[1]||crosscount==dartposition[2])
		      catchdart(1);
			 
			  motor(10,-10);              //右转d(theta)以瞄准
			  HAL_Delay(2*angle[crosscount-1]);
			 motor(0,0);
			 
			 	if(crosscount==dartposition[0]||crosscount==dartposition[1]||crosscount==dartposition[2])
		   launch(launchspeed[crosscount-1]);
			 
			 
			 
	   HAL_Delay(2000);
			 
				 if(crosscount!=5)
				 {
					
					  motor(-20,-20);
		      HAL_Delay(500);
					 lefttranslation(5);
					 HAL_Delay(400);
				 }
				 else
				 {
					 
					  lefttranslation(5);
					  HAL_Delay(400);
					motor(20,20);
				
		       HAL_Delay(6000);
             crosscount=0;
					   state=2;
				 } 
			 
			
		 }	

     
}

void statetwo()
{     
	      if(crosscount==0)     
			{ 
			   lefttranslation(-20);
         HAL_Delay(2000);
	  	   motor(20,20);
		     HAL_Delay(300);
			
	         if(D1==0&&D2==0&&D3!=0&&D4!=0&&D5!=0)
			     { 
			      
				     motor(30,30);
				     HAL_Delay(3000);
						 crosscount=1;
						
				
			     }
		  }
			 if(crosscount==1)  
	    { 
		      motor(30,30);
		   if(D2==0&&D4==0&&D5==0&&D7==0)
		   {
				 
				 track_turnright(700,1800,500);
				 motor(20,20);
				 HAL_Delay(8000);
				 
				 crosscount=0;
				 state=3;
				 
			 }
	    }
					 
						
					
			
}




void track_zhixian2()
{
	
	if(state==0)  //移动到左上角
	{
		open();
	  //statezero();
  }
	if(state==1) //遍历5根线
		 stateone();
		 
	if(state==2) //移动到上面
	   statetwo();
	
	
	
	
}



	  
	
 
 
void open()
{
	motor(40,40);
	HAL_Delay(3000);
	lefttranslation(40);
	HAL_Delay(10000);
	motor(20,20);
	HAL_Delay(6000);
	state=1;
	time=currentime;
}

void track_zhixian3()
{
	  if(state==0)
		statezero_1();
		
		 if(state==1)
		stateone_1();
		 
		 if(state==2)
		statetwo_1();
		
	
}


void 	statezero_1()
{
	   lefttranslation(40);
	  HAL_Delay(3800);
	  
	  motor(40,40);
	  HAL_Delay(4500);
	  
	  
	  motor(20,20);
	  HAL_Delay(1500);
	  
	 
	
	  state=1;
}


void stateone_1()
{
	   if(crosscount==0)     
			{ 
			   lefttranslation(20);
         

			
	         if(D1==0&&D2==0&&D3!=0&&D4!=0&&D5!=0&&D6!=0)
			     { 
			       motor(0,0);
						 HAL_Delay(3000);
				     motor(30,30);
				     HAL_Delay(3000);
						 crosscount=1;
						
				
			     }
		  }
			 if(crosscount==1)  
	    { 
		      motor(30,30);
		   if(D2==0&&D4==0&&D5==0&&D7==0)
		   {
				 
				 track_turnright(700,1800,500);
				 motor(20,20);
				 HAL_Delay(10000);
				 
				 crosscount=0;
				 state=2;
				 
			 }
	    }
	
	
}

	     
void statetwo_1()
{
	 
	
	 
		      motor(-20,-20);
	
	   if(currentime-time==1000)
		 {
			     lefttranslation(20);
					 HAL_Delay(100);
		 }
	    
		 if(D3==0&&D4==0&&D5==0&&D6==0)
		 {
				     crosscount++;
			 
			      
			 
			 
			      motor(0,0);
			 
				   //if(crosscount==dartposition[0]||crosscount==dartposition[1]||crosscount==dartposition[2])
		     catchdart(2);
			 
         
			       
			 
			 	//if(crosscount==dartposition[0]||crosscount==dartposition[1]||crosscount==dartposition[2])
		   launch(2000);
			 
			 
			 
	         HAL_Delay(2000);
			 
				
			 
		 }	
 
		  
	 
	  
}					 
	      
	      
	