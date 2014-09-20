#include <STC12C5A.h>
#include <absacc.h>
#include <intrins.h>
#include <math.h>
#include <string.h>


#define uchar unsigned char	
#define uint unsigned int
#define ulong unsigned long

void key_scan(void);
void motor_control(void);

struct date
{
unsigned char hsec;
unsigned char sec;
}timer1a,timer1b,timer2a,timer2b,timer3a,timer3b,timer4a,timer4b;

uchar lcd_dat;


extern 	bit  st_tm4a;
extern 	bit  st_tm4b;
extern 	bit  st_tm3a;
extern 	bit  st_tm3b;
extern 	bit  st_tm2a;
extern 	bit  st_tm2b;
extern 	bit  st_tm1a;
extern 	bit  st_tm1b;

sbit    LED=P1^3;
sbit    LED1=P4^3;
extern  bit  dis_fresh;

void init_timer0()
{
   P4SW=0xff;
   TMOD|=0X01;
   TH0=0x3C;				//���ʱ��Ҫ��ȫ��ȷ������12MHZ�ľ���25ms��ʱ
   TL0=0xB0;
   EA=1;
   ET0=1;
   //TR0=1;
}

void timer0() interrupt 1 using 1
{
   
   unsigned char num,num1;
   CLK_DIV=0X00;
   TH0=0x3C;				//���ʱ��Ҫ��ȫ��ȷ������12MHZ�ľ���,25ms��ʱ
   TL0=0xB0;
   num++;
   num1++;
   lcd_dat++;
   key_scan();             //����ɨ��
   
	  if(num==2)
       {
	     LED=0;
	   }

       if(num==4)       //100ms��ʱ+
       { 
         LED=1;
		 /*
		 st_tm3a=1;
		 st_tm3b=1;
		 st_tm4a=1;
		 st_tm4b=1;
		 st_tm2a=1;
		 st_tm2b=1;
		 st_tm1a=1;
		 st_tm1b=1;
		 */
		  if(st_tm4a)	   //�������3a��ʱ��־Ϊ1����ʱ+0.1s
   		   {  
		   if(++timer4a.sec>=100){timer4a.sec=0;timer4a.hsec++;}
           if(timer4a.hsec>=100){timer4a.hsec=0;}
		   }

		  if(st_tm4b)	    //�������3b��ʱ��־Ϊ1����ʱ+0.1s
   		   {  
		   if(++timer4b.sec>=100){timer4b.sec=0;timer4b.hsec++;}
           if(timer4b.hsec>=100){timer4b.hsec=0;}
		   }

		  if(st_tm3a)	   //�������3a��ʱ��־Ϊ1����ʱ+0.1s
   		   {  
		   if(++timer3a.sec>=100){timer3a.sec=0;timer3a.hsec++;}
           if(timer3a.hsec>=100){timer3a.hsec=0;}
		   }

		  if(st_tm3b)	    //�������3b��ʱ��־Ϊ1����ʱ+0.1s
   		   {  
		   if(++timer3b.sec>=100){timer3b.sec=0;timer3b.hsec++;}
           if(timer3b.hsec>=100){timer3b.hsec=0;}
		   }


		  if(st_tm2a)	    //�������2a��ʱ��־Ϊ1����ʱ+0.1s
   		   {  
		   if(++timer2a.sec>=100){timer2a.sec=0;timer2a.hsec++;}
           if(timer2a.hsec>=100){timer2a.hsec=0;}
		   }

		  if(st_tm2b)	    //�������2b��ʱ��־Ϊ1����ʱ+0.1s
   		   {  
		   if(++timer2b.sec>=100){timer2b.sec=0;timer2b.hsec++;}
           if(timer2b.hsec>=100){timer2b.hsec=0;}
		   }

		  if(st_tm1a)		 //�������1a��ʱ��־Ϊ1����ʱ+0.1s
   		   {  
		   if(++timer1a.sec>=100){timer1a.sec=0;timer1a.hsec++;}
           if(timer1a.hsec>=100){timer1a.hsec=0;}
		   }

		  if(st_tm1b)		 //�������1b��ʱ��־Ϊ1����ʱ+0.1s
   		   {  
		   if(++timer1b.sec>=100){timer1b.sec=0;timer1b.hsec++;}
           if(timer1b.hsec>=100){timer1b.hsec=0;}
		   }

           num=0;
           motor_control();    //��������ʱ����ƣ�����ʱ��2.0s����ת0.3s����
		    	 
		  
     }

	 if(num1==20)
       {
	     LED1=0;
	   }

       if(num1==40)       //
       { 
         LED1=1;
		 num1=0;
		 }


	dis_fresh=1;	 
	if(lcd_dat==5)
	{lcd_dat=1;}       
	  
}


