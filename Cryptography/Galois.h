#pragma once
#include <stdint.h>
uint8_t GaloisMultiplication(uint8_t Num_L, uint8_t Num_R)
{
	/*
	* b7 乘以 X~(100)
	判断b7是否为0
	为0：左移一位，乘以X，相当于直接左移
	为1：左移一位，与0x1B异或
	*/

	//定义变量
	uint8_t Result = 0; //伽罗瓦域内乘法计算的结果

	while (Num_L)
	{
		if (Num_L & 0x01)
		{
			Result ^= Num_R;
		}
		Num_L >>= 1;
		
		if (Num_R & 0x80)
		{
			Num_R <<= 1;
			Num_R ^= 0x1B;
		}
		else
		{
			Num_R <<= 1;
		}
	}
	return Result;
}

