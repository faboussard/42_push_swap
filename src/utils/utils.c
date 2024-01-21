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

/*
int check_errors_and_init_stack(t_node_int **one_stack, const char **av, int ac)
{
	int			i;
	int			j;
	char		**split;

	i = 0;
	while (i++ < ac)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		if (split[j] == NULL)
			return (NOT_OK);
		while (split[j++])
		{
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				return (NOT_OK);
			if ((error_syntax(split[j]) == NOT_OK) || (error_duplicate(*one_stack, (int)(ft_atol(split[j])) == NOT_OK))
			|| (create_node_and_add_back(split[j], one_stack) == NULL))
				free_errors(one_stack);
		}
		free_split(split);
	}
	return (OK);
}
*/

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