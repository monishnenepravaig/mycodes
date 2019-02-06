#include <stdint.h>
#include <stdio.h>
#define TESTCASES 8
//#define COUNT_TEST (0)
//#define XOR_SUM (0)
//#define XOR_SWAP (0)
//#define SWAP_ODD_EVEN (0)
//#define MAGIC_NUMBER (0)
//#define SPARSE_NUMBER (0)
//#define BINARY_REPRESENTATION (1)
//#define BIT_ROTATION (1)
//#define FLIP_BIT_DIFF (1)
#define FLIP_BIT_DIFF_PAIRS (1)
#define RIGHT 9
#define LEFT 6

uint8_t count_of_1(uint8_t number)
{
	uint8_t count=0,i=0;
	for(i=0;i<8;i++)
	{
		if(number&1)
		{
			count++;
		}
		number=number>>1;
	}
	return count;
}

uint32_t magic_number(uint8_t n,uint8_t base)
{
	uint32_t pow=1,result=0;
	while(n)
	{
		pow=pow*base;
		if(n&1)
		{
			result+=pow;		
		}
		n>>=1;
	}
	return result;
}

uint32_t swap_odd_even(uint32_t number)
{
	uint32_t odd=0,even=0,result=0;
	uint32_t odd_mask=0xAAAA,even_mask=0x5555;
	odd = odd_mask & number;
	even = even_mask & number;
	even = even << 1;
	odd = odd >> 1;
	result = odd | even;
	return result;
}

uint8_t sparse_number(uint32_t number)
{
	uint8_t flag=0;
	while(number)
	{
		if(number&1)
		{
			if(flag)
			{
				return 0;
			}
			else
			{
				flag=1;
			}	
		}
		else
		{
			flag=0;
		}
		number>>=1;
	}
	return 1;
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

void binary_representation(uint32_t number,uint8_t* str)
{
	uint8_t i=0;
	for(i=0;i<32;i++)
	{
		*(str+i)='0';
	}
	*(str+i--)=0;
	while(number)
	{
		if(number&1)
		{
			*(str+i--)='1';
		}
		else
		{
			*(str+i--)='0';
		}		
		number>>=1;
	}
}

uint32_t bit_rotation(uint32_t number,uint8_t times,uint8_t direction)
{
	uint8_t i=0,bit_flag=0;
	uint32_t MSB_high = 0x80000000,MSB_low = 0x7FFFFFFF,LSB_low=0xFFFFFFFE,LSB_high=1;
	if(direction == RIGHT)
	{
		for(i=0;i<times;i++)
		{
			bit_flag=0;
			if(number&LSB_high)
			{
				bit_flag=1;
			}
			number>>=1;
			if(bit_flag)
			{
				number|=MSB_high;			
			}
			else
			{
				number&=MSB_low;	
			}
		}
	}
	else if(direction == LEFT)
	{
		for(i=0;i<times;i++)
		{
			bit_flag=0;
			if(number&MSB_high)
			{
				bit_flag=1;
			}
			number<<=1;
			if(bit_flag)
			{
				number|=LSB_high;			
			}
			else
			{
				number&=LSB_low;	
			}
		}
	}
	return number;
}

uint8_t flip_bit_diff(uint32_t a,uint32_t b)
{
	return count_of_1(a^b);
}

uint8_t selection_matrix(uint8_t r,uint8_t* matrix)
{
	uint16_t count=0,i=1;
	printf("matrix selection on\n");
	for(i=0;i<256;i++)
	{
		if(count_of_1(i)==r)
		{
			*(matrix+count++)=i;
		}
	}
	return count;
}

uint32_t flip_bit_diff_pairs(uint32_t* samples)
{
	uint8_t matrix[256];
	uint8_t count=0,i=0,j=0,pair_id=0;
	uint32_t pair[2],total=0;
	count=selection_matrix(2,matrix);
	printf("count=%d",count);
	for(i=0;i<count;i++)
	{
		j=0;
		pair_id=0;
		while(*(matrix+i))
		{
			if(*(matrix+i)&1)
			{
				pair[pair_id]=samples[j];
				*(matrix+i)>>=1;
			}
			j++;
		}
		total+=flip_bit_diff(pair[0],pair[1]);
	}
	return total;
}

void main()
{
	uint32_t samples[TESTCASES]={0xAAAAAAAA,0x55555555,0x5A5AA5A5,0x2468ACE,0x13579BDF,0xFFFFFFFF,0x89ABCDEF,0x12345678};
	uint32_t count=0,result=0,i=0;
	uint8_t str[32];	
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
		#ifdef SWAP_ODD_EVEN
			count = swap_odd_even(samples[i]);
			printf("test case = %x and result = %x\n",samples[i],count);
		#endif
		#ifdef MAGIC_NUMBER
			count = magic_number(i*i,i);
			printf("n = %d, base = %d and result = %d\n",i*i,i,count);
		#endif
		#ifdef SPARSE_NUMBER
			count = sparse_number(samples[i]);
			printf("test case = %x and result = %x\n",samples[i],count);
		#endif
		#ifdef BINARY_REPRESENTATION
			binary_representation(samples[i],str);
			printf("test case = %x and result = %s\n",samples[i],str);
		#endif
		#ifdef BIT_ROTATION
			count = count_of_1(samples[i]);
			result = bit_rotation(samples[i],count+1,LEFT);
			printf("number = %x, count = %d and result = %x\n",samples[i],count,result);
			result = bit_rotation(samples[i],count,RIGHT);
			printf("number = %x, count = %d and result = %x\n",samples[i],count,result);
		#endif
		#ifdef FLIP_BIT_DIFF
			result=flip_bit_diff(samples[i],samples[1+i]);
			i++;
			printf("number 1 = %x, number 2 =%x, difference =  %d\n",samples[i-1],samples[i],result);
		#endif
		#ifdef FLIP_BIT_DIFF_PAIRS
			result=flip_bit_diff_pairs(samples);
			printf("Total bit differences = %d",result);
		#endif
	}	
}
