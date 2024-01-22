/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:33:26 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/22 18:00:42 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rev_rotate_one(t_node_int **head)
{
	t_node_int	*temp;
	t_node_int	*tail;
	t_node_int	*before_tail;

	if (!head || !*head || !(*head)->next)
		return ;
	tail = ft_lstlast(*head);
	before_tail = ft_lstbeforelast(*head);
	temp = *head;
	*head = tail;
	(*head)->next = temp;
	before_tail->next = NULL;
}

void	do_rra(t_node_int **head)
{
	rev_rotate_one(head);
	ft_printf("rra\n");
}

void	do_rrb(t_node_int **head)
{
	rev_rotate_one(head);
	ft_printf("rrb\n");
}
