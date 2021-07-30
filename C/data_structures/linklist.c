#include "linklist.h"

void print_ll(node_t** head_ptr)
{
	node_t* current=*head_ptr;
	while(current!=NULL)
	{
		printf("%s\t",current->data);
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
			printf("%d %s",current_node->count,current_node->data);		
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

void selection_sort_ll(node_t** head_ptr)
{
	int32_t found=0;
	node_t dummy;
	dummy.data=0;
	dummy.next=NULL;
	node_t* prev = NULL;
	node_t* temp = NULL;
	node_t* current = (*head_ptr);
	node_t* search = &dummy;
	search->next=NULL;
	node_t* new_head = search;
	while(current!=NULL)
	{
		found=0;
		prev=NULL;
		search=new_head;
		while((search->data<current->data)&&(search->next!=NULL))
		{
			prev=search;
			search=search->next;
		}
		temp=current;
		current=current->next;		
		if(prev==NULL)
		{
			temp->next=new_head;
			new_head=temp;				
		}
		else
		{
			prev->next=temp;
			temp->next=search;
		}	
	}
	prev=NULL;
	current=new_head;
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	prev->next=NULL;
	*head_ptr=new_head;
	return;
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
