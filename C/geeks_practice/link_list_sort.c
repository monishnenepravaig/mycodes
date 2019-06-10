#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 10
#define TOTAL_NODES 100
#define RANGE 100
#define HASH_SIZE 1000

typedef struct node_t
{
	int32_t	data;
	struct node_t* next;
}node_t;

node_t head;
node_t nodes[TOTAL_NODES];
void ll_print(node_t** head_ptr);

void swap_nodes(node_t** head_ptr,node_t* a, node_t* b, node_t* prev)
{
	node_t* temp=b->next;
	if(prev==NULL)
	{
		//printf("null detected\n");
		*head_ptr=b;
	}
	else
	{		
		//printf("before sorting %d %d %d\n",prev->data,prev->next->data,prev->next->next->data);
		prev->next=b;
	}
	b->next=a;
	a->next=temp;
}

void ll_bubble_sort(node_t** head_ptr)
{
	uint32_t swap=1;
	node_t* current;
	node_t* prev;
	while(swap)
	{	
		swap=0;
		prev=NULL;
		current=*head_ptr;		
		while(current->next!=NULL)
		{
			//printf("%d %d\n",current->data,current->next->data);
			if(current->data > current->next->data)
			{
				swap++;
				swap_nodes(head_ptr,current,current->next,prev);
				if(prev!=NULL)
				{
					prev=prev->next;
					current=prev->next;
				}
				else
				{
					prev=current;
					current=current->next;			
				}
			}
			else
			{
				prev=current;
				current=current->next;
			}
		}
		//printf("Round ended\n");	
		//ll_print(head_ptr);
	}	
	//printf("\n");
	return;
}

void ll_selection_sort(node_t** head_ptr)
{
	bool found=0;
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
		//ll_print(&new_head);
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

node_t* ll_merge(node_t** head_ptr1, node_t** head_ptr2)
{
	node_t* current;
	current=*head_ptr1;	
	node_t** hashtable=(node_t**)calloc(HASH_SIZE,sizeof(node_t**));		
	while(current!=NULL)
	{
		if(*(hashtable+(((uint64_t)current)%HASH_SIZE))==NULL)
		{
			*(hashtable+(((uint64_t)current)%HASH_SIZE))=current;
		}
		else
		{
			return *(hashtable+(((uint64_t)current)%HASH_SIZE));
		}
		current=current->next;
	}
	current=*head_ptr2;		
	while(current!=NULL)
	{
		if(*(hashtable+(((uint64_t)current)%HASH_SIZE))==NULL)
		{
			*(hashtable+(((uint64_t)current)%HASH_SIZE))=current;
		}
		else
		{
			return *(hashtable+(((uint64_t)current)%HASH_SIZE));
		}
		current=current->next;
	}
	return NULL;
}

node_t* ll_loop(node_t** head_ptr)
{
	node_t* current;
	current=*head_ptr;	
	node_t** hashtable=(node_t**)calloc(HASH_SIZE,sizeof(node_t**));		
	while(current!=NULL)
	{
		if(*(hashtable+(((uint64_t)current)%HASH_SIZE))==NULL)
		{
			*(hashtable+(((uint64_t)current)%HASH_SIZE))=current;
		}
		else
		{
			return *(hashtable+(((uint64_t)current)%HASH_SIZE));
		}
		current=current->next;
	}
	return NULL;
}

void ll_print(node_t** head_ptr)
{
	node_t* current=ll_loop(head_ptr);
	if(current!=NULL)
	{
		printf("\nloop detected at %lx:%d\n",(uint64_t)current,current->data);
		return;
	}
	current=*head_ptr;
	while(current!=NULL)
	{
		printf("%d\t",current->data);
		current = current->next;
	}	
	printf("\n");
	return;
}

void ll_add_tail(node_t** head_ptr, node_t* new)
{
	node_t* current = *head_ptr;
	//printf("Adding Node\n");
	if(current==NULL)
	{
		printf("Bad Head\n");
		return;
	}
	while(current->next!=NULL)
	{
		//printf("*%d",current->data);
		current = current->next;
	}
	//printf("\n");
	current->next=new;
	return;
}

void ll_reverse(node_t** head_ptr)
{
	node_t* current=*head_ptr;
	node_t* prev=NULL;
	node_t* temp=NULL;	
	while(current!=NULL)
	{
		temp=current->next;
		current->next=prev;
		prev=current;
		current=temp;
	}
	*head_ptr=prev;
}

void main(void)
{
	int i=0,temp=0;
	node_t* head_ptr=&head;
	node_t head2,*head2_ptr;
	srand(time(NULL));
	head.data=rand()%RANGE;
	for(i=0;i<TOTAL_NODES;i++)
	{
		nodes[i].data=rand()%RANGE;
		nodes[i].next=NULL;	
		//printf("Adding node %d\n",i);
		ll_add_tail(&head_ptr,&nodes[i]);
	}
	ll_print(&head_ptr);
	ll_reverse(&head_ptr);
	ll_print(&head_ptr);
	ll_selection_sort(&head_ptr);
	ll_print(&head_ptr);
}
