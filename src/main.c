/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:16:47 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/22 18:00:56 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_node_int	*b_stack;
	t_node_int	*a_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (ac < 2)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	if (check_errors_and_init_stack(&a_stack, av, ac) == NOT_OK)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	if ((is_stack_sorted(a_stack)) == OK)
		ft_printf("sorted");
	else if (ac == 3)
		sort_3_elements(&a_stack);
	else
	{
		init_index(&a_stack);
		radix_sort(&a_stack, &b_stack);
	}
	ft_lstclear(&a_stack);
	ft_lstclear(&b_stack);
	return (0);
}
