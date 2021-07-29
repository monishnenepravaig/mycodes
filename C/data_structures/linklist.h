#include "common.h"

typedef struct node_t
{
	struct node_t* next;
	uint8_t* data;
}node_t;

int32_t create_data_ll(uint8_t* fname, node_t** data_ll);
int32_t print_data_ll(node_t** data_ll);
node_t* merge_sorted_ll(node_t* a, node_t* b);
node_t* merge_sort_ll(node_t* head_ptr);
int32_t sort_data_ll(node_t** data_ll);

