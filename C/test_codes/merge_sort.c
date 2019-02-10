#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#define True 1
#define False 0
 

void merge_sort(int32_t count,int32_t* data)
{
    int32_t temp=0,middle=count/2,i=0,j=0,temp_counter=0;
    int32_t* temp_ptr = (int32_t*)malloc(count*4);
    if((count==1)||(count==0))
    {
        return;
    }
    if(count==2)
    {
        if(*(data) < *(data+1))
        {
            temp=*(data);
            *(data)=*(data+1);
            *(data+1)=temp;
        }
        return;
    }
    merge_sort(middle,data);
    merge_sort(count-middle,data+middle);
    j=middle;
    while(temp_counter<count)
    {
	if(j>=count)
	{
		*(temp_ptr+temp_counter++)=*(data+i);
		i++;
	}
	else if(i>=middle)
	{
		*(temp_ptr+temp_counter++)=*(data+j);
		j++;
	}
	else if((*(data+i)>*(data+j)))
	{
		*(temp_ptr+temp_counter++)=*(data+i);
		i++;
	}
	else
	{
		*(temp_ptr+temp_counter++)=*(data+j);
		j++;
	}
    }
    temp_counter=0;
    while(temp_counter<count)
    {
	*(data+temp_counter)=*(temp_ptr+temp_counter);
    	temp_counter++;
    }
    free(temp_ptr);
    return;
}

void main()
{
	uint32_t i=0;
	int32_t data[256];
	srand(time(NULL));
	for(i=0;i<256;i++)
	{
		data[i]=rand();
	}
	merge_sort(256,data);
	for(i=0;i<256;i++)
	{
		printf("%d\n",data[i]);
	}
}
