#include "../../inc/push_swap.h"

void	rev_rotate_one(t_node **list)
{
	t_node	*tmp;
	t_node	*tail;
	t_node	*before_tail;

	tail = ft_lstlast(*list);
	before_tail = get_stack_before_bottom(*list);
	tmp = *list;
	*list = tail;
	(*list)->next = tmp;
	before_tail->next = NULL;
}

//essayer avec get last.
//tu garde before tail
//current = list
//list = get last.
// list next = tmp
//et on coupe avec before tail de next