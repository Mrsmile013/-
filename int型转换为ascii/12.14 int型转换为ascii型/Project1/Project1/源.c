#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned char my_int_to_ascii(unsigned char *array, int value);

void main(void)
{
	unsigned int fuck;
	unsigned char mynum[17];
	unsigned char mynum2[17];
	fuck = 301;
	my_int_to_ascii(mynum, fuck);
	memcpy(mynum2, mynum, 17);
	while (1);
}
/*
  author�������
  function����int��value �任Ϊascii��ʽ ��ֵ��array���飬����lcd��ʾ��
            ���� �������������ǰ������ascii��ʽ��"-"���š�
  input��
		value����Ҫ�仯��ʮ����ֵ
		array���任��ɴ��������
  output��
		array������ָ��
  data��2022.12.14
*/
unsigned char my_int_to_ascii(unsigned char *array,  int value)
{
	unsigned char digits_lenth = 17;
	unsigned char i = 0;
	unsigned char j = 0;
	unsigned char  digits = 0;
	unsigned int temp ; 
	unsigned char flag = 0;
	temp = abs(value);//��һ�θ�ֵΪ��������ֵλ��
	while (temp != 0)
	{
		temp = temp / 10;
		digits++;
	}
	temp = abs(value);//�ڶ��θ�ֵΪ��������
	if (value < 0)
	{
		*(array+i) = 45;//ascii����
		i++;
		j = 1;//������Ϊ�˸��� �����ͳһ�ԣ�Ϊ����i++�������Ĳ�׼ȷ
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
		*(array + i) = 0x00;//��ͬlcd �ո�Ĵ��벻ͬ�������Ｔ��
	}
	return *array;
}