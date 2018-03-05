/*+
* ESD_Buffer_handler.c
 *
 *  Created on: mar 1 , 2018
 *      Author: monish
 */

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
	(cbptr -> buffptr) = malloc(length);
	cbptr = malloc(sizeof(buffer));
	if(cbptr->buffptr == NULL)
		{return Null_Error;}
	else
		{return Success;}
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
	uint8_t i = CB_is_full(cbptr);
	if(i == Buffer_Full)
		{return Buffer_Full;}
	else
	{
		if (((cbptr->head)+1)==(cbptr->buffptr+cbptr->length))
			{cbptr->head = cbptr->buffptr;}
		else
			{
			cbptr->head++;
			(cbptr->count++);
			}
		*(cbptr->head) = data;
		return Success;
	}
	return fail;
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
	uint8_t i=CB_is_empty(cbptr);
	if(i == Buffer_Empty)
		{return Buffer_Empty;}
	else
	{
		if (((cbptr->tail)+1)==(cbptr->buffptr)+(cbptr->length))
			{cbptr->tail = cbptr->buffptr;}
		else
			{
			 cbptr->tail++;
			(cbptr->count--);
			}
		*store=*(cbptr->tail);
		return Success;
	}	
	return fail;
}

/***********************************************************************
 * @brief buffer_is_full()
 * This function checks if buffer is full
 * @(buffer)* cbptr pointer to buffer struct
 * @return error in form of enum defined in ESD_Buffer_handler.h
 ***********************************************************************/
Buffer_status buffer_is_full(buffer_typedef* cbptr)
	{
	if((cbptr->buffptr)==(cbptr->end)+1)
		return Buffer_Full;
	else
		return Success;
	}



/***********************************************************************
 * @brief buffer_is_empty()
 * This function checks if buffer is empty
 * @(buffer)* cbptr pointer to buffer struct
 * @return error in form of enum defined in ESD_Buffer_handler.h
 ***********************************************************************/
Buffer_status buffer_is_empty(buffer_typedef* cbptr)
{
	if((cbptr->buffptr)==(cbptr->start))
		return Buffer_Empty;
	else
		return Success;
}



/***********************************************************************
 * @brief buffer_peek()
 * This function copies the item from buffer at a given position and stores it
 * @(buffer) cbptr pointer to buffer struct
 * @position position from base
 * @store pointer to the location where the data is supposed to be stored
 * @return error in form of enum defined in ESD_Buffer_handler.h
 ***********************************************************************/
Buffer_status buffer_peek(buffer_typedef* cbptr,uint16_t position,uint8_t* store)
{
	uint8_t i=buffer_is_empty(cbptr);
	if(i == Buffer_Empty)
		{return Buffer_Empty;}
	else
	{
		while(position> cbptr->length)
		{position -= cbptr->length;}
		*store=*(cbptr->head-position);
		return Success;
	}
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
	free(cbptr->start);
	free(cbptr->end);
	free(cbptr);
	return Success;
}


