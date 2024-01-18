#include "../../inc/push_swap.h"

int is_stack_sorted(t_node *one_stack)
{
    while (one_stack->next != NULL)
    {
        if (*(int*)one_stack->content > *(int*)one_stack->next->content)
            return (NON_OK);
        one_stack = one_stack->next;
    }
    return (OK);
}

void    del(void *content)
{
	if (content)
		free(content);
}

void find_node_with_max_value(t_node *head)
{
	t_node *max_value_node;
	t_node *current_node;
	t_node *temp;

	temp = head->next;
	current_node = head;
	max_value_node = head;
	while (current_node != NULL)
	{
		if (*(int*)current_node->content > *(int*)max_value_node->content)
			max_value_node = current_node;
		current_node = current_node->next;
	}
	max_value_node->next=NULL;
	ft_lstadd_front(&head, max_value_node);
}