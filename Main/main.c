#include "reg51.h"
#include "intrins.h"
#include "lcd1602.h"
#include "xpt2046.h"
#include "uart.h"
#include "public.h"
#include "dh11.h"
#include "mq2.h"
#include "beep.h"
#include "esp8266.h"

/****************************************************************************
*函数名：main
*输  入：无
*输  出：无
*功  能：主函数
****************************************************************************/
void main(void)
{
   uchar i,j;   
	 uint value;	//存储MQ2数据
	
	 //LcdInit();   //lcd1602初始化

	 Uart_init(0XFA);	//串口初始化
	 //Delay1000ms();//给espwifi模块上电时间

   while(1)
   {  
			//DH11
      Delay1000ms();    //DHT11上电后要等待1S以越过不稳定状态在此期间不能发送任何指令
      DHT11_receive();
			LcdInit();   //lcd1602初始化
		 	 
      LcdWriteCom(0x80);   //从lcd1602第一行第一个位置开始显示
      for(i=0;i<16;i++)
				LcdWriteData(wen_dat[i]);   //显示数据 
				 
			//MQ2数据处理
			value=GetMQ2Value();  //获取MQ2数据
			value=value/15;
			MQ2Data(value); 			//MQ2数据赋值
		 
		  LcdWriteCom(0xc0);   //从lcd1602第二行第一个位置开始显示
		  for(j=0;j<16;j++)
				LcdWriteData(yanwu_dat[j]);   //显示数据
		 
		  Beep_warn(value);		//蜂鸣器报警函数
	 
			ESP8266dat();		//存储需要8266上传的湿度，温度，烟雾浓度
			
			//串口发送数据
			Delay1000ms();
			Send_uart(dat_8266[0]);
			Send_uart(dat_8266[1]);
			Send_str("#");
			Send_uart(dat_8266[3]);
			Send_uart(dat_8266[4]);
			Send_str("#");
			Send_uart(dat_8266[6]);
			Send_uart(dat_8266[7]);
			Delay1000ms();
   }
}
