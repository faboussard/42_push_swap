#include "../../inc/push_swap.h"

void	rev_rotate_one(t_node_int **head)
{
	t_node_int	*temp;
	t_node_int	*tail;
	t_node_int	*before_tail;

	tail = ft_lstlast(*head);
	before_tail = ft_lstbeforelast(*head);
    temp = *head;
	*head = tail;
	(*head)->next = temp;
	before_tail->next = NULL;
}

void rev_rotate_both(t_node_int **first_stack_head, t_node_int **second_stack_head)
{
    rev_rotate_one(first_stack_head);
    rev_rotate_one(second_stack_head);
}