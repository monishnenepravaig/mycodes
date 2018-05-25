/*
* ESD_Buffer_handler.h
 *
 *  Created on: mar 1 , 2018
 *      Author: monish
 */

#include <stdint.h>
typedef struct
{
uint8_t buffer_id;
uint8_t* buffptr;//current address
uint8_t* start;//start address
uint8_t* end;//end address
uint16_t length;//length of buffer
int16_t count;//used
}buffer_typedef;

typedef enum
{
Buffer_Full,
Buffer_Empty,
Success,
Null_Error,
fail,
}Buffer_status;


Buffer_status buffer_add_item(buffer_typedef* cbptr,uint8_t data);
Buffer_status buffer_remove_item(buffer_typedef* cbptr,uint8_t* store);
Buffer_status buffer_end_reached(buffer_typedef* cbptr);
Buffer_status buffer_init(buffer_typedef* cbptr,uint16_t length);
Buffer_status buffer_destroy(buffer_typedef* cbptr);

