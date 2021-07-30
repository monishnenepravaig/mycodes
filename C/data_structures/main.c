#include "main.h"

int32_t main(int32_t argc, uint8_t**argv)
{
	int32_t check=0;
	node_t** data_ll=(node_t**)malloc(ALPHABETS*sizeof(node_t*));
	check=create_data_ll(fname,data_ll);
	check=print_data_ll(data_ll);
	check=reverse_data_ll(data_ll);
	check=print_data_ll(data_ll);
	check=sort_data_ll(data_ll);
	check=print_data_ll(data_ll);
	printf("\n\rmain executed\n\r");
	return 0;
}
