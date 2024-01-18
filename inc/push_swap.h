#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include "../libft/inc/libft.h"

//suppr pour evakl
#include <stdio.h>

enum sort_one {SWAP_ONE, ROTATE_ONE, REV_ROTATE_ONE};
enum sort_both {SWAP_BOTH, ROTATE_BOTH, REV_ROTATE_BOTH, PUSH_HEAD};
enum status {NON_OK, OK};

//***Handle errors
void	check_errors_and_init_stack(t_node **one_stack, const char **av, int ac);

//***commands
void swap_one(t_node **head);
void swap_both(t_node **first_stack_head, t_node **second_stack_head);
void rotate_one(t_node **head);
void rotate_both(t_node **first_stack_head, t_node **second_stack_head);
void rev_rotate_one(t_node **head);
void rev_rotate_both(t_node **first_stack_head, t_node **second_stack_head);
void push_head(t_node **src_stack_head, t_node **dest_stack_head);
void ft_move_one(enum sort_one command, t_node **one_stack);
void ft_move_both(enum sort_both command, t_node **first_stack, t_node **second_stack);

//***sorting
void sort_3_elements(t_node *one_stack);
void sort_4_elements(t_node *one_stack);

//***utils
void    del(void *content);
t_node *find_node_with_max_value(t_node *head);
int is_stack_sorted(t_node *one_stack);

#endif //PUSH_SWAP_PUSH_SWAP_H
