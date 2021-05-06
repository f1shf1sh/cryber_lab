#pragma once
#include <stdint.h>
uint8_t GaloisMultiplication(uint8_t Num_L, uint8_t Num_R)
{
	/*
	* b7 乘以 X~(100)
	判断b7是否为0
	为0：左移一位，乘以X
	为1：左移一位，与0x1B异或
	*/

	//定义变量
	uint8_t Result = 0; //伽罗瓦域内乘法计算的结果

	while (Num_L)
	{
		// 如果Num_L最低位是1就异或Num_R，相当于加上Num_R * 1
		if (Num_L & 0x01)
		{
			Result ^= Num_R;
		}

		//Num_L右移一位，相当于除以2
		Num_L = Num_L >> 1;

		//如果Num_R最高位为1
		if (Num_R & 0x80)
		{
			// 左移一位
			Num_R = Num_R << 1; 
			Num_R ^= 0x1B; //计算伽罗瓦域内除法Num_R = Num_R / (x^8(刚好丢失最高位) + x^4 + x^3 + x^1 + 1)
		}
		else
		{
			//左移一位相当于乘二
			Num_R = Num_R << 1;
		}
	}
	return Result;
}


