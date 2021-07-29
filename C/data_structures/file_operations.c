#include "file_operations.h"

void test_file(uint8_t* fname,uint8_t* data)
{
	int32_t eof_check=0,check=0;
	FILE *fptr1 = fopen(fname,"r");
	FILE *fptr2 = fopen("test_write.txt","a");
	
	while(eof_check != EOF_new)
	{	
		data=fgets(data,READ_SIZE,fptr1);
		if(data!=NULL)
		{	
			printf("%s",data);
			check=fputs(data,fptr2);
		}
		eof_check=feof(fptr1);
	}
	fclose(fptr1);
	fclose(fptr2);
	return;
}

void read_file(uint8_t* fname,uint8_t* data)
{
	int32_t eof_check=0;
	FILE *fptr = fopen(fname,"r");
	while(eof_check != EOF_new)
	{		
		data=fgets(data,READ_SIZE,fptr);
		if(data!=NULL)
		{	
			printf("%s",data);
		}
		eof_check=feof(fptr);
	}
	fclose(fptr);
	return;
}

void write_file(uint8_t* fname,uint8_t* data)
{
	uint32_t error_check=0;
	FILE *fptr = fopen(fname,"w");
	error_check=fputs(data,fptr);
	fclose(fptr);
	return;
}

void append_file(uint8_t* fname,uint8_t* data)
{
	uint32_t error_check=0;
	FILE *fptr = fopen(fname,"a");
	error_check=fputs(data,fptr);
	fclose(fptr);
	return;
}
