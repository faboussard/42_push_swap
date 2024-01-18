#include "../../inc/push_swap.h"

void rotate_one(t_node **head)
{
	void *temp;

	if (!head || !*head || !(*head)->next)
		return;
	temp = (*head)->content;
	(*head) = ((*head)->next);
	ft_lstadd_back(head, ft_lstnew(temp));
}


void rotate_both(t_node **first_stack_head, t_node **second_stack_head)
{
    rotate_one(first_stack_head);
    rotate_one(second_stack_head);
}