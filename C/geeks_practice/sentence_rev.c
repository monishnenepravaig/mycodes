#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define SENTENCE_SIZE 50
#define SPACE 32

void main(void)
{
	uint8_t str[]="Check if this sentence gets reversed properly";
	uint8_t* rev=(uint8_t*)calloc(SENTENCE_SIZE,1);
	int32_t i=0,j=0,k=0;
	printf("org = %s\n",str);		
	for(i=0;*(str+i)!=0;i++);
	while(i>0)
	{
		for(;(*(str+i)!=SPACE)&&(i>0);i--);
		if(i==0)
		{
			i--;	
		}
		for(j=i+1;(*(str+j)!=SPACE)&&(*(str+j)!=0);j++)
		{
			*(rev+k++)=*(str+j);
		}
		i--;
		*(rev+k++)=SPACE;
	}
	*(rev+k++)=0;
	printf("rev = %s\n",rev);
}	
