#include <STC12C5A.h>
#include <absacc.h>
#include <intrins.h>
#include  <define.h>

sbit start_key1 = P0^0;
sbit start_key2 = P0^1;
sbit start_key3 = P0^2;
sbit start_key4 = P0^3;
sbit start_key5 = P0^4;
sbit start_key6 = P0^5;
sbit start_key7 = P0^6;
sbit start_key8 = P0^7;


sbit stop_key1 = P2^0;
//sbit stop_key2 = P2^1;
sbit stop_key2 = P3^5;
sbit stop_key3 = P2^2;
sbit stop_key4 = P2^3;
sbit stop_key5 = P2^4;
sbit stop_key6 = P2^5;
//sbit stop_key7 = P2^6;
sbit stop_key7 = P3^7;
sbit stop_key8 = P2^7;

sbit xoutput1 = P1^0;
sbit xoutput2 = P1^1;
sbit xoutput3 = P1^2;
sbit xoutput4 = P1^3;
sbit xoutput5 = P1^4;
sbit xoutput6 = P1^5;
sbit xoutput7 = P1^6;
sbit xoutput8 = P1^7;
	
unsigned  char bdata enable_timer;
sbit enable_timer1 = enable_timer^0;
sbit enable_timer2 = enable_timer^1;
sbit enable_timer3 = enable_timer^2;
sbit enable_timer4 = enable_timer^3;
sbit enable_timer5 = enable_timer^4;
sbit enable_timer6 = enable_timer^5;
sbit enable_timer7 = enable_timer^6;
sbit enable_timer8 = enable_timer^7;	

unsigned  char bdata enable_counter;
sbit enable_counter1 = enable_counter^0;
sbit enable_counter2 = enable_counter^1;
sbit enable_counter3 = enable_counter^2;
sbit enable_counter4 = enable_counter^3;
sbit enable_counter5 = enable_counter^4;
sbit enable_counter6 = enable_counter^5;
sbit enable_counter7 = enable_counter^6;
sbit enable_counter8 = enable_counter^7;
								
struct date
{
unsigned char hsec;
unsigned char sec;
}xtimer1,timer2,timer3,timer4,timer5,timer6,timer7,timer8;


unsigned char counter1_sec,counter2_sec,counter3_sec,counter4_sec,counter5_sec,counter6_sec,counter7_sec,counter8_sec;

void counter_init(void)
{
enable_timer1 = 0;
enable_timer2 = 0;
enable_timer3 = 0;
enable_timer4 = 0;
enable_timer5 = 0;
enable_timer6 = 0;
enable_timer7 = 0;
enable_timer8 = 0;

enable_counter1 = 0;
enable_counter2 = 0;
enable_counter3 = 0;
enable_counter4 = 0;
enable_counter5 = 0;
enable_counter6 = 0;
enable_counter7 = 0;
enable_counter8 = 0;

xtimer1.hsec = 0;
xtimer1.sec = 0;

timer2.hsec = 0;
timer2.sec = 0;

timer3.hsec = 0;
timer3.sec = 0;

timer4.hsec = 0;
timer4.sec = 0;

timer5.hsec = 0;
timer5.sec = 0;

timer6.hsec = 0;
timer6.sec = 0;

timer7.hsec = 0;
timer7.sec = 0;

timer8.hsec = 0;
timer8.sec = 0;

counter1_sec=0;
counter2_sec=0;
counter3_sec=0;
counter4_sec=0;
counter5_sec=0;
counter6_sec=0;
counter7_sec=0;
counter8_sec=0;

xoutput1 = 1;
xoutput2 = 1;
xoutput3 = 1;
xoutput4 = 1;
xoutput5 = 1;
xoutput6 = 1;
xoutput7 = 1;
xoutput8 = 1;

}


void key_scan(void)
{
//start key

	if(!start_key1){
		enable_timer1 = 1;
		xtimer1.hsec = 0;
		xtimer1.sec = 0;
		enable_counter1 = 1;
		counter1_sec = 0;
		xoutput1 = 0;
	}

	if(!start_key2){
		enable_timer2 = 1;
		timer2.hsec = 0;
		timer2.sec = 0;
		enable_counter2 = 1;
		counter2_sec = 0;
		xoutput2 = 0;
	}

	if(!start_key3){
		enable_timer3 = 1;
		timer3.hsec = 0;
		timer3.sec = 0;
		enable_counter3 = 1;
		counter3_sec = 0;
		xoutput3 = 0;
	}
	
	if(!start_key4){
		enable_timer4 = 1;
		timer4.hsec = 0;
		timer4.sec = 0;
		enable_counter4 = 1;
		counter4_sec = 0;
		xoutput4 = 0;
	}	

	if(!start_key5){
		enable_timer5 = 1;
		timer5.hsec = 0;
		timer5.sec = 0;
		enable_counter5 = 1;
		counter5_sec = 0;
		xoutput5 = 0;
	}

	if(!start_key6){
		enable_timer6 = 1;
		timer6.hsec = 0;
		timer6.sec = 0;
		enable_counter6 = 1;
		counter6_sec = 0;
		xoutput6 = 0;
	}

	if(!start_key7){
		enable_timer7 = 1;
		timer7.hsec = 0;
		timer7.sec = 0;
		enable_counter7 = 1;
		counter7_sec = 0;
		xoutput7 = 0;
	}
	
	if(!start_key8){
		enable_timer8 = 1;
		timer8.hsec = 0;
		timer8.sec = 0;
		enable_counter8 = 1;
		counter8_sec = 0;
		xoutput8 = 0;
	}

//stop key


	if(!stop_key1){
		enable_timer1 = 0;
	}

	if(!stop_key2){
		enable_timer2 = 0;
	}

	if(!stop_key3){
		enable_timer3 = 0;
	}

	if(!stop_key4){
		enable_timer4 = 0;
	}

	if(!stop_key5){
		enable_timer5 = 0;
	}

	if(!stop_key6){
		enable_timer6 = 0;
	}

	if(!stop_key7){
		enable_timer7 = 0;
	}

	if(!stop_key8){
		enable_timer8 = 0;
	}


}

