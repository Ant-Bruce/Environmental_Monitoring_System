#ifndef __MQ2_H_
#define __MQ2_H_

/**********************************
����ͷ�ļ�
**********************************/
#include "public.h"
#include "reg51.h"
#include "xpt2046.h"

extern uchar yanwu_dat[16];   	//������ʾ����Ũ�ȵĽ�����������

/**********************************
��������
**********************************/
/*��ȡMQ2���ݺ���*/
uint GetMQ2Value(void);
/*MQ2���ݴ�����*/
void MQ2Data(uint value);				  

#endif

