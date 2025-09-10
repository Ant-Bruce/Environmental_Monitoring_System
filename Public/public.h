#ifndef __PUBLIC_H_
#define __PUBLIC_H_
/**********************************
包含头文件
**********************************/
#include<reg51.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif


/**********************************
函数声明
**********************************/
void Delay1000ms(); 			//延时1s
void Delay_us(uchar n);		//微秒级延迟
void Delay_ms(uint z);		//毫秒级延迟
void Delay_beep(uint i);	//beep延时函数

#endif