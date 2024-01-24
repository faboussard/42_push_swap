/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:57:06 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/22 18:01:12 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	get_maxbits_lst(t_node_int *one_stack)
{
	t_node_int	*current;
	int			max;
	int			max_b;

	current = one_stack;
	max = current->index;
	max_b = 0;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);
}

void	radix_sort(t_node_int **a_stack, t_node_int **b_stack)
{
	t_node_int	*current;
	int			i;
	int			j;
	int			size;
	int			max_b;

	size = ft_lstsize(*a_stack);
	max_b = get_maxbits_lst(*a_stack);
	i = -1;
	while (++i < max_b)
	{
		j = -1;
		while (++j < size)
		{
			current = *a_stack;
			if (((current->index >> i) & 1) == 0)
				do_pb(b_stack, a_stack);
			else
				do_ra(a_stack);
		}
		while (ft_lstsize(*b_stack) != 0)
			do_pa(b_stack, a_stack);
	}
}
