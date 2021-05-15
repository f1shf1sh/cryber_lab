#pragma once
#include <stdint.h>

uint64_t EulerFunc_69(uint64_t p_69, uint64_t q_69)
{
	return (p_69 - 1) * (q_69 - 1);
}

uint64_t gcd(uint64_t x, uint64_t y)
{
	uint64_t result = 1;
	if (x > y)
	{
		result = gcd(y, x % y);
	}
	else
	{
		result = gcd(x, y % x);
	}
	
	return result;
}



// x - y == 1
uint64_t ex_gcd_69(uint64_t e_69, uint64_t n_69, uint64_t* x_69, uint64_t* y_69)
{
	
	if (e_69 == 0) // 说明上一层e等于1
	{
		*x_69 = 1;
		*y_69 = 0;
		return n_69;
	}
	uint64_t result_69 = ex_gcd_69(n_69 % e_69, e_69, y_69, x_69);
	*y_69 -= (n_69 / e_69) * (*x_69);

	return result_69;
}

uint64_t invert_69(uint64_t e_69, uint64_t n_69)
{
	uint64_t x_69, y_69;
	uint8_t check_69 = ex_gcd_69(e_69, n_69, &x_69, &y_69);
	if (check_69 == 1)
	{

		return (y_69 % n_69 + n_69) % n_69;
	}
	else
	{
		return -1;
	}
}

