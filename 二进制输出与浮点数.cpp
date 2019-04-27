#include "stdafx.h"
/*
从某个地址（该地址的数据是char型）开始，打印出length个字符出来
*/
void print_bin(unsigned char * T_byte, int length)
{
	int i, j;
	unsigned char temp;

	printf("\nmemory print  (bin)%d：", length);
	for (i = 0; i<length; i++)
	{
		temp = *(T_byte + length - 1);
		for (j = 0; j<8; j++)
		{
			if (j == 4)
			{
				printf("_");
			}
			if (temp & 0x80)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
			temp = temp << 1;
		}
		printf(" ");
		T_byte--;
	}
	return;
}
/*
从某个地址（该地址的数据是char型）开始，打印出length个字节内的二进制数
*/
void print_bytes(unsigned char * T_byte, int length)
{
	int i;

	printf("\nmemory print (byte)%d：", length);
	for (i = 0; i<length; i++)
	{
		printf(" %02X", (unsigned char)*(T_byte + length - 1));
		T_byte--;
	}
	/*printf("\n");*/
	return;
}
	typedef struct float_type_stuct_def
	{
		int frac : 23;
		int exp:8;
		int s:1;
	};

	typedef union  float_type_union_def
	{
		float_type_stuct_def comb;
		float float_comb;
	};
int main()
{

	float_type_union_def FP_test;
	FP_test.comb.frac = 1;//0
	FP_test.comb.exp = 1;                       //1
	FP_test.comb.s = -1;
	float float_a =  FP_test.float_comb;
	printf("\nfloat_a = %e", float_a);
	print_bytes((unsigned char *)&(float_a), sizeof(float));
	print_bin((unsigned char *)&(float_a), sizeof(float));
	printf("\n");

	FP_test.comb.frac = 0b11111111111111111111111;//0
	FP_test.comb.exp = 254;                       //1
	FP_test.comb.s = -1;
	float float_b = FP_test.float_comb;
	printf("\nfloat_b= %e", float_b);
	print_bytes((unsigned char *)&(float_b), sizeof(float));
	print_bin((unsigned char *)&(float_b), sizeof(float));
	printf("\n");

	float float_c = 0.0;
	printf("\nfloat_c= %0.9f", float_c);
	print_bytes((unsigned char *)&(float_c), sizeof(float));
	print_bin((unsigned char *)&(float_c), sizeof(float));
	printf("\n");

	FP_test.comb.frac = 0b11111111111111111111111;//0
	FP_test.comb.exp = 255;                       //1
	FP_test.comb.s = -1;
	float float_d = FP_test.float_comb;
	printf("\nfloat_d= %e", float_d);
	print_bytes((unsigned char *)&(float_d), sizeof(float));
	print_bin((unsigned char *)&(float_d), sizeof(float));
	printf("\n");

	float float_e = 5.0;
	printf("\nfloat_e= %0.9f", float_e);
	print_bytes((unsigned char *)&(float_e), sizeof(float));
	print_bin((unsigned char *)&(float_e), sizeof(float));
	printf("\n");

	printf("\n先将float_e转成unsignd，再打印");
	unsigned uint_a = (unsigned)float_e;
    print_bytes((unsigned char *)&(uint_a), sizeof(unsigned));
	print_bin((unsigned char *)&(uint_a), sizeof(unsigned));

	printf("\n");


	getchar();
	return 0;
}
