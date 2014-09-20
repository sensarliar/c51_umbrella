#include <STC12C5A.h>
#include <absacc.h>
#include <intrins.h>
#include  <define.h>



sbit zhengkong1=P1^0;	 //电机1正转控制信号，低有效		 
sbit fankong1=P1^1;		 //电机1反转控制信号，低有效
sbit dingdian1=P4^0;	 //顶点开关1信号，低有效



sbit zhengkong2=P2^3;	//电机2正转控制信号，低有效		 
sbit fankong2=P2^4;		//电机2反转控制信号，低有效
sbit dingdian2=P4^6;	//顶点开关2信号，低有效

sbit zhengkong3=P1^4;	//电机3正转控制信号，低有效		 
sbit fankong3=P1^5;		//电机3反转控制信号，低有效
sbit dingdian3=P5^0;	//顶点开关3信号，低有效

sbit zhengkong4=P3^0;	//电机4正转控制信号，低有效		 
sbit fankong4=P1^7;		//电机4反转控制信号，低有效
sbit dingdian4=P4^5;	//顶点开关4信号，低有效


sbit keystart=P0^0;		//启动按键，低有效
sbit keystop=P0^1;		//停止按键，低有效
sbit keyfan=P0^2;		//反转按键，低有效
sbit clr=P0^3;			//复位按键，低有效

sbit astop1=P5^2;		//工件1的A停止位，低有效
sbit astop2=P1^6;		//工件2的A停止位，低有效
sbit astop3=P4^2;		//工件3的A停止位，低有效
sbit astop4=P1^2;		//工件4的A停止位，低有效


sbit bstop1=P0^4;		//工件1的B停止位，低有效
sbit bstop2=P0^5;		//工件2的B停止位，低有效
sbit bstop3=P3^7;		//工件3的B停止位，低有效
sbit bstop4=P3^1;		//工件4的B停止位，低有效


sbit kong1=P0^6;		//工件1按键的位选，低有效
sbit kong2=P0^7;		//工件2按键的位选，低有效
sbit kong3=P2^0;		//工件3按键的位选，低有效
sbit kong4=P2^7;		//工件4按键的位选，低有效




sbit zero1=P2^2;		//工件1的零点，低有效
sbit zero2=P4^1;		//工件2的零点，低有效
sbit zero3=P2^5;		//工件3的零点，低有效
sbit zero4=P4^4;		//工件4的零点，低有效


unsigned char counter4=0,counter3=0,counter2=0,counter1=0;

unsigned  char bdata  kongzhi1;
unsigned  char bdata  kongzhi2;
unsigned  char bdata  fan1s5;

sbit  fanzhan4=kongzhi1^0;	    //电机4反转标志位，高有效
sbit  hold4=kongzhi1^1;			//电机4保持标志位，高有效
sbit  st_tm4a=kongzhi1^2;		//工件4，A计时开始标志，高有效
sbit  st_tm4b=kongzhi1^3;		//工件4，B计时开始标志，高有效


sbit  fanzhan3=kongzhi1^4;	    //电机3反转标志位，高有效
sbit  hold3=kongzhi1^5;			//电机3保持标志位，高有效
sbit  st_tm3a=kongzhi1^6;		//工件3，A计时开始标志，高有效
sbit  st_tm3b=kongzhi1^7;		//工件3，B计时开始标志，高有效

sbit  fanzhan2=kongzhi2^0;	    //电机2反转标志位，高有效
sbit  hold2=kongzhi2^1;			//电机2保持标志位，高有效
sbit  st_tm2a=kongzhi2^2;	    //工件2，A计时开始标志，高有效
sbit  st_tm2b=kongzhi2^3;		//工件2，B计时开始标志，高有效

sbit  fanzhan1=kongzhi2^4;		//电机1反转标志位，高有效
sbit  hold1=kongzhi2^5;			//电机1保持标志位，高有效
sbit  st_tm1a=kongzhi2^6;		//工件1，A计时开始标志，高有效
sbit  st_tm1b=kongzhi2^7;		//工件1，B计时开始标志，高有效

