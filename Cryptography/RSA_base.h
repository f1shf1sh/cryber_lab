#pragma once
#include <stdint.h>

// 平方乘计算
uint64_t LRFun_69_1(uint64_t m_69, uint64_t e_69, uint64_t n_69)
{
	uint8_t bit_69[32] = { 0 };
	uint64_t count_69 = 0, ret_69 = 1;

	printf("平方乘\n");
	while (e_69 != 0)
	{
		bit_69[count_69++] = e_69 & 0x1;
		e_69 >>= 1;
	}
	
	for (int i = count_69-1; i >= 0; i--)
	{
		if (!bit_69[i])
		{
			ret_69 *= ret_69;
		}
		else
		{
			ret_69 *= (ret_69 * m_69);
		}
		ret_69 %= n_69;
		printf("i=%d， n=%lld\n", i, ret_69);
	}
	return ret_69;
}

// 模重复平方计算
uint64_t LRFun_69_2(uint64_t c_69, uint64_t d_69, uint64_t n_69)
{
	uint64_t ret_69 = 1, temp_69 = c_69, count_69 = 0;
	uint32_t i = 0;
	uint64_t arr_69[100] = { 0 };

	// 防止溢出
	while (d_69 != 0)
	{
		temp_69 %= n_69;
		if (d_69 & 0x1)
		{
			arr_69[count_69++] = temp_69 % n_69;
		}
		temp_69 *= temp_69;
		d_69 >>= 1;
	}

	for (int i = 0; i < count_69; i++)
	{
		ret_69 *= arr_69[i];
		ret_69 %= n_69;
		printf("i=%d, n=%lld\n", i, ret_69);
	}
	return ret_69;
}