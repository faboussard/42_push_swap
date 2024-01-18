#include "../../inc/push_swap.h"

void	rev_rotate_one(t_node **head)
{
	t_node	*temp;
	t_node	*tail;
	t_node	*before_tail;

	tail = ft_lstlast(*head);
	before_tail = ft_lstbeforelast(*head);
    temp = *head;
	*head = tail;
	(*head)->next = temp;
	before_tail->next = NULL;
}

/*
void rev_rotate_both(t_node **first_stack_head, t_node **second_stack_head)
{
	rev_rotate(first_stack_head);
	rev_rotate(second_stack_head);
}
 */