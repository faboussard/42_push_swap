#include "../../inc/push_swap.h"

void rotate_one(t_node_int **head)
{
	t_node_int *is_last;

	if (!head || !*head || !(*head)->next)
		return;
	is_last = ft_lstlast(*head);
	is_last->next = *head;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	is_last->next->prev = is_last;
	is_last->next->next = NULL;
}

void rotate_both(t_node_int **first_stack_head, t_node_int **second_stack_head)
{
    rotate_one(first_stack_head);
    rotate_one(second_stack_head);
}