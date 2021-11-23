#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#define DATA_SIZE 256
#define True 1
#define False 0

void print_data(uint8_t* data, uint32_t size)
{
    int32_t i=0;
    for(i=0;i<size;i++)
    {
        printf("%d ",*(data+i));
    }
}

void main()
{
	uint32_t i=0;
	uint8_t* data=(uint8_t*)malloc(DATA_SIZE);
	srand(time(NULL));
	for(i=0;i<DATA_SIZE;i++)
	{
		data[i]=rand();
	}
	//sort the data here
	print_data(data,DATA_SIZE);
}
