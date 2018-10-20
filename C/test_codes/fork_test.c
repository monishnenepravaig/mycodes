#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

uint8_t counter=0;

void main()
{
	uint8_t check=1,i=0;
	uint8_t* ptr=&counter;
	for(i=0;i<10;i++)
	{	
		if(check!=0)
		{
			check=fork();
		}
		else
		{
			counter++;
		}		
	}
	
	printf("i=%d counter=%d ptr*=%d ptr=%ld\n",i,counter,*ptr,(size_t)ptr);
}
