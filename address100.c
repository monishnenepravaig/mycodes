/*
 * address100+.c
 *
 *  Created on: Sep 21, 2017
 *      Author: monish.
 */


#include <stdio.h>

void modify(char* ptr)
{	int temp;
	char* ptr1 = ptr;
	temp= 0xF1 & 127;
	*ptr=temp;
	ptr++;
	*ptr += 17;
	ptr += 2;
	*ptr = 15 % 4;
	ptr--;
	*ptr >>= 4;
	ptr = (char*)(ptr1+5);
	*ptr = (1<<5)|(4<<2);
	*((char*)(ptr1+7)) = 22;
	ptr=ptr1;
	return;
}

void main()
{
    int index;
    unsigned char arr[8], arroriginal[8]={0xEE,0x12,0x77,0xBE,0x66,0x54,0x33,0xf0};
    for(index=0;index<8;index++)
    {
    arr[index] = arroriginal[index];
    }
  	unsigned char * ptr = arr;
  	modify(&arr);
	for(index=0;index<8;index++)
	{
	    printf("Addr: %d \t %x \t %x \n", (100+index), arroriginal[index],*ptr++);
	}
}
