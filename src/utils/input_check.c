/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:16:47 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/22 18:01:12 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	syntax(const char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (NOT_OK);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (NOT_OK);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (NOT_OK);
	}
	return (OK);
}

static int	error_duplicate(t_node_int *one_stack, int n)
{
	while (one_stack)
	{
		if (one_stack->content == n)
			return (NOT_OK);
		one_stack = one_stack->next;
	}
	return (OK);
}

int	check_errors_and_init_stack(t_node_int **a, char **av, int ac)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		split = ft_split(av[i], ' ');
		if (split == NULL)
			return (0);
		while (split[++j])
		{
			if ((ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				|| (syntax(split[j]) == 0)
				|| (error_duplicate(*a, (int)(ft_atol(split[j]))) == 0)
				|| (create_and_add(split[j], a) == 0))
			{
				ft_lstclear(a);
				return (NOT_OK);
			}
		}
		free_split(split);
	}
	return (OK);
}
