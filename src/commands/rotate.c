/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:49:05 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/22 18:00:42 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate_one(t_node_int **head)
{
	t_node_int	*is_last;
	t_node_int	*new_last;
	t_node_int	*new_first;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	is_last = ft_lstlast(*head);
	if (*head == is_last)
		return ;
	new_last = *head;
	is_last->next = new_last;
	new_first = (*head)->next;
	new_last->next = NULL;
	(*head) = new_first;
}

void	do_ra(t_node_int **head)
{
	rotate_one(head);
	ft_printf("ra\n");
}

void	do_rb(t_node_int **head)
{
	rotate_one(head);
	ft_printf("rb\n");
}
