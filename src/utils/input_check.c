#include "../../inc/push_swap.h"

int	error_syntax(const char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_node *t_stack, int n)
{
	if (!t_stack)
		return (0);
	while (t_stack)
	{
		if (*(int *)t_stack->content == n)
			return (1);
        t_stack = t_stack->next;
	}
	return (0);
}

void	free_errors(t_node **a_stack)
{
	ft_lstclear(a_stack, del);
	ft_printf("Input Error\n");
	exit(EXIT_FAILURE);
}

void check_errors_and_init_stack(t_node **one_stack, const char **av, int ac)
{
    long n;
    int *n_int;
    ssize_t i;
	t_node	*new_node;

    i = 0;
	while (i < ac)
    {
		n = ft_atol(av[i]);
		if (error_syntax(av[i]) || (n > INT_MAX || n < INT_MIN) || error_duplicate(*one_stack, (int)n))
            free_errors(one_stack);
        n_int = malloc(sizeof(int));
        if (n_int == NULL)
            return;
		*n_int = (int)n;
		new_node = ft_lstnew(n_int);
		if (new_node == NULL)
		{
			ft_lstclear(&new_node, del);
			del(n_int);
            return;
		}
        ft_lstadd_back(one_stack, new_node);
        i++;
    }
}
