/*
* ESD_Project.c
 *
 *  Created on: mar 1 , 2018
 *      Author: monish
 */

#include <stdio.h>
#include <stdint.h>
#include "ESD_Project.h"

Buffer_status buffer_create(void)
{
	uint16_t buffer_size=0;
	uint8_t i=0,error_check=0;
	my_printf(size_buffer_txt_0);
	print_number(buffer_number);
	while(error_check==0)
	{
		if(buffer_number<2)
		{
			my_printf(size_buffer_txt_1_initial);
			//buffer_size = fetch_number();
			scanf("%hd",&buffer_size);
			if((buffer_size<32)||(buffer_size>2800)||(buffer_size%16!=0))
			{
				my_printf(invalid_number_txt);	
			}		
			else 
			{
				error_check=1;			
			}
		}
		else
		{
			my_printf(size_buffer_txt_1_later);
			//buffer_size = fetch_number();
			scanf("%hd",&buffer_size);
			if((buffer_size<20)||(buffer_size>400))
			{
				my_printf(invalid_number_txt);	
			}		
			else 
			{
				error_check=1;			
			}
		}
	}
	i = buffer_init(&buffer_storage[buffer_number],buffer_size);
	buffer_storage[buffer_number].start = buffer_storage[buffer_number].buffptr;
	buffer_storage[buffer_number].end = buffer_storage[buffer_number].buffptr + buffer_size;
	buffer_storage[buffer_number].count = 0;
	buffer_storage[buffer_number].length = buffer_size;
	buffer_storage[buffer_number].buffer_id = buffer_number;
	if(buffer_number>max_buffers_created)
	{
		max_buffers_created=buffer_number;
	}
	if(i ==  Null_Error)
	{
		my_printf(buffer_allocation_failed_txt);
		putchar('0'+ buffer_number);
	}
	else
	{
		my_printf(buffer_created_txt);
		print_number(buffer_number);
		my_printf(with_txt);
		print_number(buffer_size);
		my_printf(bytes_txt);
		buffer_number++;	
	}
	return i;
}

Buffer_status buffer_delete(uint8_t buffer_number)
{
	uint8_t i;
	i = buffer_destroy(&buffer_storage[buffer_number]);
	my_printf(buffer_deleted_txt);
	print_number(buffer_number);
	return i;
}

void my_printf(uint8_t* text_ptr)
{
	uint8_t i=0;
	while(*(text_ptr+i)!='\0')	
	{
		putchar(*(text_ptr+i));
		i++;
	}
	return;
}

void print_number(uint32_t number)
{
	uint8_t temp_ascii_store[10];
	int8_t counter=0;
	do
	{
		temp_ascii_store[counter]='0'+number%10;
		number/=10;
		counter++;
	}while(number>0);
	for(counter-=1;counter>=0;counter--)
	{
		putchar(temp_ascii_store[counter]);
	}
	return;
}

uint16_t fetch_number(void)
{
	uint8_t scanned_digit=0;
	uint16_t number=0;
	while(1)
	{
		scanned_digit=getchar();
		if((scanned_digit > '0') && (scanned_digit < '9'))
		{
			number+= scanned_digit - '0';
			number*= 10;	
		}
		else if (scanned_digit=='9')
		{
			return number;		
		}
		else 
		{
			return 0;
		}		
	}
}

int main(void)
{
	//initialisation
	uint8_t key_pressed=0,exit_code=0;
	Buffer_status error_check = 0;
	//infinite_loop3
	while(1)
	{
		my_printf(Welcome_txt);
		do
		{		
		error_check = buffer_create();	
		if(error_check == Null_Error)
		{
			continue;
		}
		error_check = buffer_create();
		if(error_check ==  Success)
		{
			exit_code=1;
		}
		}while(exit_code==0);
		exit_code=0;
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
				{
					do
					{
						buffer_structure_ptr = &buffer_storage[buffer_number];
						if((buffer_structure_ptr->buffptr != NULL))
						{
							buffer_number = max_buffers_created + 1;
						}
						error_check = buffer_create();
						if(error_check ==  Success)
						{
							exit_code=1;
						}
					}while(exit_code==0);
					exit_code=0;
					break;
				}

				case '-':
				{
					my_printf(buffer_delete_number_txt);
					//buffer_size = fetch_number();
					do
					{					
						scanf("%hhd",&buffer_number);
						buffer_structure_ptr = &buffer_storage[buffer_number];
						if((buffer_structure_ptr->buffptr != NULL)&&(buffer_number != 0))
						{
							error_check = buffer_delete(buffer_number);
						}
						else
						{
							my_printf(invalid_number_txt);
							error_check = fail;			
						}
						if(error_check ==  Success)
						{
							exit_code=1;
						}
					}while(exit_code==0);
					exit_code=0;	
					break;
				}

				case '@':
				{
					buffer_number = max_buffers_created;
					do
					{
						buffer_number--;
						buffer_structure_ptr = &buffer_storage[buffer_number];
						if(buffer_structure_ptr->buffptr != NULL)
						{
							error_check = buffer_delete(buffer_number);
						}		
					}
					while(buffer_number!=0);
					max_buffers_created = 0;
					exit_code=1;
					break;
				}
							
				default:
				break;					
			}
			key_pressed=0;
		}while(exit_code==0);
		exit_code=0;
	}
	return Success;
}

