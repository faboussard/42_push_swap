#include "../../inc/push_swap.h"

static int	error_syntax(const char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (OK);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (OK);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (OK);
	}
	return (NOT_OK);
}

static int	error_duplicate(t_node_int *t_stack, int n)
{
	if (!t_stack)
		return (NOT_OK);
	while (t_stack)
	{
		if (t_stack->content == n)
			return (OK);
		t_stack = t_stack->next;
	}
	return (NOT_OK);
}

static void free_errors(t_node_int **a_stack)
{
	ft_lstclear(a_stack);
	write(2, "Error\n", 7);
}

int check_errors_and_init_stack(t_node_int **one_stack, const char **av, int ac)
{
	int			i;
	int			j;
	char		**split;

	j = 0;
	i = 0;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split[j])
			return (NOT_OK);
		while (split[j])
		{
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				return (NOT_OK);
			if (error_syntax(split[j]) == NOT_OK)
				free_errors(one_stack);
			if (error_duplicate(*one_stack, (int)(ft_atol(split[j]))) == NOT_OK)
				free_errors(one_stack);
			if (create_node_and_add_back(split[j], one_stack) == NULL)
				free_errors(one_stack);
			j++;
		}
		free_split(split);
		i++;
	}
	return (OK);
}

/*
void check_errors_and_init_stack(t_node_int **one_stack, const char **av, int ac)
{
	long n;
	int	n_int;
	ssize_t i;
	t_node_int	*new_node;

	i = 0;
	while (i < ac)
	{
		n = ft_atol(av[i]);
		if (error_syntax(av[i]) || (n > INT_MAX || n < INT_MIN) || error_duplicate(*one_stack, (int)n))
			free_errors(one_stack);
		n_int = (int)n;
		new_node = ft_lstnew(n_int);
		if (new_node == NULL)
		{
			ft_lstclear(&new_node);
			write(2, "Error\n", 12);
			return;
		}
		ft_lstadd_back(one_stack, new_node);
		i++;
	}
}
*/
