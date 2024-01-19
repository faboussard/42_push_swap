#include "../../inc/push_swap.h"

void rotate_one(t_node_int **head) //  1 2 3 4
{
	t_node_int *is_last;

	if (!head || !*head || !(*head)->next)
		return;
	is_last = ft_lstlast(*head); //4
	is_last->next = *head; // 4 ->NULL = 1
	(*head) = (*head)->next;// 1  = 2
	(*head)->prev = NULL; // ->2 = null
	is_last->next->prev = is_last; // rotationdu premier au dernier
	is_last->next->next = NULL;
}

void rotate_both(t_node_int **first_stack_head, t_node_int **second_stack_head)
{
    rotate_one(first_stack_head);
    rotate_one(second_stack_head);
}