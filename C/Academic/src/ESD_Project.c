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
	uint8_t i=0;
	Buffer_status error_check = 0;
	my_printf(size_buffer_txt_0);
	print_number(buffer_number);
	while(error_check==0)
	{
		if(buffer_number<2)
		{
			my_printf(size_buffer_txt_1_initial);
			//buffer_size = fetch_number();
			scanf("%hd",&buffer_size);
			if((buffer_size<32)||(buffer_size>3200)||(buffer_size%32!=0))
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
	Buffer_status error_check = 0;
	error_check = buffer_destroy(&buffer_storage[buffer_number]);
	if(error_check==Success)
	{
		my_printf(buffer_deleted_txt);
		print_number(buffer_number);
	}
	return error_check;
}

Buffer_status buffer_flush(uint8_t buffer_number)
{
	Buffer_status error_check = 0;
	uint8_t temp_storage=0;
	buffer_structure_ptr = &buffer_storage[buffer_number];
	uint8_t* buffer_temp_ptr = buffer_structure_ptr->buffptr;
	buffer_structure_ptr->buffptr = buffer_structure_ptr->start;
	do
	{
		error_check=buffer_remove_item(&buffer_storage[buffer_number],&temp_storage);
		putchar(temp_storage);
	}while(error_check!=Buffer_Empty);
 	buffer_structure_ptr->buffptr = buffer_temp_ptr;
	return error_check;
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
		my_printf(buffer_instructions_txt);
		do
		{
			key_pressed=getchar();
			characters_count++;
			switch(key_pressed)
			{
				case '=':
				{
					 buffer_flush(0);
				}
				break;

				case '?':
				{
					buffer_number = max_buffers_created+1;
					do
					{
						buffer_number--;
						buffer_structure_ptr = &buffer_storage[buffer_number];
						if(buffer_structure_ptr->buffptr != NULL)
						{
							my_printf(buffer_number_txt);
							print_number(buffer_number);
							my_printf(buffer_start_address_txt);
							//print_number();
							my_printf(buffer_end_address_txt);
							//print_number();
							my_printf(buffer_size_txt);
							print_number(buffer_storage[buffer_number].length);
							my_printf(bytes_txt);
							my_printf(buffer_used_txt);
							print_number(buffer_storage[buffer_number].count);
							my_printf(bytes_txt);
							my_printf(buffer_unused_txt);
							print_number(buffer_storage[buffer_number].length-buffer_storage[buffer_number].count);
							my_printf(bytes_txt);
						}		
					}while(buffer_number!=0);
					my_printf(buffer_query_txt);
					print_number(characters_count);
					characters_count=0;
					break;
				}

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
					}while(error_check !=  Success);
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
					}while(error_check !=  Success);
					break;
				}

				case '@':
				{
					buffer_number = max_buffers_created+1;
					do
					{
						buffer_number--;
						buffer_structure_ptr = &buffer_storage[buffer_number];
						if(buffer_structure_ptr->buffptr != NULL)
						{
							error_check = buffer_delete(buffer_number);
						}		
					}while(buffer_number!=0);
					max_buffers_created = 0;
					exit_code=1;
					break;
				}	
							
				default:
				{
					if ((key_pressed>='A')&&(key_pressed<='Z'))
					{
						putchar(key_pressed);
						error_check = buffer_add_item(&buffer_storage[0],key_pressed);
						if(error_check==Buffer_Full)
						{
							my_printf(buffer_txt);
							print_number(0);
							my_printf(full_txt);
						}
					}
				}
				break;					
			}
			key_pressed=0;
		}while(exit_code==0);
		exit_code=0;
	}
	return Success;
}

