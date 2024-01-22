/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:33:26 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/22 18:00:42 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap_one(t_node_int **head)
{
	int	index;
	int	content;

	if (!head || !*head || !(*head)->next)
		return ;
	content = (*head)->next->content;
	index = (*head)->next->index;
	(*head)->next->content = (*head)->content;
	(*head)->next->index = (*head)->index;
	(*head)->content = content;
	(*head)->index = index;
}

void	do_sa(t_node_int **head)
{
	swap_one(head);
	ft_printf("sa\n");
}

void	do_sb(t_node_int **head)
{
	swap_one(head);
	ft_printf("sb\n");
}
