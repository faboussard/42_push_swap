#include "../../inc/push_swap.h"

void rotate_one(t_node **head)
{
	void *is_first;

	if (!head || !*head || !(*head)->next)
		return;
    is_first = (*head)->content;
	(*head) = ((*head)->next);
	ft_lstadd_back(head, ft_lstnew(is_first));
}


void rotate_both(t_node **first_stack_head, t_node **second_stack_head)
{
    rotate_one(first_stack_head);
    rotate_one(second_stack_head);
}