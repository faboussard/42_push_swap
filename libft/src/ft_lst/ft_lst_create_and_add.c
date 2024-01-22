/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:46:22 by faboussa          #+#    #+#             */
/*   Updated: 2023/11/11 08:46:22 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*create_and_add(const char *av, t_node_int **one_stack)
{
	int			n;
	t_node_int	*new_node;

	n = ft_atoi(av);
	new_node = ft_lstnew(n);
	if (new_node == NULL)
	{
		ft_lstclear(&new_node);
		write(2, "Error\n", 7);
		return (NULL);
	}
	ft_lstadd_back(one_stack, new_node);
	return (one_stack);
}
