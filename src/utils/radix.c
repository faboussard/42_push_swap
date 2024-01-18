#include "../../inc/push_swap.h"

void sort_3_elements(t_node *one_stack)
{
    if (*(int*)one_stack->content == 2)
        rotate_one(&one_stack);
    if (*(int*)one_stack->next->content == 3)
            rev_rotate_one(&one_stack);
    if (*(int*)one_stack->content > *(int*)one_stack->next->content)
        swap_one(&one_stack);
}
/*
void sort_4_elements(t_node *one_stack)
{
	t_node *node_with_max_value;
	t_node *another_stack;


	node_with_max_value = find_node_with_max_value(one_stack);
	push_head(&node_with_max_value, &another_stack);
	sort_3_elements(one_stack);
	push_head(&another_stack, &one_stack);
	ft_lstadd_back(&one_stack, node_with_max_value);
}*/