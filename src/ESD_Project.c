/*
* ESD_Project.c
 *
 *  Created on: mar 1 , 2018
 *      Author: monish
 */

#include <stdio.h>
#include <stdint.h>
#include "ESD_Buffer_Handling.h"

uint32_t buffer_pointer_storage[20];

Buffer_status buffer_create(uint8_t buffer_number,uint16_t size)
{
	uint8_t i;
	buffer_typedef buffer;
	i = buffer_init(&buffer_new,size);
	buffer.start = buffer.buffptr;
	buffer.end = buffer.buffptr + size;
	buffer.count = 0;
	buffer.length = size;
	buferr.buffer_id=buffer_number;
	buffer_pointer_storage[buffer_number]=(uint32_t)buffer.buffptr;
	return i;
}

Buffer_status buffer_delete(uint8_t buffer_number)
{
	uint8_t i;
	buffer_typedef* buffer_ptr = (buffer_typedef*) buffer_pointer_storage[buffer_number];
	i = buffer_destroy(buffer_ptr);
	return i;
}

void main(void)
{
	//initialisation
	uint8_t key_pressed=0,exit_code==0;
	//infinite_loop
	while(1)
	{
		do
		{
			key_pressed=getchar();
			switch(key_pressed)
			{
				case '=':
				break;

				case '?':
				break;

				case '+':
				break;

				case '-':
				break;

				case '@':
				exit_code=1;
				break;
							
				default:
				break;					
			}
			key_pressed=0;
		}while(exit_code==1);
		
		exit_code==0;
	}
}

