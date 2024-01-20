#include "../../inc/push_swap.h"

void sort_3_elements(t_node_int **one_stack)
{
	t_node_int *max_value_node;

	max_value_node = find_node_with_max_value(*one_stack);
    if (max_value_node == *one_stack)
        do_ra(one_stack);
    if ((*one_stack)->next == max_value_node)
		do_rra(one_stack);
    if ((*one_stack)->content > (*one_stack)->next->content)
        do_sa(one_stack);
}
/*
void sort_4_elements(t_node_int **one_stack)
{
	t_node_int *max_value_node;
	t_node_int *another_stack;

	max_value_node = find_node_with_max_value(*one_stack);
	push_head(&max_value_node, &another_stack);
	sort_3_elements(one_stack);
	push_head(&another_stack, one_stack);
	rotate_one(one_stack);
}
 */