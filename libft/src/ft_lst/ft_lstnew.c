/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:46:22 by faboussa          #+#    #+#             */
/*   Updated: 2023/11/21 06:44:37 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"
#include  <stdio.h>

t_node_int	*ft_lstnew(int content)
{
	t_node_int	*new_element;

	new_element = malloc(sizeof(t_node));
	if (new_element == NULL)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
