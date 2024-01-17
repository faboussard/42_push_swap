#include "../../inc/push_swap.h"

void	rev_rotate_one(t_node **list)
{
	t_node	*tmp;
	t_node	*tail;
	t_node	*before_tail;

	tail = get_stack_bottom(*list);
	before_tail = get_stack_before_bottom(*list);
	tmp = *list;
	*list = tail;
	(*list)->next = tmp;
	before_tail->next = NULL;
}