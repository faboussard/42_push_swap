#include "../../inc/push_swap.h"

static t_node_int	*get_min_node(t_node_int **one_stack)
{
	t_node_int	*current;
	t_node_int	*lst_min;
	int		min;

	if (!(*one_stack))
		return (NULL);
	min = 0;
	lst_min = NULL;
	current = *one_stack;
	while (current)
	{
		if ((current->index == -1) && (!min || current->content < lst_min->content))
		{
			lst_min = current;
			min = 1;
		}
		current = current->next;
	}
	return (lst_min);
}

void	init_index(t_node_int **stack)
{
	t_node_int	*lst;
	int		index;

	index = 0;
	lst = get_min_node(stack);
	while (lst)
	{
		lst->index = index++;
		lst = get_min_node(stack);
	}
}
