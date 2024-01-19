#include "../../inc/push_swap.h"

void push_head(t_node_int **src_stack_head, t_node_int **dest_stack_head)
{
	t_node_int *temp;

    if (src_stack_head == NULL)
        return;
    temp = (*src_stack_head)->next;
   (*src_stack_head)->next=NULL;
    ft_lstadd_front(dest_stack_head, *src_stack_head);
    *src_stack_head = temp;
}