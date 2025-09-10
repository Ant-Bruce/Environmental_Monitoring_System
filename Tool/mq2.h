#ifndef __MQ2_H_
#define __MQ2_H_

/**********************************
包含头文件
**********************************/
#include "public.h"
#include "reg51.h"
#include "xpt2046.h"

extern uchar yanwu_dat[16];   	//用于显示烟雾浓度的接收数据数组

/**********************************
函数声明
**********************************/
/*获取MQ2数据函数*/
uint GetMQ2Value(void);
/*MQ2数据处理函数*/
void MQ2Data(uint value);				  

#endif

