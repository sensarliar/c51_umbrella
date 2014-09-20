#include <STC12C5A.h>
#include<intrins.h>
#include<math.h>
#include<string.h>

#define uchar unsigned char	
#define uint unsigned int
#define ulong unsigned long


sbit DS=P2^7;           	                //定义温度DS18B20接口
sbit heating_1=P1^3;
sbit heating_2=P1^7;
sbit heating_3=P2^5;
sbit heating_4=P4^6;


uchar code COM_1[]={0x02,0x00,0x00,0x02,0xE5,0xBA,0xB2,0x28};
uchar code COM_2[]={0x35,0x00,0x00,0x02,0xE5,0x9B,0xA1,0x28};
uchar code COM_3[]={0xFF,0x00,0x00,0x02,0xE5,0xBF,0x67,0x28};
uchar code COM_4[]={0x1B,0x00,0x00,0x02,0xE5,0xE4,0xE2,0x28};

/******************************延时函数*******************************************
*	   
**********************************************************************************/
void delay(uint z)
{
	uint x,y;
	for(x=2000;x>1;x--)
	{
		for(y=z;y>1;y--);
	}
}

/******************************微延时函数*****************************************
*	   
**********************************************************************************/
void tmp_delay(uint z)
{
	while(z--);
}



/******************************DS18B20芯片****************************************
*	        初始化
*         读一个字节
*         写一个字节
**********************************************************************************/
void DS_init()                           //初始化DS18B20
{
	DS=1;                                  //DS复位
	tmp_delay(10);                         //稍做延时
	DS=0;                                  //单片机将DS拉低
	delay(1);                              //精确延时 大于 480us
	DS=1;                                  //拉高总线
	tmp_delay(20);
}

uchar read_DS()
{
	uchar i=0;
	uchar dat=0;
	for(i=8;i>0;i--)
	{
		DS=0;                                 //给脉冲信号
		dat>>=1;
		DS=1;                                 //给脉冲信号
		if(DS)
		dat|=0x80;
		tmp_delay(4);
	}
	return(dat);                            //返回值高位在左，低位在右
}

void write_DS(uchar dat)                  //由右至左写入一字节
{
	uchar i=0;
	for(i=8; i>0; i--)
	{
		DS=0;
		DS=dat&0x01;
		tmp_delay(5);
		DS=1;
		dat>>=1;
	}
}

void th_tl(uchar serial[])    //设置高低温限
{
	uchar i;
	DS_init();
	write_DS(0x55);             //发出 MATCH ROM 命令
	for(i=0;i<8;i++)
	{
		write_DS(serial[7-i]);    //发出DS18B20的 COM 序列
	}
	write_DS(0x4E);             //写入高低温告警温度
	write_DS(0x7D);                   //高温 125℃
	write_DS(0x14);                   //低温 20 ℃
}

