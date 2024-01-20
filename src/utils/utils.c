#include "../../inc/push_swap.h"

int is_stack_sorted(t_node_int *one_stack)
{
    while (one_stack->next != NULL)
    {
        if (one_stack->content > one_stack->next->content)
            return (NOT_OK);
        one_stack = one_stack->next;
    }
    return (OK);
}

t_node_int *find_node_with_max_value(t_node_int *head)
{
	long max;
	t_node_int *max_node;

	max = LONG_MIN;
	while (head)
	{
		if (head->content > max)
		{
			max = head->content;
			max_node = head;
		}
		head = head->next;
	}
	return (max_node);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}