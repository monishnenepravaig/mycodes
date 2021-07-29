#include "common.h"
#define READ_SIZE 32
#define DATA_SIZE 100
#define NEW_LINE 10
#define EOF_new 1

void test_file(uint8_t* fname,uint8_t* data);
void read_file(uint8_t* fname,uint8_t* data);
void write_file(uint8_t* fname,uint8_t* data);
void append_file(uint8_t* fname,uint8_t* data);
