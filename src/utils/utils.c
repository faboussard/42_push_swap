#include "../../inc/push_swap.h"

void    del(void *content)
{
	if (content)
		free(content);
}

t_node	*get_stack_bottom(t_node *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_node	*get_stack_before_bottom(t_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}