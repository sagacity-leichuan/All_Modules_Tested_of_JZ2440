#include "s3c2440_soc.h"
#include "interrupt.h"
#include "timer.h"
#include "string_utils.h"



#define TIMER_NUM  32

STimerDesc timer_array[TIMER_NUM];


int RegisterTimer(char *name, TimerFunc fp)
{
	int i;
	for (i = 0; i < TIMER_NUM; i++)
	{
		if (!timer_array[i].fp)
		{
			timer_array[i].name = name;
			timer_array[i].fp   = fp;
			return 0;
		}
	}
	return -1;
}

int UnregisterTimer(char *name)
{
	int i;
	for (i = 0; i < TIMER_NUM; i++)
	{
		if (!strcmp(timer_array[i].name, name))
		{
			timer_array[i].name = NULL;
			timer_array[i].fp   = NULL;
			return 0;
		}
	}
	return -1;
}

void TimerIrq(int irq)
{
	int i;
	for (i = 0; i < TIMER_NUM; i++)
	{
		if (timer_array[i].fp)
		{
			timer_array[i].fp();
		}
	}	
}

void InitTimer(void)
{
	/* 设置TIMER0的时钟 */
	/* Timer clk = PCLK / {prescaler value+1} / {divider value} 
	             = 50000000/(49+1)/16
	             = 62500
	 */
	TCFG0 = 49;  /* Prescaler 0 = 49, 用于timer0,1 */
	TCFG1 &= ~0xf;
	TCFG1 |= 3;  /* MUX0 : 1/16 */

	/* 设置TIMER0的初值 */
	TCNTB0 = 625;  /* 10Ms中断一次 */

	/* 加载初值, 启动timer0 */
	TCON |= (1<<1);   /* Update from TCNTB0 & TCMPB0 */

	/* 设置为自动加载并启动 */
	TCON &= ~(1<<1);
	TCON |= (1<<0) | (1<<3);  /* bit0: start, bit3: auto reload */

	/* 设置中断 */
	RegisterIrq(10, TimerIrq);
}


