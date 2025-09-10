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
*��������main
*��  �룺��
*��  ������
*��  �ܣ�������
****************************************************************************/
void main(void)
{
   uchar i,j;   
	 uint value;	//�洢MQ2����
	
	 //LcdInit();   //lcd1602��ʼ��

	 Uart_init(0XFA);	//���ڳ�ʼ��
	 //Delay1000ms();//��espwifiģ���ϵ�ʱ��

   while(1)
   {  
			//DH11
      Delay1000ms();    //DHT11�ϵ��Ҫ�ȴ�1S��Խ�����ȶ�״̬�ڴ��ڼ䲻�ܷ����κ�ָ��
      DHT11_receive();
			LcdInit();   //lcd1602��ʼ��
		 	 
      LcdWriteCom(0x80);   //��lcd1602��һ�е�һ��λ�ÿ�ʼ��ʾ
      for(i=0;i<16;i++)
				LcdWriteData(wen_dat[i]);   //��ʾ���� 
				 
			//MQ2���ݴ���
			value=GetMQ2Value();  //��ȡMQ2����
			value=value/15;
			MQ2Data(value); 			//MQ2���ݸ�ֵ
		 
		  LcdWriteCom(0xc0);   //��lcd1602�ڶ��е�һ��λ�ÿ�ʼ��ʾ
		  for(j=0;j<16;j++)
				LcdWriteData(yanwu_dat[j]);   //��ʾ����
		 
		  Beep_warn(value);		//��������������
	 
			ESP8266dat();		//�洢��Ҫ8266�ϴ���ʪ�ȣ��¶ȣ�����Ũ��
			
			//���ڷ�������
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
