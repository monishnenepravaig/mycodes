
#include <at89c51ed2.h>
#include <mcs51reg.h>
#include <stdint.h>
#include <malloc.h>
typedef struct
{
    uint8_t buffer_id;
    uint8_t* buffptr;//current address
    uint8_t* start;//start address
    uint8_t* end;//end address
    uint16_t length;//length of buffer
    int16_t count;//used
}buffer_typedef;

# define NULL (void *)0

typedef enum
{
Buffer_Full,
Buffer_Empty,
Success,
Null_Error,
fail,
}Buffer_status;
__xdata buffer_typedef buffer_storage[20];
__xdata buffer_typedef* buffer_structure_ptr;
__xdata uint8_t buffer_number=0,max_buffers_created=0;
__xdata uint32_t characters_count=0;
uint8_t* buffer_temp_ptr;
//sentences
__xdata uint8_t Welcome_txt[] = "\n\rMonish Nene ESD Spring 2018 Lab 3";
__xdata uint8_t size_buffer_txt_0[] = "\n\rEnter the size for buffer 0 and buffer 1";
__xdata uint8_t size_buffer_txt_1_initial[] = " between 32 to 3200 bytes and a multiple of 32:";
__xdata uint8_t size_buffer_txt_1_later[] = " between 20 to 400 bytes:";
__xdata uint8_t invalid_number_txt[] = "\n\rinvalid number.\n\rRe-enter number:";
__xdata uint8_t buffer_instructions_txt[]="\n\r'+' Add Buffer, '-' Delete Buffer, '=' Dump Buffer 0, '?' Buffer Query, '@' Reset Code";
__xdata uint8_t buffer_allocation_failed_txt[] = "\n\rMemory Allocation failed for buffer ";
__xdata uint8_t buffer_delete_number_txt[] = "\n\rWhat is the buffer id of the buffer you want to delete?(Note: Buffer 0 can't be deleted.)";
__xdata uint8_t buffer_deleted_txt[] = "\n\rDeleted Buffer ";
__xdata uint8_t buffer_created_txt[] = "\n\rCreated Buffer ";
__xdata uint8_t buffer_txt[]= "\n\rBuffer ";
__xdata uint8_t full_txt[]=" is full.";
__xdata uint8_t with_txt[] = " with ";
__xdata uint8_t bytes_txt[] = " bytes";
__xdata uint8_t buffer_number_txt[]="\n\rBuffer number = ";
__xdata uint8_t buffer_start_address_txt[]="\n\rBuffer Start Address = ";
__xdata uint8_t buffer_end_address_txt[]="\n\rBuffer End Address = ";
__xdata uint8_t buffer_size_txt[]="\n\rTotal Allocated size for buffer = ";
__xdata uint8_t buffer_used_txt[]="\n\rUsed Space in buffer = ";
__xdata uint8_t buffer_unused_txt[]="\n\rUnused Space in buffer = ";
__xdata uint8_t buffer_query_txt[]="\n\rNumber of Characters entered after the last '?' = ";
__xdata uint8_t large_value_txt[]="\n\rMemory Allocation Failed. Too large value for buffer. Enter smaller values";
//functions
Buffer_status buffer_create(void);
Buffer_status buffer_delete(__xdata uint8_t buffer_number);
void my_printf(__xdata uint8_t* text_ptr);
void print_number(__xdata uint32_t number);
uint16_t fetch_number(void);
Buffer_status  buffer_flush(__xdata uint8_t buffer_number);
Buffer_status buffer_add_item(buffer_typedef* cbptr, uint8_t data);
Buffer_status buffer_remove_item(buffer_typedef* cbptr, uint8_t* store);
Buffer_status buffer_end_reached(buffer_typedef* cbptr);
Buffer_status buffer_init(buffer_typedef* cbptr, uint16_t length);
Buffer_status buffer_destroy(buffer_typedef* cbptr);


