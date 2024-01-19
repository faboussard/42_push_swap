#include "../../inc/push_swap.h"

void swap_one(t_node_int **head)
{
	int	index;
	int content;

	if (!head || !*head || !(*head)->next)
		return;
	content = (*head)->next->content;
	index = (*head)->next->index;
	(*head)->next->content = (*head)->content;
	(*head)->next->index = (*head)->index;
	(*head)->content = content;
	(*head)->index = index;
}

void swap_both(t_node_int **first_stack_head, t_node_int **second_stack_head)
{
    swap_one(first_stack_head);
    swap_one(second_stack_head);
}