/**********************************************************************************
  * @brief      : 	JZ2440v2开发板LCD绘制几何图像代码头文件
  * @version    : 	V0.0
  * @note       : 	无
  * @history    : 	无
***********************************************************************************/

#ifndef _GEOMETRY_H
#define _GEOMETRY_H

 /**********************************************************************************
  * @brief       : 	在LCD中指定位置绘制一个特定半径特定颜色的圆
  * @param[in]   : 	x	绘制的圆的x坐标
  					y	绘制的圆的y坐标
  					r	绘制的圆的半径
  					color	绘制的圆的颜色
  * @param[out]  : 	无
  * @return      : 	无
  * @others      : 	无
***********************************************************************************/
void DrawCircle(int x, int y, int r, int color);

/**********************************************************************************
  * @brief		 :	在LCD中绘制一条指定起始点的特定颜色的线条
  * @param[in]	 :	x1	   线条起点的x坐标
					y1	   线条起点的y坐标
					x2	   线条结束点的x坐标
					y2	   线条结束点的y坐标
					color  线条的颜色
  * @param[out]  :	无
  * @return 	 :	无
  * @others 	 :	无
***********************************************************************************/
void DrawLine(int x1,int y1,int x2,int y2,int color);

/**********************************************************************************
  * @brief		 :	绘制校准触摸屏所用的用来点击的十字架
  * @param[in]	 :	x  十字架的x坐标
					y  十字架的y坐标
					color  十字架的颜色
  * @param[out]  :	无
  * @return 	 :	无
  * @others 	 :	无
***********************************************************************************/
void FbDispCross(int x, int y, unsigned int color);

/********************************************************************************************
  * @brief		 :	在LCD的指定位置绘制一个指定大小，指定颜色的矩形
  * @param[in]	 :	x  矩形的x坐标
					y  矩形的y坐标
					color  矩形的颜色
  * @param[out]  :	无
  * @return 	 :	无
  * @others 	 :	无
*********************************************************************************************/
void DrawRectangle(int x,int y,int length,int high,int color);

#endif /* _GEOMETRY_H */

