#include <STC12C5A.h>
#include<intrins.h>
#include<math.h>
#include<string.h>

#define uchar unsigned char	
#define uint unsigned int
#define ulong unsigned long


sbit DS=P2^7;           	                //�����¶�DS18B20�ӿ�
sbit heating_1=P1^3;
sbit heating_2=P1^7;
sbit heating_3=P2^5;
sbit heating_4=P4^6;


uchar code COM_1[]={0x02,0x00,0x00,0x02,0xE5,0xBA,0xB2,0x28};
uchar code COM_2[]={0x35,0x00,0x00,0x02,0xE5,0x9B,0xA1,0x28};
uchar code COM_3[]={0xFF,0x00,0x00,0x02,0xE5,0xBF,0x67,0x28};
uchar code COM_4[]={0x1B,0x00,0x00,0x02,0xE5,0xE4,0xE2,0x28};

/******************************��ʱ����*******************************************
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

/******************************΢��ʱ����*****************************************
*	   
**********************************************************************************/
void tmp_delay(uint z)
{
	while(z--);
}



/******************************DS18B20оƬ****************************************
*	        ��ʼ��
*         ��һ���ֽ�
*         дһ���ֽ�
**********************************************************************************/
void DS_init()                           //��ʼ��DS18B20
{
	DS=1;                                  //DS��λ
	tmp_delay(10);                         //������ʱ
	DS=0;                                  //��Ƭ����DS����
	delay(1);                              //��ȷ��ʱ ���� 480us
	DS=1;                                  //��������
	tmp_delay(20);
}

uchar read_DS()
{
	uchar i=0;
	uchar dat=0;
	for(i=8;i>0;i--)
	{
		DS=0;                                 //�������ź�
		dat>>=1;
		DS=1;                                 //�������ź�
		if(DS)
		dat|=0x80;
		tmp_delay(4);
	}
	return(dat);                            //����ֵ��λ���󣬵�λ����
}

void write_DS(uchar dat)                  //��������д��һ�ֽ�
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

void th_tl(uchar serial[])    //���øߵ�����
{
	uchar i;
	DS_init();
	write_DS(0x55);             //���� MATCH ROM ����
	for(i=0;i<8;i++)
	{
		write_DS(serial[7-i]);    //����DS18B20�� COM ����
	}
	write_DS(0x4E);             //д��ߵ��¸澯�¶�
	write_DS(0x7D);                   //���� 125��
	write_DS(0x14);                   //���� 20 ��
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
		write_DS(0xEC);                    //���� ALARM SEARCH ����
		do
		{
			c=0;
			DS=0;                                 //��1bit
			_nop_();_nop_();
			DS=1;
			if(DS) c|=0x02;
			tmp_delay(6);
			DS=0;                                 //��1bit����
			_nop_();_nop_();
			DS=1;
			if(DS) c|=0x01;
			tmp_delay(6);	
			
			switch (c)
			{
				case 0x00:                //��λ��ͻ
					if(i<tag_old)           //δ�����TAG_OLD,��TAG_OLD��,��������������µ�TAG_NEW
					{
						if (!((serial[(i-1)>>3]>>((i-1)%8))&0x01)) {b=0;tag_new=i;} else b=1;
					}
					if(i==tag_old) b=1;  //����TAG_OLD,�̶�"1"
					if(i>tag_old)        //����TAG_OLD,��ѡ��"0",����µ�TAG_NEW 
					{
						b=0;
						tag_new=i;
					}
					break;
				case 0x01:                //��λΪ0 
					b=0;
					break;
				case 0x02:                //��λΪ1
					b=1;
					break;
				case 0x03:                //�޴�����
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

/******************************��ȡ����ʾ�¶Ⱥ���*********************************
*	   ��ȡ����ʾDS18B20���¶�ֵ
*	   ��ڲ�����DS18B20���кš��¶���ʾ��ַ
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
	write_DS(0x55);             //���� MATCH ROM ����
	for(i=0;i<8;i++)
	{
		write_DS(serial[7-i]);    //����DS18B20�� COM ����
	}
	write_DS(0x44);           //�����¶ȱ任����
	delay(1);
	
	DS_init();
	write_DS(0x55);           //���� MATCH ROM ����
	for(i=0;i<8;i++)
	{
		write_DS(serial[7-i]);    //����DS18B20�� COM ����
	}
	write_DS(0xBE);           //��ȡ�¶ȼĴ���
	t1=read_DS();              //�����������ֽ�����   //����8λ 
	t2=read_DS();                                     //����8λ
	if(t2<0xF0)               //���¶�
	{
		t=t2;
		t<<=8;
		t=t|t1; 			        //���ֽںϳ�һ�����ͱ�����
		tt=t*0.0625;  	    //�õ���ʵʮ�����¶�ֵ����ΪDS18B20���Ծ�ȷ��0.0625�ȣ����Զ������ݵ����λ�������0.0625��
		t=tt*10+0.5; 	      //�Ŵ�ʮ������������Ŀ�Ľ�С������һλҲת��Ϊ����ʾ���֣�ͬʱ����һ���������������
		shi=t/100;
		ge=t/10%10;
		xiaoshu=t%10;
	
	}
	else                    //���¶�
	{
		t=t2;
		t<<=8;
		t=t|t1; 			        //���ֽںϳ�һ�����ͱ�����
		t=0xFFFF-t+1;         //�õ��¶ȵľ���ֵ
		tt=t*0.0625;  	    //�õ���ʵʮ�����¶�ֵ����ΪDS18B20���Ծ�ȷ��0.0625�ȣ����Զ������ݵ����λ�������0.0625��
		t=tt*10+0.5; 	      //�Ŵ�ʮ������������Ŀ�Ľ�С������һλҲת��Ϊ����ʾ���֣�ͬʱ����һ���������������
		shi=t/100;
		ge=t/10%10;
		xiaoshu=t%10;
	
	}
}