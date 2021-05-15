#pragma once
#include <stdint.h>
uint8_t gfmultby_69(uint8_t Num_L_69, uint8_t Num_R_69)
{
	/*
	* b7 乘以 X~(100)
	判断b7是否为0
	为0：左移一位，乘以X，相当于直接左移
	为1：左移一位，与0x1B异或
	*/

	//定义变量
	uint8_t Result_69 = 0; //伽罗瓦域内乘法计算的结果

	while (Num_L_69)
	{
		if (Num_L_69 & 0x01)
		{
			Result_69 ^= Num_R_69;
		}
		Num_L_69 >>= 1;
		
		if (Num_R_69 & 0x80)
		{
			Num_R_69 <<= 1;
			Num_R_69 ^= 0x1B;
		}
		else
		{
			Num_R_69 <<= 1;
		}
	}
	return Result_69;
}

