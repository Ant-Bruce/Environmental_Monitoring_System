#include "mq2.h"
uchar yanwu_dat[16];   	//用于显示烟雾浓度的接收数据数组
/*******************************************************************************
* 函 数 名       : GetMQ2Value
* 函数功能		 : 获取MQ2数据
* 输    入       : 无
* 输    出    	 : value:MQ2数据
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
* 函 数 名     : MQ2Data
* 函数功能		 : MQ2数据处理
* 输    入     : value:MQ2数据
* 输    出     : 无
*******************************************************************************/
void MQ2Data(uint value)
{
			//LCD将要显示的数据
			yanwu_dat[0]='S'; 
			yanwu_dat[1]='m';
			yanwu_dat[2]='o';
			yanwu_dat[3]=':';
//			yanwu_dat[4]=value/1000+'0';//千位
//			yanwu_dat[5]=value%1000/100+'0';//百位
//			yanwu_dat[6]=value%1000%100/10+'0';//十位
//			yanwu_dat[7]=value%1000%100%10+'0';	//个位
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