unsigned  char bdata  flag1;
unsigned  char bdata  flag2;
unsigned  char bdata  flag3;

sbit  zero_already4=flag1^0;	//工件4，已经在零位标志位，高有效
sbit  astop_already4=flag1^1;	//工件4，已经在A停止标志位，高有效
sbit  bstop_already4=flag1^2;	//工件4，已经在B停止标志位，高有效
sbit  ding_already4=flag1^3;	//工件4，已经在顶点标志位，高有效

sbit  zero_already3=flag1^4;	//工件3，已经在零位标志位，高有效
sbit  astop_already3=flag1^5;	//工件3，已经在A停止标志位，高有效
sbit  bstop_already3=flag1^6;	//工件3，已经在B停止标志位，高有效
sbit  ding_already3=flag1^7;	//工件3，已经在顶点标志位，高有效

sbit  zero_already2=flag2^0;	//工件2，已经在零位标志位，高有效
sbit  astop_already2=flag2^1;   //工件2，已经在A停止标志位，高有效
sbit  bstop_already2=flag2^2;   //工件2，已经在B停止标志位，高有效
sbit  ding_already2=flag2^3;	//工件2，已经在顶点标志位，高有效

sbit  zero_already1=flag2^4;	//工件1，已经在零位标志位，高有效
sbit  astop_already1=flag2^5;	//工件1，已经在A停止标志位，高有效
sbit  bstop_already1=flag2^6;	//工件1，已经在B停止标志位，高有效
sbit  ding_already1=flag2^7;	//工件1，已经在顶点标志位，高有效

sbit  start_already1=flag3^0;	//工件1，按下启动按键，高有效
sbit  start_already2=flag3^1;	//工件2，按下启动按键，高有效
sbit  start_already3=flag3^2;	//工件3，按下启动按键，高有效
sbit  start_already4=flag3^3;	//工件4，按下启动按键，高有效
sbit  hold_already1=flag3^4;	//工件1，已经处于保持状态，高有效
sbit  hold_already2=flag3^5;	//工件2，已经处于保持状态，高有效
sbit  hold_already3=flag3^6;	//工件3，已经处于保持状态，高有效
sbit  hold_already4=flag3^7;	//工件4，已经处于保持状态，高有效


sbit  fan1_1s5=fan1s5^1;        //工件1，离开零点反转1.5s
sbit  fan2_1s5=fan1s5^2;		//工件2，离开零点反转1.5s
sbit  fan3_1s5=fan1s5^3;		//工件3，离开零点反转1.5s
sbit  fan4_1s5=fan1s5^4;		//工件4，离开零点反转1.5s

								
extern struct date
{
unsigned char hsec;
unsigned char sec;
}timer1a,timer1b,timer2a,timer2b,timer3a,timer3b,timer4a,timer4b;

extern 	bit  dis_all;






