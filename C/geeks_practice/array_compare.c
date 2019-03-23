#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_LENGTH 100000

void main(void)
{	
	uint8_t a[ARRAY_LENGTH],b[ARRAY_LENGTH];
	uint32_t hash[256];
	srand(time(NULL));	
	uint32_t i = 0,score=0;
	for(i=0;i<256;i++)
	{
		hash[i]=0;
	}
	for(i=0;i<ARRAY_LENGTH;i++)
	{
		a[i]=rand()%256;
		b[i]=rand()%256;
	}
	for(i=0;i<ARRAY_LENGTH;i++)
	{
		if(a[i]==b[i])
		{
			score++;		
		}
	}
	for(i=0;i<ARRAY_LENGTH;i++)
	{
		hash[a[i]]++;	
	}
	for(i=0;i<ARRAY_LENGTH;i++)
	{
		if(hash[b[i]])
		{
			hash[b[i]]--;
			score++;
		}
	}
	printf("Score = %d\n",score);	
	#ifdef SMALL
	printf("Array A : ");		
	for(i=0;i<ARRAY_LENGTH;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Array B : ");
	for(i=0;i<ARRAY_LENGTH;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	#endif
}	
