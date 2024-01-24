/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:03:50 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/24 12:03:50 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_3_elements(t_node_int **a_stack)
{
	t_node_int	*max_value_node;

	max_value_node = find_node_with_max_value(*a_stack);
	if (max_value_node == *a_stack)
		do_ra(a_stack);
	if ((*a_stack)->next == max_value_node)
		do_rra(a_stack);
	if ((*a_stack)->content > (*a_stack)->next->content)
		do_sa(a_stack);
}

void	sort_twenty(t_node_int **a_stack, t_node_int **b_stack)
{
	t_node_int	*current;

	current = *a_stack;
	while (ft_lstsize(*b_stack) < ft_lstsize(*a_stack) - 1)
	{
		if (current->index == 0 || current->index == 1)
			do_pb(b_stack, a_stack);
		else
			do_ra(a_stack);
		current = *a_stack;
	}
	while (!is_stack_sorted(*a_stack))
	{
		if (ft_lstsize(*b_stack) > 0 && (*b_stack)->index == 0)
			do_sb(b_stack);
		if ((*a_stack)->index != find_min(*a_stack))
			do_rra(a_stack);
		else
			do_pb(b_stack, a_stack);
	}
	while (ft_lstsize(*b_stack) != 0)
		do_pa(b_stack, a_stack);
}
