#include <stdio.h>
#include <stdlib.h>

typedef struct element_s
{
  void* data; /*user data associated with item */
  struct element_s* next; /* points to next item or 0 (NULL pointer) if this is the last item */
} element;
/* root of the list */
element *first = 0;
/* insert specified item at beginning of list */
void insert_first( element *item )
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
   element *removed = first;
   element *t;
   if(first->next==NULL)
   {
       free(first);
       first = NULL;
   }
   else
   {
       while(removed->next!=NULL)
       {
           t=removed;
           removed = removed->next;
       }
       free(t->next);
       t->next=NULL;
   }
   return removed;
}

void print(element* node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
void main()
{
    element *first = NULL;
    insert_first(5);
    insert_first(8);
}
