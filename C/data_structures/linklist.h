#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node_t
{
	struct node_t* next;
	int32_t data;
}node_t;

