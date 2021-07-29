#include "common.h"

typedef struct node_t
{
	struct node_t* next;
	uint8_t* data;
}node_t;

void create_data_ll(void);
