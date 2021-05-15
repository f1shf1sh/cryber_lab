#pragma once
#include <stdint.h>
#include <string.h>
#include "AES_box.h"
#include "Galois.h"
#define N 4

void AddRoundKey_69(uint8_t(*State_69)[N], uint8_t RoundKey_69[N][N])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			State_69[j][i] ^= RoundKey_69[j][i];
		}
	}
}

void SubBytes_69(uint8_t (*State_69)[N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			State_69[i][j] = Sbox[(State_69[i][j] >> 4) & 0x0F][State_69[i][j] & 0x0F];
		}
	}
}

void ShiftRows_69(uint8_t (*State_69)[N])
{
	uint32_t shiftnum_69 = 0;
	uint8_t tmp_69;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < shiftnum_69; j++)		//循环左移一次	
		{
			tmp_69 = State_69[i][0];
			for (int k = 0; k < N - 1; k++)
			{
				State_69[i][k] = State_69[i][k + 1];
			}
			State_69[i][N - 1] = tmp_69;
		}
		shiftnum_69++;                       //移位次数+1
	}
}

void MixColumu_69(uint8_t(*State_69)[N])
{
	uint8_t MixArray_69[N][N] = {
		0x02, 0x03, 0x01, 0x01,
		0x01, 0x02, 0x03, 0x01,
		0x01, 0x01, 0x02, 0x03,
		0x03, 0x01, 0x01, 0x02
	};
	uint8_t TempMatrix_69[N][N];
	memcpy(TempMatrix_69, State_69, 16);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			State_69[i][j] = gfmultby_69(MixArray_69[i][0], TempMatrix_69[0][j]) ^
							 gfmultby_69(MixArray_69[i][1], TempMatrix_69[1][j]) ^
							 gfmultby_69(MixArray_69[i][2], TempMatrix_69[2][j]) ^
				             gfmultby_69(MixArray_69[i][3], TempMatrix_69[3][j]);
		}
	}
	
}


