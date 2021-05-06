#pragma once
#include <stdint.h>
uint8_t GaloisMultiplication(uint8_t Num_L, uint8_t Num_R)
{
	/*
	* b7 ���� X~(100)
	�ж�b7�Ƿ�Ϊ0
	Ϊ0������һλ������X
	Ϊ1������һλ����0x1B���
	*/

	//�������
	uint8_t Result = 0; //٤�������ڳ˷�����Ľ��

	while (Num_L)
	{
		// ���Num_L���λ��1�����Num_R���൱�ڼ���Num_R * 1
		if (Num_L & 0x01)
		{
			Result ^= Num_R;
		}

		//Num_L����һλ���൱�ڳ���2
		Num_L = Num_L >> 1;

		//���Num_R���λΪ1
		if (Num_R & 0x80)
		{
			// ����һλ
			Num_R = Num_R << 1; 
			Num_R ^= 0x1B; //����٤�������ڳ���Num_R = Num_R / (x^8(�պö�ʧ���λ) + x^4 + x^3 + x^1 + 1)
		}
		else
		{
			//����һλ�൱�ڳ˶�
			Num_R = Num_R << 1;
		}
	}
	return Result;
}