void key_scan(void)
{
	// if(!(zero4||(!keystop)||zero_already4||(!start_already4)))		   //工件3到达零位，如果之前已在零位状态、或者停止键按下，或者没有启动该动作，工件不动作；
																		   //工件3到达零位，如果之前未在零位状态，停止键未按下，并启动该动作，工件执行零位动作
	  if(!(zero4||(!keystop)||zero_already4||hold_already4||start_already4))

	  {																  
	   zhengkong4=1;				 //电机34正转停止
	   fankong4=1;					 //电机4反转停止
	   zero_already4=1;

       hold_already4=1;
	   fanzhan4=0;
	   start_already4=1;
		
	    if(ding_already4)
	   {
	    hold4=0;					//如果在顶点4顶点标志为1（在顶点），不执行保持动作
		}
		else
		{
		hold4=1;				   //如果在顶点4顶点标志为0（非顶点），执行保持动作
		}				
	  }



	if(!zero4)					  //如果在零点4，电机3正转停止
	   {
	     zhengkong4=1;
	   }

	
    if(zero4)					  //如果离开零点4
	{
	  zero_already4=0;
	  hold_already4=0;
	  
	} 

		if(astop4)				 //工件4离开A停止位
	  {
	   astop_already4=0;
	  }

	if(!(astop4||(!keystop)||astop_already4))	   //工件4到达A停止位
	  {
	   st_tm4a=0;
	   //zhengkong1=1;			   2/23
	   //fankong1=1;			   2/23
	   //*hold3=0;
	   //fanzhan1=0;			   2/27
	   astop_already4=1;
	  }

	if(bstop4)					//工件4离开B停止位
	  {
	   bstop_already4=0;
	  }

	if(!(bstop4||(!keystop)||bstop_already4))		//工件4到达B停止位
	   {
	   st_tm4b=0;
	   bstop_already4=1;
	   }


	if(!kong4)
	{
	if(!(keystop||kong4))					   	//停止按键4按下，工件3所有动作停止
	   {
		zhengkong4=1;
	    fankong4=1; 
		start_already4=0;
		//zero_already3=0;    
	   }


	if(!(keystart||(!keystop)||(!keyfan)||(!fankong4)||kong4||zero_already4))		 //启动按键4按下（在非停止、非反转、非零位状态下）
	   {
	   if(!zero4)				  //非零位下，电机3正转
	   {
	     zhengkong4=1;
	   }
	   else
	   {
	     zhengkong4=0;
	   }

	   fankong4=1;

	   counter4=0;
	   
	   hold4=0;	         //

	   fanzhan4=0;

	   start_already4=0;
	   	   
       }

    if(!(keyfan||(!keystop)||(!keystart)||(!zhengkong4)||kong4||ding_already4))		   //反转按键4按下（在非停止、非正转、非顶点状态下）
	  {
	   zhengkong4=1;
	   fankong4=0;

	   counter4=0;
	   hold4=0;
	   fanzhan4=1;

	   st_tm4a=1;
	   st_tm4b=1;
	   timer4a.sec=0;				 //计时数据、计时标志清零
	   timer4a.hsec=0;
	   timer4b.sec=0;
	   timer4b.hsec=0;

	   start_already4=0;
      }
  }	   
	
	 


	// if(!(zero3||(!keystop)||zero_already3||(!start_already3)))		   //工件3到达零位，如果之前已在零位状态、或者停止键按下，或者没有启动该动作，工件不动作；
																		   //工件3到达零位，如果之前未在零位状态，停止键未按下，并启动该动作，工件执行零位动作
	  if(!(zero3||(!keystop)||zero_already3||hold_already3||start_already3))

	  {																  
	   zhengkong3=1;				 //电机3正转停止
	   fankong3=1;					 //电机3反转停止
	   zero_already3=1;

       hold_already3=1;
	   fanzhan3=0;
	   start_already3=1;
		
	    if(ding_already3)
	   {
	    hold3=0;					//如果在顶点3顶点标志为1（在顶点），不执行保持动作
		}
		else
		{
		hold3=1;				   //如果在顶点3顶点标志为0（非顶点），执行保持动作
		}				
	  }



	if(!zero3)					  //如果在零点3，电机3正转停止
	   {
	     zhengkong3=1;
	   }

	
    if(zero3)					  //如果离开零点3
	{
	  zero_already3=0;
	  hold_already3=0;
	  
	} 

		if(astop3)				 //工件3离开A停止位
	  {
	   astop_already3=0;
	  }

	if(!(astop3||(!keystop)||astop_already3))	   //工件3到达A停止位
	  {
	   st_tm3a=0;
	   //zhengkong1=1;			   2/23
	   //fankong1=1;			   2/23
	   //*hold3=0;
	   //fanzhan1=0;			   2/27
	   astop_already3=1;
	  }

	if(bstop3)					//工件3离开B停止位
	  {
	   bstop_already3=0;
	  }

	if(!(bstop3||(!keystop)||bstop_already3))		//工件3到达B停止位
	   {
	   st_tm3b=0;
	   bstop_already3=1;
	   }


	if(!kong3)
	{
	if(!(keystop||kong3))					   	//停止按键3按下，工件3所有动作停止
	   {
		zhengkong3=1;
	    fankong3=1; 
		start_already3=0;
		//zero_already3=0;    
	   }


	if(!(keystart||(!keystop)||(!keyfan)||(!fankong3)||kong3||zero_already3))		 //启动按键3按下（在非停止、非反转、非零位状态下）
	   {
	   if(!zero3)				  //非零位下，电机3正转
	   {
	     zhengkong3=1;
	   }
	   else
	   {
	     zhengkong3=0;
	   }

	   fankong3=1;

	   counter3=0;
	   
	   hold3=0;	         //

	   fanzhan3=0;

	   start_already3=0;
	   	   
       }

    if(!(keyfan||(!keystop)||(!keystart)||(!zhengkong3)||kong3||ding_already3))		   //反转按键3按下（在非停止、非正转、非顶点状态下）
	  {
	   zhengkong3=1;
	   fankong3=0;

	   counter3=0;
	   hold3=0;
	   fanzhan3=1;

	   st_tm3a=1;
	   st_tm3b=1;
	   timer3a.sec=0;				 //计时数据、计时标志清零
	   timer3a.hsec=0;
	   timer3b.sec=0;
	   timer3b.hsec=0;

	   start_already3=0;
      }
  }
//////////////////////////////////////////////////////////////////////////////////////////////////	 
	 // if(!(zero2||(!keystop)||zero_already2||(!start_already2)))		   //工件2到达零位，如果之前已在零位状态、或者停止键按下，或者没有启动该动作，工件不动作；
																		   //工件2到达零位，如果之前未在零位状态，停止键未按下，并启动该动作，工件执行零位动作
	  if(!(zero2||(!keystop)||zero_already2||hold_already2||start_already2))

	  {																  
	   zhengkong2=1;				 //电机2正转停止
	   fankong2=1;					 //电机2反转停止
	   zero_already2=1;
	   start_already2=1;
       hold_already2=1;
	   fanzhan2=0;
	 	
	    if(ding_already2)
	   {
	    hold2=0;					//如果在顶点2顶点标志为1（在顶点），不执行保持动作
		}
		else
		{
		hold2=1;				   //如果在顶点2顶点标志为0（非顶点），执行保持动作
		}		

	  }

	 if(zero2)					  //如果离开零点2
	{
	  zero_already2=0;
	  hold_already2=0;
	  
	} 

	if(!zero2)					  //如果在零点2，电机2正转停止
	   {
	     zhengkong2=1;
	   }


		if(astop2)				 //工件2离开A停止位
	  {
	   astop_already2=0;
	  }

	if(!(astop2||(!keystop)||astop_already2))	   //工件2到达A停止位
	  {
	   st_tm2a=0;
	   astop_already2=1;
	  }

	if(bstop2)					//工件2离开B停止位
	  {
	   bstop_already2=0;
	  }

	if(!(bstop2||(!keystop)||bstop_already2))		//工件2到达B停止位
	   {
	   st_tm2b=0;
	   bstop_already2=1;
	   }


	if(!kong2)
	{
	if(!(keystop||kong2))					   	//停止按键2按下，工件2所有动作停止
	   {
		zhengkong2=1;
	    fankong2=1; 
		start_already2=0;
		zero_already2=0;    
	   }


	if(!(keystart||(!keystop)||(!keyfan)||(!fankong2)||kong2||zero_already2))		 //启动按键2按下（在非停止、非反转、非零位状态下）
	   {
	   if(!zero2)				  //非零位下，电机2正转
	   {
	     zhengkong2=1;
	   }
	   else
	   {
	     zhengkong2=0;
	   }

	   fankong2=1;

	   counter2=0;
	   
	   hold2=0;	         //

	   fanzhan2=0;

	   start_already2=0;
	   	   
       }

    if(!(keyfan||(!keystop)||(!keystart)||(!zhengkong2)||kong2||ding_already2))		   //反转按键2按下（在非停止、非正转、非顶点状态下）
	  {
	   zhengkong2=1;
	   fankong2=0;

	   counter2=0;
	   hold2=0;
	   fanzhan2=1;
	   start_already2=0;
	   st_tm2a=1;
	   st_tm2b=1;
	   timer2a.sec=0;				 //计时数据、计时标志清零
	   timer2a.hsec=0;
	   timer2b.sec=0;
	   timer2b.hsec=0;

      }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////	 
	 // if(!(zero1||(!keystop)||zero_already1||(!start_already1)))		   //工件1到达零位，如果之前已在零位状态、或者停止键按下，或者没有启动该动作，工件不动作；
																		   //工件1到达零位，如果之前未在零位状态，停止键未按下，并启动该动作，工件执行零位动作
	  if(!(zero1||(!keystop)||zero_already1||hold_already1||start_already1))

	  {																  
	   zhengkong1=1;				 //电机1正转停止
	   fankong1=1;					 //电机1反转停止
	   zero_already1=1;
	   start_already1=1;
       hold_already1=1;
	   fanzhan1=0;
	 	
	    if(ding_already1)
	   {
	    hold1=0;					//如果在顶点1顶点标志为1（在顶点），不执行保持动作
		}
		else
		{
		hold1=1;				   //如果在顶点1顶点标志为0（非顶点），执行保持动作
		}	

	  }

	 if(zero1)					  //如果离开零点1
	{
	  zero_already1=0;
	  hold_already1=0;
	  
	} 

	if(!zero1)					  //如果在零点1，电机1正转停止
	   {
	     zhengkong1=1;
	   }


		if(astop1)				 //工件1离开A停止位
	  {
	   astop_already1=0;
	  }

	if(!(astop1||(!keystop)||astop_already1))	   //工件1到达A停止位
	  {
	   st_tm1a=0;
	   astop_already1=1;
	  }

	if(bstop1)					//工件1离开B停止位
	  {
	   bstop_already1=0;
	  }

	if(!(bstop1||(!keystop)||bstop_already1))		//工件1到达B停止位
	   {
	   st_tm1b=0;
	   bstop_already1=1;
	   }


	if(!kong1)
	{
	if(!(keystop||kong1))					   	//停止按键1按下，工件1所有动作停止
	   {
		zhengkong1=1;
	    fankong1=1; 
		start_already1=0;
		zero_already1=0;    
	   }


	if(!(keystart||(!keystop)||(!keyfan)||(!fankong1)||kong1||zero_already1))		 //启动按键1按下（在非停止、非反转、非零位状态下）
	   {
	   if(!zero1)				  //非零位下，电机1正转
	   {
	     zhengkong1=1;
	   }
	   else
	   {
	     zhengkong1=0;
	   }

	   fankong1=1;

	   counter1=0;
	   
	   hold1=0;	         //

	   fanzhan1=0;

	   start_already1=0;
	   	   
       }

    if(!(keyfan||(!keystop)||(!keystart)||(!zhengkong1)||kong1||ding_already1))		   //反转按键1按下（在非停止、非正转、非顶点状态下）
	  {
	   zhengkong1=1;
	   fankong1=0;

	   counter1=0;
	   hold1=0;
	   fanzhan1=1;
	   start_already1=0;
	   st_tm1a=1;
	   st_tm1b=1;
	   timer1a.sec=0;				 //计时数据、计时标志清零
	   timer1a.hsec=0;
	   timer1b.sec=0;
	   timer1b.hsec=0;

      }
  }  

    

	if(!(clr||kong4))		//复位按键4，工件4的时间清零、动作都停止和所有显示刷新
	  {
	   st_tm4a=0;
	   st_tm4b=0;
	   zhengkong4=1;
	   fankong4=1;
	   //stop1=1;
	   timer4a.sec=0;
	   timer4a.hsec=0;
	   hold4=0;
	   fanzhan4=0;
	   counter4=0;

	   timer4b.sec=0;
	   timer4b.hsec=0;

	   zero_already4=0;
       astop_already4=0;
       bstop_already4=0;
       ding_already4=0;
	   start_already4=0;
	   hold_already4=0;
	   dis_all=1;
      }


	 if(!(clr||kong3))		//复位按键3，工件3的时间清零、动作都停止和所有显示刷新
	  {
	   st_tm3a=0;
	   st_tm3b=0;
	   zhengkong3=1;
	   fankong3=1;
	   //stop1=1;
	   timer3a.sec=0;
	   timer3a.hsec=0;
	   hold3=0;
	   fanzhan3=0;
	   counter3=0;

	   timer3b.sec=0;
	   timer3b.hsec=0;

	   zero_already3=0;
       astop_already3=0;
       bstop_already3=0;
       ding_already3=0;
	   start_already3=0;
	   hold_already3=0;
	   dis_all=1;
      }
	 

   if(!(clr||kong2))		  //复位按键2，工件2的时间清零、动作都停止和所有显示刷新
	  {
	   st_tm2a=0;
	   st_tm2b=0;
	   zhengkong2=1;
	   fankong2=1;
	   //stop1=1;
	   timer2a.sec=0;
	   timer2a.hsec=0;
	   hold2=0;
	   fanzhan2=0;
	   counter2=0;

	   timer2b.sec=0;
	   timer2b.hsec=0;
	   
	   zero_already2=0;
       astop_already2=0;
       bstop_already2=0;
	   start_already2=0;
       ding_already2=0;
	   hold_already2=0;   
	   dis_all=1;
	   }

   if(!(clr||kong1))		  //复位按键1，工件1的时间清零、动作都停止和所有显示刷新
	  {
	   st_tm1a=0;
	   st_tm1b=0;
	   zhengkong1=1;
	   fankong1=1;
	   //stop1=1;
	   timer1a.sec=0;
	   timer1a.hsec=0;
	   hold1=0;
	   fanzhan1=0;
	   counter1=0;

	   timer1b.sec=0;
	   timer1b.hsec=0;


	   zero_already1=0;
       astop_already1=0;
       bstop_already1=0;
       ding_already1=0;
	   start_already1=0;
	   hold_already1=0;
	   dis_all=1;
	  }

	if(!(dingdian1||ding_already1))		  //工件1到达顶点，电机1停止反转
	  {
	   //zhengkong1=1;
	   fankong1=1; 
	   ding_already1=1;

	   hold1=0;
	   fanzhan1=0;
	   counter1=0;
	  } 

	if(dingdian1)						 //工件1离开顶点
	 {
	 ding_already1=0;
	 }

	if(!(dingdian2||ding_already2))		 //工件2到达顶点，电机2停止反转
	{
	   //zhengkong2=1;
	   fankong2=1;
	   ding_already2=1; 

	   hold2=0;
	   fanzhan2=0;
	   counter2=0;
	}
	if(dingdian2)					    //工件2离开顶点
	{
	   ding_already2=0;
	}

   	if(!(dingdian3||ding_already3))		 //工件3到达顶点，电机3停止反转
	{
	   //zhengkong3=1;
	   fankong3=1; 
	   ding_already3=1;

	   hold3=0;
	   fanzhan3=0;
	   counter3=0;
	}

	if(dingdian3)						//工件3离开顶点
	{
	   ding_already3=0;
	}


  	if(!(dingdian4||ding_already4))		 //工件4到达顶点，电机4停止反转
	{
	   //zhengkong3=1;
	   fankong4=1; 
	   ding_already4=1;

	   hold4=0;
	   fanzhan4=0;
	   counter4=0;
	}

	if(dingdian4)						//工件4离开顶点
	{
	   ding_already4=0;
	}

	
	
}

void motor_control(void)
{
    
   	if(hold4)					   //工件4在零位保持，所有动作停止
	    {   
   	         hold_already4=1;
			 counter4++;
			 if(counter4==20)	   //电机4保持时间为2.0s&&&
			 {
			     fanzhan4=1;
				 hold4=0;
				 fan4_1s5=1;
				 counter4=0;
				 zhengkong4=1;
				 fankong4=0;
				 
			  }
         }

    if((!ding_already4)&&fan4_1s5)	 	 //电机3反转0.3s控制，反转标志3为1并且不在顶点3
         {   
   	         counter4++;
			 if(counter4==3)			 //电机3反转控制，时间为0.3s&&&
			 {
			     fanzhan4=0;
				 hold4=0;
				 counter4=0;
				 zhengkong4=1;
				 fankong4=1;
				hold_already4=0;
				 fan4_1s5=0;
			  }
         }


	if(hold3)					   //工件3在零位保持，所有动作停止
	    {   
   	         hold_already3=1;
			 counter3++;
			 if(counter3==20)	   //电机3保持时间为2.0s&&&
			 {
			     fanzhan3=1;
				 hold3=0;
				 fan3_1s5=1;
				 counter3=0;
				 zhengkong3=1;
				 fankong3=0;
				 
			  }
         }

    if((!ding_already3)&&fan3_1s5)	 	 //电机3反转0.3s控制，反转标志3为1并且不在顶点3
         {   
   	         counter3++;
			 if(counter3==3)			 //电机3反转控制，时间为0.3s&&&
			 {
			     fanzhan3=0;
				 hold3=0;
				 counter3=0;
				 zhengkong3=1;
				 fankong3=1;
				hold_already3=0;
				 fan3_1s5=0;
			  }
         }



		if(hold2)					   //工件3在零位保持，所有动作停止
	    {   
   	         hold_already2=1;
			 counter2++;
			 if(counter2==20)	   //电机3保持时间为2.0s&&&
			 {
			     fanzhan2=1;
				 hold2=0;
				 fan2_1s5=1;
				 counter2=0;
				 zhengkong2=1;
				 fankong2=0;
				 
			  }
         }

    if((!ding_already2)&&fan2_1s5)	 	 //电机2反转0.3s控制，反转标志3为1并且不在顶点3
         {   
   	         counter2++;
			 if(counter2==3)			 //电机2反转控制，时间为0.3s&&&
			 {
			     fanzhan2=0;
				 hold2=0;
				 counter2=0;
				 zhengkong2=1;
				 fankong2=1;
				 //zero_already1=0;
				hold_already2=0;
				 fan2_1s5=0;
			  }
         }


		if(hold1)					   //工件3在零位保持，所有动作停止
	    {   
   	         hold_already1=1;
			 counter1++;
			 if(counter1==20)	   //电机3保持时间为2.0s&&&
			 {
			     fanzhan1=1;
				 hold1=0;
				 fan1_1s5=1;
				 counter1=0;
				 zhengkong1=1;
				 fankong1=0;
				 
			  }
         }

    if((!ding_already1)&&fan1_1s5)	 	 //电机1反转0.3s控制，反转标志3为1并且不在顶点3
         {   
   	         counter1++;
			 if(counter1==3)			 //电机1反转控制，时间为0.3s&&&
			 {
			     fanzhan1=0;
				 hold1=0;
				 counter1=0;
				 zhengkong1=1;
				 fankong1=1;
				 //zero_already1=0;
				 hold_already1=0;
				 fan1_1s5=0;
			  }
         }


} 
