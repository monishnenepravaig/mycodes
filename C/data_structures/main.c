#include "main.h"


void create_data_ll(void)
{
	uint8_t* str=(uint8_t*)malloc(WORDSIZE*sizeof(uint8_t));
	int32_t eof_check=0,i=0;
	node_t* current_node;
	node_t** data_ll=(node_t**)malloc(ALPHABETS*sizeof(node_t*));
	FILE *fptr = fopen(fname,"r");
	while(eof_check != EOF_new)
	{
		str=fgets(str,READ_SIZE,fptr);
		if(str!=NULL)
		{	
			current_node=*(data_ll+(*str-'A'));
			if(current_node!=NULL)
			{	
				while(current_node->next!=NULL)
				{
					current_node=current_node->next;
				}
			}
			current_node=(node_t*)malloc(sizeof(node_t));
			current_node->data=(uint8_t*)malloc(strlen(str)*sizeof(node_t));
			strcpy(current_node->data,str);
			printf("%s",current_node->data);
		}
		eof_check=feof(fptr);
	}
	fclose(fptr);
	free(str);
}


int32_t main(int32_t argc, uint8_t**argv)
{
	create_data_ll();
	printf("main executed\n");
	return 0;
}
