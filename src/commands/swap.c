#include "../../inc/push_swap.h"

void swap_one(t_node **head)
{
	t_node *temp;

	if (!head || !*head || !(*head)->next)
		return;
	temp = (*head)->next->next ;
    ft_lstadd_front(head, (*head)->next);
	(*head)->next->next = temp;
}

void swap_both(t_node **first_stack_head, t_node **second_stack_head)
{
    swap_one(first_stack_head);
    swap_one(second_stack_head);
}