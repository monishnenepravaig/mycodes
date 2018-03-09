/*
* ESD_Project.c
 *
 *  Created on: mar 1 , 2018
 *      Author: monish
 */

#include "main.h"
#define HEAP_SIZE (0x4000)   // size must be smaller than available XRAM
void xdata* heap;

_sdcc_external_startup()
{

return 0;
}


/***********************************************************************
 * @brief buffer_init()
 * This function allocates memory using malloc for buffer
 * @param (buffer)* cbptr pointer to buffer struct
 * @param length length of the buffer
 * @return error in form of enum defined in main.h
 ***********************************************************************/
Buffer_status buffer_init(buffer_typedef* cbptr, __xdata uint16_t length)
{
	(cbptr->buffptr) = (uint8_t*)malloc(length);
	if(cbptr->buffptr == NULL)
	{
		return Null_Error;
	}
	else
	{
		return Success;
	}
}

/***********************************************************************
 * @brief buffer_add_item()
 * This function adds an item to buffer
 * @param (buffer)* cbptr pointer to buffer struct
 * @param data value to be stored in buffer
 * @return error in form of enum defined in main.h
 ***********************************************************************/
Buffer_status buffer_add_item(buffer_typedef* cbptr,__xdata uint8_t data1)
{
	__xdata uint8_t i = buffer_end_reached(cbptr);
	if(i == Buffer_Full)
		{return Buffer_Full;}
	else
	{
		(cbptr->count)++;
		*(cbptr->buffptr) = data1;
		cbptr->buffptr++;
		return Success;
	}
}


/***********************************************************************
 * @brief buffer_remove_item()
 * This function removes an item from buffer and stores it
 * @param (buffer)* cbptr pointer to buffer struct
 * @param store pointer to the location where the data is supposed to be stored
 * @return error in form of enum defined in main.h
 ***********************************************************************/
Buffer_status buffer_remove_item(buffer_typedef* cbptr, uint8_t* store)
{
	uint8_t i=buffer_end_reached(cbptr);
	if(i == Buffer_Full)
		{return Buffer_Empty;}
	else
	{
		//(cbptr->count)--;
		*store=*(cbptr->buffptr);
		cbptr->buffptr++;
		return Success;
	}
}

/***********************************************************************
 * @brief buffer_end_reached()
 * This function checks if buffer is full
 * @param (buffer)* cbptr pointer to buffer struct
 * @return error in form of enum defined in main.h
 ***********************************************************************/
Buffer_status buffer_end_reached(buffer_typedef* cbptr)
	{
	if((cbptr->buffptr)==(cbptr->end)+1)
		return Buffer_Full;
	else
		return Success;
	}

/***********************************************************************
 * @brief buffer_destroy()
 * This function deallocates memory used by the buffer pointed by cbptr
 * @param (buffer)* cbptr pointer to buffer struct
 * @return error in form of enum defined in main.h
 ***********************************************************************/
Buffer_status buffer_destroy(buffer_typedef* cbptr)
{
	free(cbptr->buffptr);
	cbptr->buffptr = NULL;
	return Success;
}


/***********************************************************************
 * @brief getchar()
 * receives a charater from UART
 * @return acsii value of scanned character
 ***********************************************************************/
uint8_t getchar (void)
{
//	char cc;
    while (!RI);                // compare asm code generated for these three lines
    //while ((SCON & 0x01) == 0);  // wait for character to be received, spin on RI
	//while (RI == 0);
	RI = 0;			// clear RI flag
	return SBUF;  	// return character from SBUF
}


/***********************************************************************
 * @brief putchar()
 * This function deallocates memory used by the buffer pointed by cbptr
 * @param 'c' charater to be transmitted via UART
 ***********************************************************************/
void putchar (__xdata uint8_t c)
{
while(!TI); //wait for transmitter to be ready
SBUF = c; //write character to transmit buffer
TI = 0; //clear the TI flag
}


/***********************************************************************
 * @brief buffer_create()
 * This function creates a new buffer
 * @return error in form of enum defined in main.h
 ***********************************************************************/
