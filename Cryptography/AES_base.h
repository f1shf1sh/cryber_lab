#pragma once
#include <stdint.h>
#include <string.h>
#include "AES_box.h"
#include "Galois.h"
#define N 4

void AddRoundKey(uint8_t(*State)[N], uint8_t RoundKey[N][N])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			State[j][i] ^= RoundKey[j][i];
		}
	}
}

void SubBytes(uint8_t (*State)[N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			State[i][j] = Sbox[(State[i][j] >> 4) & 0x0F][State[i][j] & 0x0F];
		}
	}
}

void ShiftRows(uint8_t (*State)[N])
{
	uint32_t shiftnum = 0;
	uint8_t tmp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < shiftnum; j++)		//循环左移一次	
		{
			tmp = State[i][0];
			for (int k = 0; k < N - 1; k++)
			{
				State[i][k] = State[i][k + 1];
			}
			State[i][N - 1] = tmp;
		}
		shiftnum++;                       //移位次数+1
	}
}

void MixColumu(uint8_t(*State)[N])
{
	uint8_t MixArray[N][N] = {
		0x02, 0x03, 0x01, 0x01,
		0x01, 0x02, 0x03, 0x01,
		0x01, 0x01, 0x02, 0x03,
		0x03, 0x01, 0x01, 0x02
	};
	uint8_t TempMatrix[4][4];
	memcpy(TempMatrix, State, 16);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			State[i][j] = GaloisMultiplication(MixArray[i][0], TempMatrix[0][j]) ^
						  GaloisMultiplication(MixArray[i][1], TempMatrix[1][j]) ^
						  GaloisMultiplication(MixArray[i][2], TempMatrix[2][j]) ^
						  GaloisMultiplication(MixArray[i][3], TempMatrix[3][j]);
		}
	}
	
}


