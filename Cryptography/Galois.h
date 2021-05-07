#pragma once
#include <stdint.h>
uint8_t GaloisMultiplication(uint8_t Num_L, uint8_t Num_R)
{
	/*
	* b7 ���� X~(100)
	�ж�b7�Ƿ�Ϊ0
	Ϊ0������һλ������X���൱��ֱ������
	Ϊ1������һλ����0x1B���
	*/

	//�������
	uint8_t Result = 0; //٤�������ڳ˷�����Ľ��

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