Buffer_status buffer_create(void)
{
	__xdata static uint16_t buffer_size=0;
	__xdata uint8_t i=0;
	Buffer_status error_check = 0;
	my_printf(size_buffer_txt_0);
	print_number(buffer_number);
	while(error_check==0)
	{
		if(buffer_number<2)
		{
		    if(buffer_number==0)
			{
                my_printf(size_buffer_txt_1_initial);
			    buffer_size = fetch_number();
			}
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
			buffer_size = fetch_number();
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


/***********************************************************************
 * @brief buffer_delete()
 * This function deletes a buffer
 * @param buffer_number is ID of buffer to be deleted
 * @return error in form of enum defined in main.h
 ***********************************************************************/
Buffer_status buffer_delete(__xdata uint8_t buffer_number)
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


/***********************************************************************
 * @brief buffer_flush()
 * Flushes or prints the data in a buffer
 * @param buffer_number is ID of buffer to be flushed
 * @return error in form of enum defined in main.h
 ***********************************************************************/
Buffer_status buffer_flush(__xdata uint8_t buffer_number)
{
	Buffer_status error_check = 0;
	__xdata uint8_t temp_storage=0;
	buffer_structure_ptr = &buffer_storage[buffer_number];
	buffer_temp_ptr = buffer_structure_ptr->buffptr;
	buffer_structure_ptr->buffptr = buffer_structure_ptr->start;
	do
	{
		error_check=buffer_remove_item(&buffer_storage[buffer_number],&temp_storage);
		putchar(temp_storage);
	}while(error_check!=Buffer_Empty);
 	buffer_structure_ptr->buffptr = buffer_temp_ptr;
	return error_check;
}


/***********************************************************************
 * @brief my_printf()
 * Funtion for printing strings on UART
 * @param pointer to string to be printed
 ***********************************************************************/
void my_printf(__xdata uint8_t* text_ptr)
{
	__xdata uint8_t i=0;
	while(*(text_ptr+i)!='\0')
	{
		putchar(*(text_ptr+i));
		i++;
	}
	return;
}


/***********************************************************************
 * @brief print_number()
 * Converts a number to ascii and prints it via UART
 * @param number to be printed on UART
 ***********************************************************************/
void print_number(__xdata uint32_t number)
{
	__xdata uint8_t temp_ascii_store[10];
	__xdata int8_t counter=0;
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


/***********************************************************************
 * @brief fetch_number()
 * get characters from UART and combine to create number
 * @return decimal number
***********************************************************************/
uint16_t fetch_number(void)
{
	__xdata uint8_t scanned_digit=0,digit_array[10],digit_counter=0,i=0;
	__xdata uint16_t number=0;
	while(scanned_digit!='\r')
	{
		scanned_digit=getchar();
		if((scanned_digit >= '0') && (scanned_digit <= '9'))
		{
		    putchar(scanned_digit);
            digit_array[digit_counter]=scanned_digit-'0';
            digit_counter++;
		}
		else if(scanned_digit=8) //check for backspace
        {
            putchar(8); //print backspace
            putchar(20); //print space
            putchar(8); //print backspace
            digit_counter--;
        }
	}
	for(i=0;i<digit_counter;i++)
    {
        number*= 10;
        number+= digit_array[i] - '0';
    }
	return number;
}

/***********************************************************************
 * @brief main()
 * main function for ESD lab3
 * contains initialization and an infinite loop which checks UART input
 * and performs tasks accordingly
***********************************************************************/
void main(void)
{
	//initialization
	__xdata uint8_t key_pressed=0,exit_code=0;
    __xdata uint16_t buffer_size = 0;
	Buffer_status error_check = 0;
	init_dynamic_memory(heap,HEAP_SIZE);
	//infinite_loop3
	while(1)
	{
		my_printf(Welcome_txt);
		my_printf(size_buffer_txt_0);
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
            else
            {
                my_printf(large_value_txt);
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
							print_number((uint16_t)buffer_storage[buffer_number].start);
							my_printf(buffer_end_address_txt);
							print_number((uint16_t)buffer_storage[buffer_number].end);
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
					do
					{
						buffer_size = fetch_number();
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
}
