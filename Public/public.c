#include "public.h"
#include "intrins.h"

void Delay1000ms()		//@11.0592MHz
{
	uchar i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay_us(uchar n)//Î¢Ãë¼¶ÑÓ³Ù
{
    while(--n);
}

void Delay_ms(uint z)//ºÁÃë¼¶ÑÓ³Ù
{
   uint i,j;
   for(i=z;i>0;i--)
      for(j=110;j>0;j--);
}

void Delay_beep(uint i)//beepÑÓÊ±º¯Êý
{
	char j;
	for(i; i > 0; i--)
		for(j = 200; j > 0; j--);
}