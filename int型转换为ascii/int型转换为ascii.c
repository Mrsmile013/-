/*
  author：张颢文
  function：将int型value 变换为ascii格式 赋值给array数组，用于lcd显示。
            正数 正常输出，负数前面会加入ascii格式的"-"符号。
  input：
		value：需要变化的十进制值
		array：变换完成存入的数组
  output：
		array的数组指针
  data：2022.12.14
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*.h声明*/
unsigned char my_int_to_ascii(unsigned char *array,  int value);
/*.h声明*/



unsigned char my_int_to_ascii(unsigned char *array,  int value)
{
	unsigned char digits_lenth = 17;
	unsigned char i = 0;
	unsigned char j = 0;
	unsigned char  digits = 0;
	unsigned int temp ; 
	unsigned char flag = 0;
	temp = abs(value);//第一次赋值为计算输入值位数
	while (temp != 0)
	{
		temp = temp / 10;
		digits++;
	}
	temp = abs(value);//第二次赋值为后续计算
	if (value < 0)
	{
		*(array+i) = 45;//ascii减号
		i++;
		j = 1;//这里是为了负数 计算的统一性，为消除i++，后计算的不准确
	}
	for (i; i < digits+j; i++)
	{
		if (flag == 0)
		{
			flag = 1;
			*(array + i) = temp / (int)(pow(10, digits - i - 1 + j))  + 0x30;
		}
		else
		{
			
			*(array + i) = temp / (int)(pow(10, digits - i - 1 + j)) % 10 + 0x30;
		}
	}
	for (i; i < digits_lenth+j; i++)
	{
		*(array + i) = 0x00;//不同lcd 空格的代码不同，改这里即可
	}
	return *array;
}