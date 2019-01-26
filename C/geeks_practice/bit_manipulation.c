#define TESTCASES 8
//#define COUNT_TEST (0)
#define XOR_SUM (1)
//#define XOR_SWAP (0)
#include <stdint.h>
#include <stdio.h>

uint8_t count_of_1(uint32_t number)
{
	uint8_t count=0,i=0;
	for(i=0;i<32;i++)
	{
		if(number&1)
		{
			count++;
		}
		number=number>>1;
	}
	return count;
}

uint32_t xor_equals_sum(uint32_t number)
{
	printf("number=%x",number);
	uint32_t count=0,i=0,result=1,bit=1;
	while(number)
	{
		if(number%2==0)
		{
			count++;
		}
		number/=2;
	}
	printf(" count=%d\n",count);
	result=1<<count;
	return result;
}

void xor_swap(uint32_t* a,uint32_t* b)
{
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
	return;
}

void main()
{
	uint32_t samples[TESTCASES]={0xAAAA,0x5555,0xA5A5,0xC,0xFFFF,0x0,0xABCD,0x1234};
	uint32_t count=0,i=0;	
	for(i=0;i<TESTCASES;i++)
	{
		#ifdef COUNT_TEST
			count = count_of_1(samples[i]);
			printf("test case = %x and result = %d\n",samples[i],count);
		#endif
		#ifdef XOR_SWAP
			printf("number 1 = %x, number 2 =%x\n",samples[i],samples[i+1]);
			xor_swap(&samples[i],&samples[1+i]);
			i++;
			printf("number 1 = %x, number 2 =%x\n",samples[i-1],samples[i]);
		#endif
		#ifdef XOR_SUM
			count = xor_equals_sum(samples[i]);
			printf("test case = %x and result = %d\n",samples[i],count);
		#endif
	}	
}
