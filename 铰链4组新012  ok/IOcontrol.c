#include <STC12C5A.h>
#include <absacc.h>
#include <intrins.h>
#include  <define.h>



sbit zhengkong1=P1^0;	 //���1��ת�����źţ�����Ч		 
sbit fankong1=P1^1;		 //���1��ת�����źţ�����Ч
sbit dingdian1=P4^0;	 //���㿪��1�źţ�����Ч



sbit zhengkong2=P2^3;	//���2��ת�����źţ�����Ч		 
sbit fankong2=P2^4;		//���2��ת�����źţ�����Ч
sbit dingdian2=P4^6;	//���㿪��2�źţ�����Ч

sbit zhengkong3=P1^4;	//���3��ת�����źţ�����Ч		 
sbit fankong3=P1^5;		//���3��ת�����źţ�����Ч
sbit dingdian3=P5^0;	//���㿪��3�źţ�����Ч

sbit zhengkong4=P3^0;	//���4��ת�����źţ�����Ч		 
sbit fankong4=P1^7;		//���4��ת�����źţ�����Ч
sbit dingdian4=P4^5;	//���㿪��4�źţ�����Ч


sbit keystart=P0^0;		//��������������Ч
sbit keystop=P0^1;		//ֹͣ����������Ч
sbit keyfan=P0^2;		//��ת����������Ч
sbit clr=P0^3;			//��λ����������Ч

sbit astop1=P5^2;		//����1��Aֹͣλ������Ч
sbit astop2=P1^6;		//����2��Aֹͣλ������Ч
sbit astop3=P4^2;		//����3��Aֹͣλ������Ч
sbit astop4=P1^2;		//����4��Aֹͣλ������Ч


sbit bstop1=P0^4;		//����1��Bֹͣλ������Ч
sbit bstop2=P0^5;		//����2��Bֹͣλ������Ч
sbit bstop3=P3^7;		//����3��Bֹͣλ������Ч
sbit bstop4=P3^1;		//����4��Bֹͣλ������Ч


sbit kong1=P0^6;		//����1������λѡ������Ч
sbit kong2=P0^7;		//����2������λѡ������Ч
sbit kong3=P2^0;		//����3������λѡ������Ч
sbit kong4=P2^7;		//����4������λѡ������Ч




sbit zero1=P2^2;		//����1����㣬����Ч
sbit zero2=P4^1;		//����2����㣬����Ч
sbit zero3=P2^5;		//����3����㣬����Ч
sbit zero4=P4^4;		//����4����㣬����Ч


unsigned char counter4=0,counter3=0,counter2=0,counter1=0;

unsigned  char bdata  kongzhi1;
unsigned  char bdata  kongzhi2;
unsigned  char bdata  fan1s5;

sbit  fanzhan4=kongzhi1^0;	    //���4��ת��־λ������Ч
sbit  hold4=kongzhi1^1;			//���4���ֱ�־λ������Ч
sbit  st_tm4a=kongzhi1^2;		//����4��A��ʱ��ʼ��־������Ч
sbit  st_tm4b=kongzhi1^3;		//����4��B��ʱ��ʼ��־������Ч


sbit  fanzhan3=kongzhi1^4;	    //���3��ת��־λ������Ч
sbit  hold3=kongzhi1^5;			//���3���ֱ�־λ������Ч
sbit  st_tm3a=kongzhi1^6;		//����3��A��ʱ��ʼ��־������Ч
sbit  st_tm3b=kongzhi1^7;		//����3��B��ʱ��ʼ��־������Ч

sbit  fanzhan2=kongzhi2^0;	    //���2��ת��־λ������Ч
sbit  hold2=kongzhi2^1;			//���2���ֱ�־λ������Ч
sbit  st_tm2a=kongzhi2^2;	    //����2��A��ʱ��ʼ��־������Ч
sbit  st_tm2b=kongzhi2^3;		//����2��B��ʱ��ʼ��־������Ч

