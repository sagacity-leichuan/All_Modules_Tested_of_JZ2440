/**********************************************************************************
  * @brief      : 	JZ2440v2开发板中断代码源文件
  * @version    : 	V0.0
  * @note       : 	无
  * @history    : 	无
***********************************************************************************/

#include "s3c2440_soc.h"
#include "interrupt.h"

IrqFunc g_fIrqArray[32];    //各个中断处理函数的函数数组


/**********************************************************************************
  * @brief       : 	JZ2440v2开发板中断处理总函数
  * @param[in]   : 	无
  * @param[out]  : 	无
  * @return      : 	无
  * @others      : 	无
***********************************************************************************/
void HandleIrqC(void)
{
	/* 分辨中断源 */
	int bit = INTOFFSET;

	g_fIrqArray[bit](bit);
	
	/* 清中断 : 从源头开始清 */
	SRCPND = (1<<bit);
	INTPND = (1<<bit);	
}

/**********************************************************************************
  * @brief       : 	JZ2440v2开发板中断函数处理函数
  * @param[in]   : 	irp	待注册的中断函数的中断号
  					fp	待注册的中断函数的函数指针
  * @param[out]  : 	无
  * @return      : 	无
  * @others      : 	无
***********************************************************************************/
void RegisterIrq(int irq, IrqFunc fp)
{
	g_fIrqArray[irq] = fp;

	INTMSK &= ~(1<<irq);
}

