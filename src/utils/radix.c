#include "../../inc/push_swap.h"

static int get_maxbits_lst(t_node_int *one_stack)
{
	t_node_int *current;
	int max;
	int max_b;

	current = one_stack;
	max = current->index;
	max_b = 0;

	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);
}