#include <stdint.h>
#include "ESD_Buffer_Handling.h"
buffer_typedef buffer_storage[20];
buffer_typedef* buffer_structure_ptr;
static uint8_t buffer_number=0,max_buffers_created=0;
static uint32_t characters_count=0;
//sentences
uint8_t Welcome_txt[] = "\n\rMonish Nene ESD Spring 2018 Lab 3";
uint8_t size_buffer_txt_0[] = "\n\rEnter the size for buffer ";
uint8_t size_buffer_txt_1_initial[] = " between 32 to 3200 bytes and a multiple of 32:";
uint8_t size_buffer_txt_1_later[] = " between 20 to 400 bytes:";
uint8_t invalid_number_txt[] = "\n\rinvalid number.\n\rRe-enter number:";
uint8_t buffer_instructions_txt[]="\n\r'+' Add Buffer, '-' Delete Buffer, '=' Dump Buffer 0, '?' Buffer Query, '@' Reset Code"; 
uint8_t buffer_allocation_failed_txt[] = "\n\rMemory Allocation failed for buffer ";
uint8_t buffer_delete_number_txt[] = "\n\rWhat is the buffer id of the buffer you want to delete?(Note: Buffer 0 can't be deleted.)";
uint8_t buffer_deleted_txt[] = "\n\rDeleted Buffer ";
uint8_t buffer_created_txt[] = "\n\rCreated Buffer ";
uint8_t buffer_txt[]= "\n\rBuffer ";
uint8_t full_txt[]=" is full.";
uint8_t with_txt[] = " with ";
uint8_t bytes_txt[] = " bytes";
uint8_t buffer_number_txt[]="\n\rBuffer number = ";
uint8_t buffer_start_address_txt[]="\n\rBuffer Start Address = ";
uint8_t buffer_end_address_txt[]="\n\rBuffer End Address = ";
uint8_t buffer_size_txt[]="\n\rTotal Allocated size for buffer = ";
uint8_t buffer_used_txt[]="\n\rUsed Space in buffer = ";
uint8_t buffer_unused_txt[]="\n\rUnused Space in buffer = ";
uint8_t buffer_query_txt[]="\n\rNumber of Characters entered after the last '?' = ";
//functions
Buffer_status buffer_create(void);
Buffer_status buffer_delete(uint8_t buffer_number);
void my_printf(uint8_t* text_ptr);
void print_number(uint32_t number);
uint16_t fetch_number(void);
Buffer_status  buffer_flush(uint8_t buffer_number);
