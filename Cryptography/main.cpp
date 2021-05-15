#include <stdlib.h>
#define N 4

#include <stdio.h>
#include <stdint.h>
#include "AES_base.h"
#include "calc.h"
#include "RSA_base.h"
#include "base.h"

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
void AES()
{
	// 32 43 F6 A8 88 5A 30 8D 31 31 98 A2 E0 37 07 34
	// 2B 7E 15 16 28 AE D2 A6 AB F7 15 88 09 CF 4F 3C
	uint8_t plain_69[N][N] = { 0 };
	uint8_t key_69[N][N] = { 0 };
	printf("明文：\n");
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%hhx", &plain_69[j][i]);
		}
	}
	printf("秘钥：\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%hhx", &key_69[j][i]);
		}
	}
	print("输入明文的状态矩阵：\n",plain_69);
	print("输入128位比特初始秘钥矩阵：\n",key_69);
	AddRoundKey_69(plain_69, key_69);
	print("轮秘钥加运算输出：\n", plain_69);
	SubBytes_69(plain_69);
	print("字节替代输出：\n", plain_69);
	ShiftRows_69(plain_69);
	print("行移位输出：\n", plain_69);
	MixColumu_69(plain_69);
	print("列混合输出：\n", plain_69);
}
void RSA()
{
	uint64_t e = 0, d = 0, n = 0, p = 0, q = 0, m = 0, c = 0;
	uint64_t* base, * m_array_69;
	uint64_t x = 0;
	char mm[100];
	printf("请顺序输入公钥，两素数（e,p,q）：");
	scanf("%lld%lld%lld", &e, &p, &q);
	n = p * q;
	printf("输出模数n: %lld\n", p * q);
	printf("输出模的欧拉函数: %lld\n", EulerFunc_69(p, q));
	d = invert_69(e, EulerFunc_69(p, q));
	printf("输出模数私钥: %lld\n", d);
	printf("请输入要加密的明文m: ");
	// scanf("%lld", &m);
	scanf("%s", mm);
	// printf("RSA加密模幂运算：底数，指数，模数：%lld %lld %lld\n", m, e, n);
	printf("RSA加密模幂运算：底数，指数，模数：%s %lld %lld\n", mm, e, n);
	// 获取n进制数组
	// base = MessageProcess_69(n, m);
	m_array_69 = StrProcess_69(n, mm);
	for (int j = 0; m_array_69[j] != 0; j++)
	{
		base = MessageProcess_69(n, m_array_69[j]);
		for (int i = 0; base[i] != 0; i++)
		{
			printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
			m = base[i];
			printf("RSA第%d组数据：底数，指数，模数：%lld %lld %lld\n", i, m, e, n);
			c = LRFun_69_1(m, e, n);
			printf("加密过后的密文为：%lld\n", c);
			printf("RSA解密模幂运算：底数，指数，模数：%lld %lld %lld\n", c, d, n);
			m = LRFun_69_2(c, d, n);
			printf("解密过后的明文：%lld\n", m);
			putchar('\n');
		}
		system("pause");
	}
}
int main()
{
	/// 需要解决的问题 m>n OK
	/// 字符串问题，没有解决
	// AES();
	RSA();
}

