#ifndef __UART_H_
#define __UART_H_

#include "reg51.h"
#include "public.h"

/**********************************
��������
**********************************/
void Uart_init(uchar baud);		//���ڳ�ʼ������
void Send_uart(uchar value);	//���ڷ���һ���ֽ�����
void Send_str(uchar *puf);		//���ڷ����ַ���

#endif