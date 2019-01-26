#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define SIZE 10

typedef struct element_s
{
  void* data; /*user data associated with item */
  struct element_s* next; /* points to next item or 0 (NULL pointer) if this is the last item */
} element;

/* root of the list */
element* first = 0;

/* insert specified item at beginning of list */
void insert_first(element *item)
{
    item->next = first;
    first = item;
}

/* remove and return item from beginning of list. returns 0 (NULL pointer) if list is empty. */
element *remove_first( void )
{
    element *removed = first;
    if( first != 0 ) first = first->next;
    return removed;
}

/* remove and return item from end of list. returns 0 (NULL pointer) if list is empty. */
element *remove_last(void)
{
	if(first==NULL)
	{
		return first;
	}
  	element *node = first;
	if(node->next==NULL)
	{
		first=NULL;
		return node;		
	}
   	element *prev = NULL;
	while(node->next!=NULL)
      	{
		prev = node;
           	node = node->next;
       	}
       	prev->next=NULL;
   	return node;
}

void print_ll(void)
{
    	element* node=first;
	if(first==NULL)
	{
		printf("\nEmpty Link List\n");
	}
    	while(node!=NULL)
    	{
        	printf("%d\t",*(uint32_t*)(node->data));
        	node = node->next;
    	}
}

void main()
{
	uint32_t i=0;	
	element node[SIZE];
	element* removed;
	for(i=0;i<SIZE;i++)
	{
		node[i].data=(uint32_t*)malloc(sizeof(uint32_t));
		*(uint32_t*)(node[i].data)=i;
		insert_first(&node[i]);
	}
	print_ll();
	printf("\nstart removing\n");
	for(i=0;i<SIZE;i++)
	{
		removed=remove_last();
		printf("%d\t",*(uint32_t*)(removed->data));
	}
	removed=remove_last();
	print_ll();
}
