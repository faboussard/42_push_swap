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
		return (0);
	if (check_errors_and_init_stack(&a_stack, av, ac) == NOK)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	if ((is_stack_sorted(a_stack)) == OK)
		return (ft_lstclear(&a_stack), 0);
	init_index(&a_stack);
	if (ac == 4)
		sort_3_elements(&a_stack);
	else if (ac < 20)
		sort_twenty(&a_stack, &b_stack);
	else
		radix_sort(&a_stack, &b_stack);
	ft_lstclear(&a_stack);
	ft_lstclear(&b_stack);
	return (0);
}
