#include "linklist.h"

void print_ll(node_t** head_ptr)
{
	node_t* current=*head_ptr;
	while(current!=NULL)
	{
		printf("%d %s",current->count,current->data);
		current = current->next;
	}	
	printf("\n");
	return;
}

int32_t create_data_ll(uint8_t* fname, node_t** data_ll)
{
	uint8_t* str=(uint8_t*)malloc(WORDSIZE*sizeof(uint8_t));
	int32_t eof_check=0,counter=0,i=0;
	node_t* current_node;
	FILE *fptr = fopen(fname,"r");
	for(i=0;i<ALPHABETS;i++)
	{
		*(data_ll+i)=(node_t*)malloc(sizeof(node_t));
		current_node=*(data_ll+i);
		current_node->data=(uint8_t*)malloc(2*WORDSIZE);
		sprintf(current_node->data,"Pokemons starting with letter %c\n\r",'A'+i);
		current_node->count=0;
	}
	while(eof_check != EOF_new)
	{
		str=fgets(str,READ_SIZE,fptr);
		if(str!=NULL)
		{	
			counter=1;
			current_node=*(data_ll+(*str-'A'));
			while(current_node->next!=NULL)
			{
				counter++;
				current_node=current_node->next;
			}
			current_node->next=(node_t*)malloc(sizeof(node_t));
			current_node=current_node->next;
			current_node->data=(uint8_t*)malloc(strlen(str)*sizeof(node_t));
			current_node->count=counter;
			strcpy(current_node->data,str);
			(*(data_ll+(*str-'A')))->count=counter;
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
		current_node=*(data_ll+i);
		counter=1;
		printf("\n\r");
		while(current_node!=NULL)
		{
			printf("%d\t%s",current_node->count,current_node->data);		
			current_node=current_node->next;
		}
	}
	return i;
}

node_t* reverse_ll(node_t* head)
{
	int32_t i=0;
	node_t *prev=NULL, *current=head, *temp;
	while(current!=NULL)
	{
		temp=current;
		current=current->next;
		temp->next=prev;
		prev=temp;
	}
	return prev;
}

int32_t reverse_data_ll(node_t** data_ll)
{
	int32_t i=0,check=0;
	node_t* current_node;
	for(i=0;i<ALPHABETS;i++)
	{
		current_node=(*(data_ll+i))->next;
		current_node=reverse_ll(current_node);
		(*(data_ll+i))->next=current_node;
	}
	return check;
}

node_t* sort_ll(node_t* head)
{
	node_t *sorted_head=head,*current=head->next,*buffer,*sorted,*prev;
	sorted_head->next=NULL;
	while(current!=NULL)
	{
		buffer=current;
		current=current->next;
		sorted=sorted_head;
		prev=sorted;
		if(strcmp(sorted_head->data,buffer->data)>0)
		{
			sorted_head=buffer; //insert at head
			buffer->next=sorted;
			continue;
		}
		while(sorted!=NULL)
		{
			if(strcmp(sorted->data,buffer->data)>0)
			{
				prev->next=buffer; //insert in between
				buffer->next=sorted;
				break;
			}
			prev=sorted;
			sorted=sorted->next;
			if(sorted==NULL)
			{	
				prev->next=buffer; //insert at tail
				buffer->next=NULL;
				break;
			}				
		}
	}
	return sorted_head;
}

int32_t sort_data_ll(node_t** data_ll)
{
	int32_t i=0,check=0;
	node_t* current_node;
	for(i=0;i<ALPHABETS;i++)
	{
		current_node=(*(data_ll+i))->next;
		current_node=sort_ll(current_node);
		(*(data_ll+i))->next=current_node;
	}
	return check;
}