sbit  fanzhan1=kongzhi2^4;		//���1��ת��־λ������Ч
sbit  hold1=kongzhi2^5;			//���1���ֱ�־λ������Ч
sbit  st_tm1a=kongzhi2^6;		//����1��A��ʱ��ʼ��־������Ч
sbit  st_tm1b=kongzhi2^7;		//����1��B��ʱ��ʼ��־������Ч

unsigned  char bdata  flag1;
unsigned  char bdata  flag2;
unsigned  char bdata  flag3;

sbit  zero_already4=flag1^0;	//����4���Ѿ�����λ��־λ������Ч
sbit  astop_already4=flag1^1;	//����4���Ѿ���Aֹͣ��־λ������Ч
sbit  bstop_already4=flag1^2;	//����4���Ѿ���Bֹͣ��־λ������Ч
sbit  ding_already4=flag1^3;	//����4���Ѿ��ڶ����־λ������Ч

sbit  zero_already3=flag1^4;	//����3���Ѿ�����λ��־λ������Ч
sbit  astop_already3=flag1^5;	//����3���Ѿ���Aֹͣ��־λ������Ч
sbit  bstop_already3=flag1^6;	//����3���Ѿ���Bֹͣ��־λ������Ч
sbit  ding_already3=flag1^7;	//����3���Ѿ��ڶ����־λ������Ч

sbit  zero_already2=flag2^0;	//����2���Ѿ�����λ��־λ������Ч
sbit  astop_already2=flag2^1;   //����2���Ѿ���Aֹͣ��־λ������Ч
sbit  bstop_already2=flag2^2;   //����2���Ѿ���Bֹͣ��־λ������Ч
sbit  ding_already2=flag2^3;	//����2���Ѿ��ڶ����־λ������Ч

sbit  zero_already1=flag2^4;	//����1���Ѿ�����λ��־λ������Ч
sbit  astop_already1=flag2^5;	//����1���Ѿ���Aֹͣ��־λ������Ч
sbit  bstop_already1=flag2^6;	//����1���Ѿ���Bֹͣ��־λ������Ч
sbit  ding_already1=flag2^7;	//����1���Ѿ��ڶ����־λ������Ч

sbit  start_already1=flag3^0;	//����1��������������������Ч
sbit  start_already2=flag3^1;	//����2��������������������Ч
sbit  start_already3=flag3^2;	//����3��������������������Ч
sbit  start_already4=flag3^3;	//����4��������������������Ч
sbit  hold_already1=flag3^4;	//����1���Ѿ����ڱ���״̬������Ч
sbit  hold_already2=flag3^5;	//����2���Ѿ����ڱ���״̬������Ч
sbit  hold_already3=flag3^6;	//����3���Ѿ����ڱ���״̬������Ч
sbit  hold_already4=flag3^7;	//����4���Ѿ����ڱ���״̬������Ч


sbit  fan1_1s5=fan1s5^1;        //����1���뿪��㷴ת1.5s
sbit  fan2_1s5=fan1s5^2;		//����2���뿪��㷴ת1.5s
sbit  fan3_1s5=fan1s5^3;		//����3���뿪��㷴ת1.5s
sbit  fan4_1s5=fan1s5^4;		//����4���뿪��㷴ת1.5s

								
extern struct date
{
unsigned char hsec;
unsigned char sec;
}timer1a,timer1b,timer2a,timer2b,timer3a,timer3b,timer4a,timer4b;

extern 	bit  dis_all;






