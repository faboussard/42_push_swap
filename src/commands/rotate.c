#include "../../inc/push_swap.h"

void rotate_one(t_node **head)
{
	void *temp;

	if (!head || !*head || !(*head)->next)
		return;
	temp = (*head)->content;
	(*head) = ((*head)->next);
	ft_lstadd_back(head, ft_lstnew(temp));
}

void rev_rotate_one(t_node **head)
{
	//t_node *last;
	t_node *new;
	t_node *current;
	//t_node *previous;

	if (!head || !*head || !(*head)->next)
		return;
	//last = ft_lstlast(*head);
	//new = ft_lstnew(last->content);
	current = *head;
	//previous = NULL;
	while (current->next)
	{
	//	previous = current;
		current = current->next;
	}
	//previous->next = NULL;
	new = ft_lstnew(current->content);
	//free(current); si jenleve un 4 en trop, sinon segfault.
	ft_lstadd_front(head, new);
}

/*
void rotate_both(t_node **first_stack_head, t_node **second_stack_head)
{
	rotate_both(first_stack_head);
	rotate_both(second_stack_head);
}
 */