#include <STC12C5A.h>
#include <absacc.h>
#include <intrins.h>
#include <math.h>
#include <string.h>


#define uchar unsigned char	
#define uint unsigned int
#define ulong unsigned long

#define WAVE_LEN 45

void key_scan(void);
void motor_control(void);

extern struct date
{
unsigned char hsec;
unsigned char sec;
}xtimer1,timer2,timer3,timer4,timer5,timer6,timer7,timer8;

extern unsigned char counter1_sec,counter2_sec,counter3_sec,counter4_sec,counter5_sec,counter6_sec,counter7_sec,counter8_sec;

uchar lcd_dat;



sbit    LED=P5^3;
sbit    LED1=P5^2;
extern  bit  dis_fresh;
/*
sbit xoutput1;
extern bit xoutput2;
extern bit xoutput3;
extern bit xoutput4;
extern bit xoutput5;
extern bit xoutput6;
extern bit xoutput7;
extern bit xoutput8;
*/

sbit xoutput1 = P1^0;
sbit xoutput2 = P1^1;
sbit xoutput3 = P1^2;
sbit xoutput4 = P1^3;
sbit xoutput5 = P1^4;
sbit xoutput6 = P1^5;
sbit xoutput7 = P1^6;
sbit xoutput8 = P1^7;

extern bit enable_timer1;
extern bit enable_timer2;
extern bit enable_timer3;
extern bit enable_timer4;
extern bit enable_timer5;
extern bit enable_timer6;
extern bit enable_timer7;
extern bit enable_timer8;

extern bit enable_counter1;
extern bit enable_counter2;
extern bit enable_counter3;
extern bit enable_counter4;
extern bit enable_counter5;
extern bit enable_counter6;
extern bit enable_counter7;
extern bit enable_counter8;


void init_timer0()
{
   P4SW=0xff;
   TMOD|=0X01;
   TH0=0x3C;				//如果时间要完全精确，需用12MHZ的晶振，25ms定时
   TL0=0xB0;
   EA=1;
   ET0=1;
   //TR0=1;
}

void timer0() interrupt 1 using 1
{
   
   unsigned char num,num1;
   CLK_DIV=0X00;
   TH0=0x3C;				//如果时间要完全精确，需用12MHZ的晶振,25ms定时
   TL0=0xB0;
   num++;
   num1++;
   lcd_dat++;
   key_scan();             //按键扫描
   
	  if(num==2)
       {
	     LED=0;				   //	  输出方波
	   }

       if(num==4)       //100ms计时+
       { 
         LED=1;

//timer 计数，用于显示
			if(enable_timer1){
				if(++xtimer1.sec>=100){xtimer1.sec=0;xtimer1.hsec++;}
				if(xtimer1.hsec>=100){xtimer1.hsec=0;}
			}

			if(enable_timer2){
				if(++timer2.sec>=100){timer2.sec=0;timer2.hsec++;}
				if(timer2.hsec>=100){timer2.hsec=0;}
			}

			if(enable_timer3){
				if(++timer3.sec>=100){timer3.sec=0;timer3.hsec++;}
				if(timer3.hsec>=100){timer3.hsec=0;}
			}

			if(enable_timer4){
				if(++timer4.sec>=100){timer4.sec=0;timer4.hsec++;}
				if(timer4.hsec>=100){timer4.hsec=0;}
			}

			if(enable_timer5){
				if(++timer5.sec>=100){timer5.sec=0;timer5.hsec++;}
				if(timer5.hsec>=100){timer5.hsec=0;}
			}

			if(enable_timer6){
				if(++timer6.sec>=100){timer6.sec=0;timer6.hsec++;}
				if(timer6.hsec>=100){timer6.hsec=0;}
			}

			if(enable_timer7){
				if(++timer7.sec>=100){timer7.sec=0;timer7.hsec++;}
				if(timer7.hsec>=100){timer7.hsec=0;}
			}

			if(enable_timer8){
				if(++timer8.sec>=100){timer8.sec=0;timer8.hsec++;}
				if(timer8.hsec>=100){timer8.hsec=0;}
			}

//counter 计数，用于输出波形
			if(enable_counter1){
				if(++counter1_sec>=WAVE_LEN){
				counter1_sec = 0;
				enable_counter1 = 0;
				xoutput1 = 1;
				}
			}

			if(enable_counter2){
				if(++counter2_sec>=WAVE_LEN){
				counter2_sec = 0;
				enable_counter2 = 0;
				xoutput2 = 1;
				}
			}

			if(enable_counter3){
				if(++counter3_sec>=WAVE_LEN){
				counter3_sec = 0;
				enable_counter3 = 0;
				xoutput3 = 1;
				}
			}

			if(enable_counter4){
				if(++counter4_sec>=WAVE_LEN){
				counter4_sec = 0;
				enable_counter4 = 0;
				xoutput4 = 1;
				}
			}

			if(enable_counter5){
				if(++counter5_sec>=WAVE_LEN){
				counter5_sec = 0;
				enable_counter5 = 0;
				xoutput5 = 1;
				}
			}

			if(enable_counter6){
				if(++counter6_sec>=WAVE_LEN){
				counter6_sec = 0;
				enable_counter6 = 0;
				xoutput6 = 1;
				}
			}

			if(enable_counter7){
				if(++counter7_sec>=WAVE_LEN){
				counter7_sec = 0;
				enable_counter7 = 0;
				xoutput7 = 1;
				}
			}

			if(enable_counter8){
				if(++counter8_sec>=WAVE_LEN){
				counter8_sec = 0;
				enable_counter8 = 0;
				xoutput8 = 1;
				}
			}

           num=0;

		    	 
		  
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
	if(lcd_dat>=5)
	{lcd_dat=1;}       
	  
}