void key_scan(void)
{
	// if(!(zero4||(!keystop)||zero_already4||(!start_already4)))		   //����3������λ�����֮ǰ������λ״̬������ֹͣ�����£�����û�������ö�����������������
																		   //����3������λ�����֮ǰδ����λ״̬��ֹͣ��δ���£��������ö���������ִ����λ����
	  if(!(zero4||(!keystop)||zero_already4||hold_already4||start_already4))

	  {																  
	   zhengkong4=1;				 //���34��תֹͣ
	   fankong4=1;					 //���4��תֹͣ
	   zero_already4=1;

       hold_already4=1;
	   fanzhan4=0;
	   start_already4=1;
		
	    if(ding_already4)
	   {
	    hold4=0;					//����ڶ���4�����־Ϊ1���ڶ��㣩����ִ�б��ֶ���
		}
		else
		{
		hold4=1;				   //����ڶ���4�����־Ϊ0���Ƕ��㣩��ִ�б��ֶ���
		}				
	  }



	if(!zero4)					  //��������4�����3��תֹͣ
	   {
	     zhengkong4=1;
	   }

	
    if(zero4)					  //����뿪���4
	{
	  zero_already4=0;
	  hold_already4=0;
	  
	} 

		if(astop4)				 //����4�뿪Aֹͣλ
	  {
	   astop_already4=0;
	  }

	if(!(astop4||(!keystop)||astop_already4))	   //����4����Aֹͣλ
	  {
	   st_tm4a=0;
	   //zhengkong1=1;			   2/23
	   //fankong1=1;			   2/23
	   //*hold3=0;
	   //fanzhan1=0;			   2/27
	   astop_already4=1;
	  }

	if(bstop4)					//����4�뿪Bֹͣλ
	  {
	   bstop_already4=0;
	  }

	if(!(bstop4||(!keystop)||bstop_already4))		//����4����Bֹͣλ
	   {
	   st_tm4b=0;
	   bstop_already4=1;
	   }


	if(!kong4)
	{
	if(!(keystop||kong4))					   	//ֹͣ����4���£�����3���ж���ֹͣ
	   {
		zhengkong4=1;
	    fankong4=1; 
		start_already4=0;
		//zero_already3=0;    
	   }


	if(!(keystart||(!keystop)||(!keyfan)||(!fankong4)||kong4||zero_already4))		 //��������4���£��ڷ�ֹͣ���Ƿ�ת������λ״̬�£�
	   {
	   if(!zero4)				  //����λ�£����3��ת
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

    if(!(keyfan||(!keystop)||(!keystart)||(!zhengkong4)||kong4||ding_already4))		   //��ת����4���£��ڷ�ֹͣ������ת���Ƕ���״̬�£�
	  {
	   zhengkong4=1;
	   fankong4=0;

	   counter4=0;
	   hold4=0;
	   fanzhan4=1;

	   st_tm4a=1;
	   st_tm4b=1;
	   timer4a.sec=0;				 //��ʱ���ݡ���ʱ��־����
	   timer4a.hsec=0;
	   timer4b.sec=0;
	   timer4b.hsec=0;

	   start_already4=0;
      }
  }	   
	
	 


	// if(!(zero3||(!keystop)||zero_already3||(!start_already3)))		   //����3������λ�����֮ǰ������λ״̬������ֹͣ�����£�����û�������ö�����������������
																		   //����3������λ�����֮ǰδ����λ״̬��ֹͣ��δ���£��������ö���������ִ����λ����
	  if(!(zero3||(!keystop)||zero_already3||hold_already3||start_already3))

	  {																  
	   zhengkong3=1;				 //���3��תֹͣ
	   fankong3=1;					 //���3��תֹͣ
	   zero_already3=1;

       hold_already3=1;
	   fanzhan3=0;
	   start_already3=1;
		
	    if(ding_already3)
	   {
	    hold3=0;					//����ڶ���3�����־Ϊ1���ڶ��㣩����ִ�б��ֶ���
		}
		else
		{
		hold3=1;				   //����ڶ���3�����־Ϊ0���Ƕ��㣩��ִ�б��ֶ���
		}				
	  }



	if(!zero3)					  //��������3�����3��תֹͣ
	   {
	     zhengkong3=1;
	   }

	
    if(zero3)					  //����뿪���3
	{
	  zero_already3=0;
	  hold_already3=0;
	  
	} 

		if(astop3)				 //����3�뿪Aֹͣλ
	  {
	   astop_already3=0;
	  }

	if(!(astop3||(!keystop)||astop_already3))	   //����3����Aֹͣλ
	  {
	   st_tm3a=0;
	   //zhengkong1=1;			   2/23
	   //fankong1=1;			   2/23
	   //*hold3=0;
	   //fanzhan1=0;			   2/27
	   astop_already3=1;
	  }

	if(bstop3)					//����3�뿪Bֹͣλ
	  {
	   bstop_already3=0;
	  }

	if(!(bstop3||(!keystop)||bstop_already3))		//����3����Bֹͣλ
	   {
	   st_tm3b=0;
	   bstop_already3=1;
	   }


	if(!kong3)
	{
	if(!(keystop||kong3))					   	//ֹͣ����3���£�����3���ж���ֹͣ
	   {
		zhengkong3=1;
	    fankong3=1; 
		start_already3=0;
		//zero_already3=0;    
	   }


	if(!(keystart||(!keystop)||(!keyfan)||(!fankong3)||kong3||zero_already3))		 //��������3���£��ڷ�ֹͣ���Ƿ�ת������λ״̬�£�
	   {
	   if(!zero3)				  //����λ�£����3��ת
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

    if(!(keyfan||(!keystop)||(!keystart)||(!zhengkong3)||kong3||ding_already3))		   //��ת����3���£��ڷ�ֹͣ������ת���Ƕ���״̬�£�
	  {
	   zhengkong3=1;
	   fankong3=0;

	   counter3=0;
	   hold3=0;
	   fanzhan3=1;

	   st_tm3a=1;
	   st_tm3b=1;
	   timer3a.sec=0;				 //��ʱ���ݡ���ʱ��־����
	   timer3a.hsec=0;
	   timer3b.sec=0;
	   timer3b.hsec=0;

	   start_already3=0;
      }
  }
//////////////////////////////////////////////////////////////////////////////////////////////////	 
	 // if(!(zero2||(!keystop)||zero_already2||(!start_already2)))		   //����2������λ�����֮ǰ������λ״̬������ֹͣ�����£�����û�������ö�����������������
																		   //����2������λ�����֮ǰδ����λ״̬��ֹͣ��δ���£��������ö���������ִ����λ����
	  if(!(zero2||(!keystop)||zero_already2||hold_already2||start_already2))

	  {																  
	   zhengkong2=1;				 //���2��תֹͣ
	   fankong2=1;					 //���2��תֹͣ
	   zero_already2=1;
	   start_already2=1;
       hold_already2=1;
	   fanzhan2=0;
	 	
	    if(ding_already2)
	   {
	    hold2=0;					//����ڶ���2�����־Ϊ1���ڶ��㣩����ִ�б��ֶ���
		}
		else
		{
		hold2=1;				   //����ڶ���2�����־Ϊ0���Ƕ��㣩��ִ�б��ֶ���
		}		

	  }

	 if(zero2)					  //����뿪���2
	{
	  zero_already2=0;
	  hold_already2=0;
	  
	} 

	if(!zero2)					  //��������2�����2��תֹͣ
	   {
	     zhengkong2=1;
	   }


		if(astop2)				 //����2�뿪Aֹͣλ
	  {
	   astop_already2=0;
	  }

	if(!(astop2||(!keystop)||astop_already2))	   //����2����Aֹͣλ
	  {
	   st_tm2a=0;
	   astop_already2=1;
	  }

	if(bstop2)					//����2�뿪Bֹͣλ
	  {
	   bstop_already2=0;
	  }

	if(!(bstop2||(!keystop)||bstop_already2))		//����2����Bֹͣλ
	   {
	   st_tm2b=0;
	   bstop_already2=1;
	   }


	if(!kong2)
	{
	if(!(keystop||kong2))					   	//ֹͣ����2���£�����2���ж���ֹͣ
	   {
		zhengkong2=1;
	    fankong2=1; 
		start_already2=0;
		zero_already2=0;    
	   }


	if(!(keystart||(!keystop)||(!keyfan)||(!fankong2)||kong2||zero_already2))		 //��������2���£��ڷ�ֹͣ���Ƿ�ת������λ״̬�£�
	   {
	   if(!zero2)				  //����λ�£����2��ת
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

    if(!(keyfan||(!keystop)||(!keystart)||(!zhengkong2)||kong2||ding_already2))		   //��ת����2���£��ڷ�ֹͣ������ת���Ƕ���״̬�£�
	  {
	   zhengkong2=1;
	   fankong2=0;

	   counter2=0;
	   hold2=0;
	   fanzhan2=1;
	   start_already2=0;
	   st_tm2a=1;
	   st_tm2b=1;
	   timer2a.sec=0;				 //��ʱ���ݡ���ʱ��־����
	   timer2a.hsec=0;
	   timer2b.sec=0;
	   timer2b.hsec=0;

      }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////	 
	 // if(!(zero1||(!keystop)||zero_already1||(!start_already1)))		   //����1������λ�����֮ǰ������λ״̬������ֹͣ�����£�����û�������ö�����������������
																		   //����1������λ�����֮ǰδ����λ״̬��ֹͣ��δ���£��������ö���������ִ����λ����
	  if(!(zero1||(!keystop)||zero_already1||hold_already1||start_already1))

	  {																  
	   zhengkong1=1;				 //���1��תֹͣ
	   fankong1=1;					 //���1��תֹͣ
	   zero_already1=1;
	   start_already1=1;
       hold_already1=1;
	   fanzhan1=0;
	 	
	    if(ding_already1)
	   {
	    hold1=0;					//����ڶ���1�����־Ϊ1���ڶ��㣩����ִ�б��ֶ���
		}
		else
		{
		hold1=1;				   //����ڶ���1�����־Ϊ0���Ƕ��㣩��ִ�б��ֶ���
		}	

	  }

	 if(zero1)					  //����뿪���1
	{
	  zero_already1=0;
	  hold_already1=0;
	  
	} 

	if(!zero1)					  //��������1�����1��תֹͣ
	   {
	     zhengkong1=1;
	   }


		if(astop1)				 //����1�뿪Aֹͣλ
	  {
	   astop_already1=0;
	  }

	if(!(astop1||(!keystop)||astop_already1))	   //����1����Aֹͣλ
	  {
	   st_tm1a=0;
	   astop_already1=1;
	  }

	if(bstop1)					//����1�뿪Bֹͣλ
	  {
	   bstop_already1=0;
	  }

	if(!(bstop1||(!keystop)||bstop_already1))		//����1����Bֹͣλ
	   {
	   st_tm1b=0;
	   bstop_already1=1;
	   }


	if(!kong1)
	{
	if(!(keystop||kong1))					   	//ֹͣ����1���£�����1���ж���ֹͣ
	   {
		zhengkong1=1;
	    fankong1=1; 
		start_already1=0;
		zero_already1=0;    
	   }


	if(!(keystart||(!keystop)||(!keyfan)||(!fankong1)||kong1||zero_already1))		 //��������1���£��ڷ�ֹͣ���Ƿ�ת������λ״̬�£�
	   {
	   if(!zero1)				  //����λ�£����1��ת
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

    if(!(keyfan||(!keystop)||(!keystart)||(!zhengkong1)||kong1||ding_already1))		   //��ת����1���£��ڷ�ֹͣ������ת���Ƕ���״̬�£�
	  {
	   zhengkong1=1;
	   fankong1=0;

	   counter1=0;
	   hold1=0;
	   fanzhan1=1;
	   start_already1=0;
	   st_tm1a=1;
	   st_tm1b=1;
	   timer1a.sec=0;				 //��ʱ���ݡ���ʱ��־����
	   timer1a.hsec=0;
	   timer1b.sec=0;
	   timer1b.hsec=0;

      }
  }  

    

	if(!(clr||kong4))		//��λ����4������4��ʱ�����㡢������ֹͣ��������ʾˢ��
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


	 if(!(clr||kong3))		//��λ����3������3��ʱ�����㡢������ֹͣ��������ʾˢ��
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
	 

   if(!(clr||kong2))		  //��λ����2������2��ʱ�����㡢������ֹͣ��������ʾˢ��
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

   if(!(clr||kong1))		  //��λ����1������1��ʱ�����㡢������ֹͣ��������ʾˢ��
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

	if(!(dingdian1||ding_already1))		  //����1���ﶥ�㣬���1ֹͣ��ת
	  {
	   //zhengkong1=1;
	   fankong1=1; 
	   ding_already1=1;

	   hold1=0;
	   fanzhan1=0;
	   counter1=0;
	  } 

	if(dingdian1)						 //����1�뿪����
	 {
	 ding_already1=0;
	 }

	if(!(dingdian2||ding_already2))		 //����2���ﶥ�㣬���2ֹͣ��ת
	{
	   //zhengkong2=1;
	   fankong2=1;
	   ding_already2=1; 

	   hold2=0;
	   fanzhan2=0;
	   counter2=0;
	}
	if(dingdian2)					    //����2�뿪����
	{
	   ding_already2=0;
	}

   	if(!(dingdian3||ding_already3))		 //����3���ﶥ�㣬���3ֹͣ��ת
	{
	   //zhengkong3=1;
	   fankong3=1; 
	   ding_already3=1;

	   hold3=0;
	   fanzhan3=0;
	   counter3=0;
	}

	if(dingdian3)						//����3�뿪����
	{
	   ding_already3=0;
	}


  	if(!(dingdian4||ding_already4))		 //����4���ﶥ�㣬���4ֹͣ��ת
	{
	   //zhengkong3=1;
	   fankong4=1; 
	   ding_already4=1;

	   hold4=0;
	   fanzhan4=0;
	   counter4=0;
	}

	if(dingdian4)						//����4�뿪����
	{
	   ding_already4=0;
	}

	
	
}

void motor_control(void)
{
    
   	if(hold4)					   //����4����λ���֣����ж���ֹͣ
	    {   
   	         hold_already4=1;
			 counter4++;
			 if(counter4==20)	   //���4����ʱ��Ϊ2.0s&&&
			 {
			     fanzhan4=1;
				 hold4=0;
				 fan4_1s5=1;
				 counter4=0;
				 zhengkong4=1;
				 fankong4=0;
				 
			  }
         }

    if((!ding_already4)&&fan4_1s5)	 	 //���3��ת0.3s���ƣ���ת��־3Ϊ1���Ҳ��ڶ���3
         {   
   	         counter4++;
			 if(counter4==3)			 //���3��ת���ƣ�ʱ��Ϊ0.3s&&&
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


	if(hold3)					   //����3����λ���֣����ж���ֹͣ
	    {   
   	         hold_already3=1;
			 counter3++;
			 if(counter3==20)	   //���3����ʱ��Ϊ2.0s&&&
			 {
			     fanzhan3=1;
				 hold3=0;
				 fan3_1s5=1;
				 counter3=0;
				 zhengkong3=1;
				 fankong3=0;
				 
			  }
         }

    if((!ding_already3)&&fan3_1s5)	 	 //���3��ת0.3s���ƣ���ת��־3Ϊ1���Ҳ��ڶ���3
         {   
   	         counter3++;
			 if(counter3==3)			 //���3��ת���ƣ�ʱ��Ϊ0.3s&&&
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



		if(hold2)					   //����3����λ���֣����ж���ֹͣ
	    {   
   	         hold_already2=1;
			 counter2++;
			 if(counter2==20)	   //���3����ʱ��Ϊ2.0s&&&
			 {
			     fanzhan2=1;
				 hold2=0;
				 fan2_1s5=1;
				 counter2=0;
				 zhengkong2=1;
				 fankong2=0;
				 
			  }
         }

    if((!ding_already2)&&fan2_1s5)	 	 //���2��ת0.3s���ƣ���ת��־3Ϊ1���Ҳ��ڶ���3
         {   
   	         counter2++;
			 if(counter2==3)			 //���2��ת���ƣ�ʱ��Ϊ0.3s&&&
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


		if(hold1)					   //����3����λ���֣����ж���ֹͣ
	    {   
   	         hold_already1=1;
			 counter1++;
			 if(counter1==20)	   //���3����ʱ��Ϊ2.0s&&&
			 {
			     fanzhan1=1;
				 hold1=0;
				 fan1_1s5=1;
				 counter1=0;
				 zhengkong1=1;
				 fankong1=0;
				 
			  }
         }

    if((!ding_already1)&&fan1_1s5)	 	 //���1��ת0.3s���ƣ���ת��־3Ϊ1���Ҳ��ڶ���3
         {   
   	         counter1++;
			 if(counter1==3)			 //���1��ת���ƣ�ʱ��Ϊ0.3s&&&
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
