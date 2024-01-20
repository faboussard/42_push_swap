#include "../../inc/push_swap.h"

void rotate_one(t_node_int **head)
{
	t_node_int *is_last;

	if (!head || !*head || !(*head)->next)
		return;
	is_last = ft_lstlast(*head);
	is_last->next = *head;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	is_last->next->prev = is_last;
	is_last->next->next = NULL;
}

void do_ra(t_node_int **head)
{
    rotate_one(head);
    ft_printf("ra\n");
}

void do_rb(t_node_int **head)
{
    rotate_one(head);
    ft_printf("rb\n");
}