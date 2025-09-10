#ifndef __UART_H_
#define __UART_H_

#include "reg51.h"
#include "public.h"

/**********************************
函数声明
**********************************/
void Uart_init(uchar baud);		//串口初始化函数
void Send_uart(uchar value);	//串口发送一个字节数据
void Send_str(uchar *puf);		//串口发送字符串

#endif