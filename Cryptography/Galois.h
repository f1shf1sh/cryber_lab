#pragma once
#include <stdint.h>
uint8_t gfmultby_69(uint8_t Num_L_69, uint8_t Num_R_69)
{
	/*
	* b7 ���� X~(100)
	�ж�b7�Ƿ�Ϊ0
	Ϊ0������һλ������X���൱��ֱ������
	Ϊ1������һλ����0x1B���
	*/

	//�������
	uint8_t Result_69 = 0; //٤�������ڳ˷�����Ľ��

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

