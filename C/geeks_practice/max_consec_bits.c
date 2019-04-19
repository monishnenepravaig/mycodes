#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#define TESTRUNS 1000

uint32_t success=0,failure=0;

uint8_t max_consec_1_counter(uint32_t number)
{
	uint8_t count=0,max=0;
	while(number)
	{
		if(number&1)
		{
			count++;
			max=count>max?count:max;		
		}
		else
		{
			count=0;
		}
		number>>=1;
	}
	return max;
}

uint8_t smart_counter(uint32_t number,uint8_t index)
{
	int8_t i=1;
	uint8_t total=1;
	uint32_t temp=number;
	while((temp&(1<<(index+i++)))&&(index+i<32))
	{
		total++;
	}
	i=-1;
	while(temp&(1<<(index+i--)))
	{
		total++;
	}
	return total;
}

uint8_t max_consec_1_swapper(uint32_t number)
{
	uint8_t i=0,count=0,max=0,max_index=0,verify=0;
	for(i=0;i<32;i++)
	{
		if(!(number&(1<<i)))
		{
			count=smart_counter(number|(1<<i),i);
			if(count>max)
			{
				max=count;
				max_index=i;			
			}		
		}
	}
	verify=max_consec_1_counter(number|(1<<max_index));
	if(verify==max)
	{
		//printf("max_index=%d Verified\n",max_index);
		success++;	
	}
	else
	{
		//printf("max_index=%d Error\n",max_index);
		failure++;
	}
	return max;
}

void main(void)
{	
	uint32_t i=0;
	srand(time(NULL));	
	uint32_t random = 0;
	for(i=0;i<TESTRUNS;i++)
	{
		random=rand();
		max_consec_1_swapper(random);		
		//printf("Number:%x, Max_consec_1 = %d\n",random,max_consec_1_swapper(random));
	}
	printf("Success=%d, Failure=%d\n",success,failure);
}	