void alarm_search()
{
	uchar i=1,j,c;
	uchar tag_old,tag_new,sensor_count;
	bit scan_over,b;
	uchar serial[8];
	xdata uchar snn[4][8]={0x00};
	
	sensor_count=0;
	scan_over=0;
	tag_old=0;
	for(;scan_over==0;)
	{
		i=1;
		tag_new=0;                      //scan_start
		
		DS_init();
		delay(1);		
		write_DS(0xEC);                    //发出 ALARM SEARCH 命令
		do
		{
			c=0;
			DS=0;                                 //读1bit
			_nop_();_nop_();
			DS=1;
			if(DS) c|=0x02;
			tmp_delay(6);
			DS=0;                                 //读1bit补码
			_nop_();_nop_();
			DS=1;
			if(DS) c|=0x01;
			tmp_delay(6);	
			
			switch (c)
			{
				case 0x00:                //此位冲突
					if(i<tag_old)           //未到达标TAG_OLD,向TAG_OLD走,如果是向左则标记新的TAG_NEW
					{
						if (!((serial[(i-1)>>3]>>((i-1)%8))&0x01)) {b=0;tag_new=i;} else b=1;
					}
					if(i==tag_old) b=1;  //到达TAG_OLD,固定"1"
					if(i>tag_old)        //超过TAG_OLD,先选择"0",标记新的TAG_NEW 
					{
						b=0;
						tag_new=i;
					}
					break;
				case 0x01:                //此位为0 
					b=0;
					break;
				case 0x02:                //此位为1
					b=1;
					break;
				case 0x03:                //无传感器
					scan_over=1;
					i=64;
					break;
				default: break;
			}
			
			DS=0;
			_nop_();_nop_();
			DS=b&0x01;
			tmp_delay(6);
			DS=1;
			
			serial[(i-1)>>3]=serial[(i-1)>>3] >> 1;
			if (b) serial[(i-1)>>3] |= 0x80;
				else serial[(i-1)>>3] &= 0x7F;
			i++;
		}
		while(i<=64);	
		
		tag_old=tag_new;
		if(sensor_count<=3)
			for(j=0;j<8;j++) snn[sensor_count][7-j]=serial[j];      //reord sensor addr
		sensor_count++;
		if(tag_new==0) scan_over=1;
	}
  
	sensor_count=0;
	P3|=0xF0;
	if(!(strcmp(snn[0],COM_1)&&strcmp(snn[1],COM_1)&&strcmp(snn[2],COM_1)&&strcmp(snn[3],COM_1)))
		P3&=0xEF;
	if(!(strcmp(snn[0],COM_2)&&strcmp(snn[1],COM_2)&&strcmp(snn[2],COM_2)&&strcmp(snn[3],COM_2)))
		P3&=0xDF;
	if(!(strcmp(snn[0],COM_3)&&strcmp(snn[1],COM_3)&&strcmp(snn[2],COM_3)&&strcmp(snn[3],COM_3)))
		P3&=0xBF;
	if(!(strcmp(snn[0],COM_4)&&strcmp(snn[1],COM_4)&&strcmp(snn[2],COM_4)&&strcmp(snn[3],COM_4)))
		P3&=0x7F;			
	sensor_count++;
}

/******************************读取并显示温度函数*********************************
*	   读取并显示DS18B20的温度值
*	   入口参数：DS18B20序列号、温度显示地址
**********************************************************************************/
void get_temp(uchar serial[])
{
	uchar i;
	uchar t1=0;
	uchar t2=0;
	uint t=0;
	float tt=0;	
	uint shi,ge,xiaoshu;

	DS_init();
	write_DS(0x55);             //发出 MATCH ROM 命令
	for(i=0;i<8;i++)
	{
		write_DS(serial[7-i]);    //发出DS18B20的 COM 序列
	}
	write_DS(0x44);           //发出温度变换命令
	delay(1);
	
	DS_init();
	write_DS(0x55);           //发出 MATCH ROM 命令
	for(i=0;i<8;i++)
	{
		write_DS(serial[7-i]);    //发出DS18B20的 COM 序列
	}
	write_DS(0xBE);           //读取温度寄存器
	t1=read_DS();              //连续读两个字节数据   //读低8位 
	t2=read_DS();                                     //读高8位
	if(t2<0xF0)               //正温度
	{
		t=t2;
		t<<=8;
		t=t|t1; 			        //两字节合成一个整型变量。
		tt=t*0.0625;  	    //得到真实十进制温度值，因为DS18B20可以精确到0.0625度，所以读回数据的最低位代表的是0.0625度
		t=tt*10+0.5; 	      //放大十倍，这样做的目的将小数点后第一位也转换为可显示数字，同时进行一个四舍五入操作。
		shi=t/100;
		ge=t/10%10;
		xiaoshu=t%10;
	
	}
	else                    //负温度
	{
		t=t2;
		t<<=8;
		t=t|t1; 			        //两字节合成一个整型变量。
		t=0xFFFF-t+1;         //得到温度的绝对值
		tt=t*0.0625;  	    //得到真实十进制温度值，因为DS18B20可以精确到0.0625度，所以读回数据的最低位代表的是0.0625度
		t=tt*10+0.5; 	      //放大十倍，这样做的目的将小数点后第一位也转换为可显示数字，同时进行一个四舍五入操作。
		shi=t/100;
		ge=t/10%10;
		xiaoshu=t%10;
	
	}
}