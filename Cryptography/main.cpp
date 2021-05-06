#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "AES_base.h"
#define N 4

void print(const char* str, uint8_t(*state)[4])
{
	printf("%s", str);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%.2X ", state[i][j]);
		} 
		putchar('\n');
	}
}

int main()
{
	// 32 43 F6 A8 88 5A 30 8D 31 31 98 A2 E0 37 07 34
	// 2B 7E 15 16 28 AE D2 A6 AB F7 15 88 09 CF 4F 3C
	uint8_t plain[N][N] = { 0 };
	uint8_t key[N][N] = { 0 };
	printf("input1: \n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%hhx", &plain[j][i]);
		}
	}
	printf("input2: \n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%hhx", &key[j][i]);
		}
	}
	
	AddRoundKey(plain, key);
	print("AddRoundKey\n", plain);
	SubBytes(plain);
	print("SubBytes\n", plain);
	ShiftRows(plain);
	print("ShiftRows\n", plain);
	MixColumu(plain);
	print("MixColumu\n", plain);
	return 0;
}

