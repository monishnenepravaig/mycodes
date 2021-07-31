#include "common.h"

typedef struct node_t
{
	struct node_t* next;
	uint8_t* data;
	int32_t count;
	uint8_t* type[2];
}node_t;

typedef enum {
	primary=0,
	secondary=1,
	}types_enum;

int32_t create_data_ll(uint8_t* fname, node_t** data_ll);
int32_t print_data_ll(node_t** data_ll);
int32_t sort_data_ll(node_t** data_ll);
void print_ll(node_t** head_ptr);
node_t* reverse_ll(node_t* head);
int32_t reverse_data_ll(node_t** data_ll);
node_t* sort_ll(node_t* head);
