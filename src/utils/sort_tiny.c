/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:01:56 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/22 18:01:56 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_3_elements(t_node_int **one_stack)
{
	t_node_int	*max_value_node;

	max_value_node = find_node_with_max_value(*one_stack);
	if (max_value_node == *one_stack)
		do_ra(one_stack);
	if ((*one_stack)->next == max_value_node)
		do_rra(one_stack);
	if ((*one_stack)->content > (*one_stack)->next->content)
		do_sa(one_stack);
}
