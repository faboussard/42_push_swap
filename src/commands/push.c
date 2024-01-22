/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:33:26 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/22 18:00:42 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_head(t_node_int **src_stack_head, t_node_int **dest_stack_head)
{
	t_node_int	*temp;

	if (src_stack_head == NULL)
		return ;
	temp = (*src_stack_head)->next;
	(*src_stack_head)->next = NULL;
	ft_lstadd_front(dest_stack_head, *src_stack_head);
	*src_stack_head = temp;
}

void	do_pa(t_node_int **a_stack, t_node_int **b_stack)
{
	push_head(a_stack, b_stack);
	ft_printf("pa\n");
}

void	do_pb(t_node_int **a_stack, t_node_int **b_stack)
{
	push_head(b_stack, a_stack);
	ft_printf("pb\n");
}
