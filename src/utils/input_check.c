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
		return (NOK);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (NOK);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (NOK);
	}
	return (OK);
}

static int	error_duplicate(t_node_int *one_stack, int n)
{
	while (one_stack)
	{
		if (one_stack->content == n)
			return (NOK);
		one_stack = one_stack->next;
	}
	return (OK);
}

static int	error_check(t_node_int **one_stack, char *s)
{
	if ((ft_atol(s) > INT_MAX || ft_atol(s) < INT_MIN) || (syntax(s) == 0)
		|| (error_duplicate(*one_stack, (int)(ft_atol(s))) == 0)
		|| create_and_add(s, one_stack) == NULL)
		return (NOK);
	else
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
			if (error_check(a, split[j]) == NOK)
			{
				if (a != NULL)
					ft_lstclear(a);
				return (free_split(split), NOK);
			}
		}
		free_split(split);
	}
	if (*a == NULL)
		return (NOK);
	return (OK);
}
