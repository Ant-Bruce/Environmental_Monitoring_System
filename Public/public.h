#ifndef __PUBLIC_H_
#define __PUBLIC_H_
/**********************************
����ͷ�ļ�
**********************************/
#include<reg51.h>

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif


/**********************************
��������
**********************************/
void Delay1000ms(); 			//��ʱ1s
void Delay_us(uchar n);		//΢�뼶�ӳ�
void Delay_ms(uint z);		//���뼶�ӳ�
void Delay_beep(uint i);	//beep��ʱ����

#endif