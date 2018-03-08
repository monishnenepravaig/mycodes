/*+
* ESD_Buffer_handler.c
 *
 *  Created on: mar 1 , 2018
 *      Author: monish
 */
#include <stdlib.h>
#include "ESD_Buffer_Handling.h"

/***********************************************************************
 * @brief buffer_init()
 * This function allocates memory using malloc for buffer
 * @(buffer)* cbptr pointer to buffer struct
 * @length length of the buffer
 * @return error in form of enum defined in ESD_Buffer_handler.h
 ***********************************************************************/
Buffer_status buffer_init(buffer_typedef* cbptr,uint16_t length)
{
	(cbptr->buffptr) = malloc(length);
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
 * @(buffer)* cbptr pointer to buffer struct
 * @data value to be stored in buffer
 * @return error in form of enum defined in ESD_Buffer_handler.h
 ***********************************************************************/
Buffer_status buffer_add_item(buffer_typedef* cbptr,uint8_t data)
{
	uint8_t i = buffer_end_reached(cbptr);
	if(i == Buffer_Full)
		{return Buffer_Full;}
	else
	{
		(cbptr->count)++;
		*(cbptr->buffptr) = data;
		cbptr->buffptr++;
		return Success;
	}
}


/***********************************************************************
 * @brief buffer_remove_item()
 * This function removes an item from buffer and stores it
 * @(buffer)* cbptr pointer to buffer struct
 * @store pointer to the location where the data is supposed to be stored
 * @return error in form of enum defined in ESD_Buffer_handler.h
 ***********************************************************************/
Buffer_status buffer_remove_item(buffer_typedef* cbptr,uint8_t* store)
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
 * @(buffer)* cbptr pointer to buffer struct
 * @return error in form of enum defined in ESD_Buffer_handler.h
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
 * @(buffer)* cbptr pointer to buffer struct
 * @return error in form of enum defined in ESD_Buffer_handler.h
 ***********************************************************************/
Buffer_status buffer_destroy(buffer_typedef* cbptr)
{
	free(cbptr->buffptr);
	cbptr->buffptr = NULL;
	return Success;
}


