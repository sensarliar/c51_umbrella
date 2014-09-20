#include <STC12C5A.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char

sbit DAT=P2^6;
sbit CLK=P5^1;
sbit LE=P2^1;

//sbit DAT=P3^0;
//sbit CLK=P3^1;
//sbit LE=P3^2;

/******************************发送一字节数据*************************************
*	   
**********************************************************************************/
void sendbyte(uchar a)
{
	uchar c;
	LE=0;
	//delay(1);
	for(c=0;c<8;c++)
	{
		a=_crol_(a,1);
		CLK=0;
		DAT=a&0x01;
		CLK=1;
	}				    
	LE=1;
	//delay(1);
	LE=0;
}

