#include "linklist.h"

int32_t create_data_ll(uint8_t* fname, node_t** data_ll)
{
	uint8_t* str=(uint8_t*)malloc(WORDSIZE*sizeof(uint8_t));
	int32_t eof_check=0;
	node_t* current_node;
	FILE *fptr = fopen(fname,"r");
	while(eof_check != EOF_new)
	{
		str=fgets(str,READ_SIZE,fptr);
		if(str!=NULL)
		{	
			if(*(data_ll+(*str-'A'))==NULL)
			{
				*(data_ll+(*str-'A'))=(node_t*)malloc(sizeof(node_t));
			}
			current_node=*(data_ll+(*str-'A'));
			while(current_node->next!=NULL)
			{
				current_node=current_node->next;
			}
			current_node->next=(node_t*)malloc(sizeof(node_t));
			current_node->data=(uint8_t*)malloc(strlen(str)*sizeof(node_t));
			strcpy(current_node->data,str);
		}
		eof_check=feof(fptr);
	}
	fclose(fptr);
	free(str);
	return eof_check;
}

int32_t print_data_ll(node_t** data_ll)
{
	int32_t i=0,counter=0;
	node_t* current_node;
	for(i=0;i<ALPHABETS;i++)
	{
		printf("\n\rPokemons starting with letter %c\n\r",'A'+i);
		current_node=*(data_ll+i);
		if(current_node==NULL)
		{
			printf("NULL node");
		}
		counter=1;
		while(current_node->data!=NULL)
		{
			printf("%d %s",counter++,current_node->data);		
			current_node=current_node->next;
		}
	}
	return i;
}
