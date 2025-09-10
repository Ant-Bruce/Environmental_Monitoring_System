#include "mq2.h"
uchar yanwu_dat[16];   	//������ʾ����Ũ�ȵĽ�����������
/*******************************************************************************
* �� �� ��       : GetMQ2Value
* ��������		 : ��ȡMQ2����
* ��    ��       : ��
* ��    ��    	 : value:MQ2����
*******************************************************************************/
uint GetMQ2Value(void)
{
	uint value=0;
	uchar j;
	for(j=0;j<50;j++)
	{
		value=value+Read_AD_Data(0xE4);
	}
	return value/50;
}

/*******************************************************************************
* �� �� ��     : MQ2Data
* ��������		 : MQ2���ݴ���
* ��    ��     : value:MQ2����
* ��    ��     : ��
*******************************************************************************/
void MQ2Data(uint value)
{
			//LCD��Ҫ��ʾ������
			yanwu_dat[0]='S'; 
			yanwu_dat[1]='m';
			yanwu_dat[2]='o';
			yanwu_dat[3]=':';
//			yanwu_dat[4]=value/1000+'0';//ǧλ
//			yanwu_dat[5]=value%1000/100+'0';//��λ
//			yanwu_dat[6]=value%1000%100/10+'0';//ʮλ
//			yanwu_dat[7]=value%1000%100%10+'0';	//��λ
			yanwu_dat[4]=value/10+'0';
			yanwu_dat[5]=value%10+'0';
			yanwu_dat[6]='%';
			yanwu_dat[7]=' ';
			yanwu_dat[8]=' ';
			yanwu_dat[9]=' ';
			yanwu_dat[10]='L';
			yanwu_dat[11]='E';
			yanwu_dat[12]='E';
			yanwu_dat[13]=' ';
			yanwu_dat[14]=' ';
			yanwu_dat[15]=' ';
}