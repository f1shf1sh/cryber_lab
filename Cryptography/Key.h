#pragma once
#include <stdlib.h>
#include "AES_box.h"
#include "AES_base.h"

void T(unsigned int k,int i)
{
	unsigned int Rcon[10] = { 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36 };
	unsigned char new_k[4];
	int N_k = 4;
	k = k << 8 | k >> 24;
	for (int i = 0; i < 4; i++)
	{
		new_k[i] = *((unsigned char*)(&k) + i);
		new_k[i] = Sbox[new_k[i] >> 4 & 0x0f][new_k[i] & 0xf];
	}
	
}

void KeyExpansion(unsigned char key[N][N], int round)
{
	
	unsigned char new_key[N][N];
	unsigned int k0[4], k1[4];
	for (int i = 0; i < 4; i++)
	{
		k0[i] = (unsigned int)key[i][0];
	}
	for (int i = 4; i < 4*(round+1); i++) // ×î¶à11ÂÖ
	{
		if (i % 4 == 0)
		{
			k0[i] = k0[i - 4] ^ T(k0[i - 1],i);
		}
		else
		{
			k0[i] = k0[i - 4] ^ k0[i - 1];
		}
	}
}