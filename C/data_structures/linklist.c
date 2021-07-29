#include "linklist.h"



node_t* merge_sorted_ll(node_t* a, node_t* b)
{
	int32_t i=0;
	node_t* dummy=NULL;
	if(a==NULL)return b;
	else if(b==NULL)return a;
	while((*(a->data+i)!=*(b->data+i))||(*(a->data+i)=='\0')||(*(b->data+i)=='\0'))i++;
	if(*(a->data+i)<=*(b->data+i))
	{
		dummy=a;
		printf("%s",a->data);
		dummy->next = merge_sorted_ll(a->next,b);
	}
	else
	{
		dummy=b;
		printf("%s",b->data);
		dummy->next = merge_sorted_ll(a,b->next);
	}
	return dummy;
	
}

node_t* merge_sort_ll(node_t* head_ptr)
{
	printf("entered merge sort at head %s",head_ptr->data);
	int check=0;
	node_t *head=head_ptr,*half,*dummy;
	if(head==NULL||head->next==NULL)return 0;
	half=head;
	dummy=head->next;
	while(dummy!=NULL)
	{
		dummy=dummy->next;
		printf("dummy-%s",dummy->data);
		if(dummy!=NULL);
		{
			half=half->next;
			printf("half-%s",half->data);
			dummy=dummy->next;
			printf("dummy-%s",dummy->data);
		}				
	}
	printf("half-%s",half->data);
	dummy=merge_sort_ll(half);
	half->next=NULL;
	head=merge_sort_ll(head);
	head_ptr=merge_sorted_ll(head,dummy);
	return head_ptr;
}

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

int32_t sort_data_ll(node_t** data_ll)
{
	int32_t i=0,check=0;
	node_t* current_node;
	for(i=0;i<ALPHABETS;i++)
	{
		current_node=*(data_ll+i);
		if(current_node==NULL)
		{
			printf("NULL node");
		}
		else
		current_node=merge_sort_ll(current_node);
	}
	return check;
}
