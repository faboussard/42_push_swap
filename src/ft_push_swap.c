#include "../inc/push_swap.h"
// if (error_syntax(av[i]) || (n > INT_MAX || n < INT_MIN) || error_duplicate(*a_stack, (int)n))
//			exit(1);
int main()
{

	t_node_int *b_stack;
	t_node_int *a_stack;

	a_stack = NULL;
	b_stack = NULL;

	const char *av[] = {"1", "2", "3", "4", "5", "6", "7", "8"};
    const char *av2[] = {"1", "50", "9", "3"};
	int ac = 4;
	//if (ac == 1 || (ac = 2 && !av[1][0]))
	//	return (EXIT_FAILURE);
	check_errors_and_init_stack(&a_stack, av2, ac);

//    while (a_stack != NULL)
//    {
//        printf("test\n");
//        printf("%d\n", a_stack->content);
//        a_stack = a_stack->next;
//    }

    //test pushshwap a
//
//
//    ft_move_both(PUSH_HEAD, &a_stack, &b_stack);
//    ft_move_both(PUSH_HEAD, &a_stack, &b_stack);
//    ft_move_both(PUSH_HEAD, &a_stack, &b_stack);
//    ft_move_both(PUSH_HEAD, &a_stack, &b_stack);

// *******************testswap
//
	//ft_move_one(ROTATE_ONE, &a_stack);
	//ft_move_one(ROTATE_ONE, &a_stack);
//	ft_move_one(ROTATE_ONE, &a_stack);

//    ft_move_both(REV_ROTATE_BOTH, &a_stack, &b_stack);
//    ft_move_both(REV_ROTATE_BOTH, &a_stack, &b_stack);
  // ft_move_both(REV_ROTATE_BOTH, &a_stack, &b_stack);
//    ft_move_both(ROTATE_BOTH, &a_stack, &b_stack);

//    while (b_stack != NULL)
//    {
//        printf("bstack\n");
//        printf("%d\n", b_stack->content);
//        b_stack = b_stack->next;
//    }
//
//    while (a_stack != NULL)
//    {
//        printf("test_astack\n");
//        printf("%d\n", a_stack->content);
//        a_stack = a_stack->next;
//    }
//    if (is_stack_sorted(a_stack))
//        printf("%s", "sorted");
//    else
//        printf("%s", "not sorted");

	sort_4_elements(&a_stack);
    while (a_stack != NULL)
    {
        printf("test_astack\n");
        printf("%d\n", a_stack->content);
        a_stack = a_stack->next;
    }

    free(a_stack);
	free(b_stack);
	return 0;
}

/*
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
		$>
 */