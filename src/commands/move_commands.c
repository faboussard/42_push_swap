#include "push_swap.h"

void ft_move_one(enum sort_one command, t_node_int **one_stack)
{
    if (command == SWAP_ONE)
        swap_one(one_stack);
    if (command == ROTATE_ONE)
        rotate_one(one_stack);
    if (command == REV_ROTATE_ONE)
        rev_rotate_one(one_stack);
}

void ft_move_both(enum sort_both command, t_node_int **first_stack, t_node_int **second_stack)
{
    if (command == SWAP_BOTH)
        swap_both(first_stack, second_stack);
    if (command == ROTATE_BOTH)
        rotate_both(first_stack, second_stack);
    if (command == REV_ROTATE_BOTH)
        rev_rotate_both(first_stack, second_stack);
    if (command == PUSH_HEAD)
        push_head(first_stack, second_stack);
}
