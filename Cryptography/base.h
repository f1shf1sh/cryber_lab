#pragma once
#include <stdint.h>
#include <string.h>

// 转为n进制函数
uint64_t* MessageProcess_69(uint64_t n_69,uint64_t m_69)
{
	uint64_t temp_69 = m_69, count_69 = 0;
	static uint64_t base_69[100] = { 100 };
	while (temp_69 > 0)
	{
		
		base_69[count_69++] = temp_69 % n_69;
		temp_69 /= n_69;
	}
	return base_69;
}

// 字符串分组函数
uint64_t* StrProcess_69(uint64_t n_69, char* m_69)
{
	uint32_t len_69 = 0;
	uint64_t* m_array_69;

	len_69 = strlen(m_69) / 8 + 1;
	m_array_69 = (uint64_t*)malloc(len_69 * sizeof(uint64_t));
	memset(m_array_69, 0, sizeof(uint64_t) * len_69);
	memcpy((char*)m_array_69, (char*)m_69, strlen(m_69));
	
	
	return m_array_69;
}