#include "../inc/push_swap.h"
// if (error_syntax(av[i]) || (n > INT_MAX || n < INT_MIN) || error_duplicate(*a_stack, (int)n))
//			exit(1);
int main()
{
    t_node *b_stack;
	t_node *a_stack;

	a_stack = NULL;
	b_stack = NULL;

	const char *av[] = {"5", "25", "3", "4"};
	int ac = 4;
	//if (ac == 1 || (ac = 2 && !av[1][0]))
	//	return (EXIT_FAILURE);
	check_errors_and_init_stack(&a_stack, av, ac);
/*
	while (a_stack != NULL)
	{
		printf("test\n");
		//printf("%d\n", *(int*)a_stack->content);
		//a_stack = a_stack->next;
		printf("%d\n", *(int*)a_stack->content);
		a_stack = a_stack->next;
	}
 */

    //test pushshwap a

	ft_move_one(REV_ROTATE_ONE, &a_stack);
    while (a_stack != NULL)
    {
        printf("test_onestack\n");
        //printf("%d\n", *(int*)a_stack->content);
        //a_stack = a_stack->next;
        printf("%d\n", *(int*)a_stack->content);
        a_stack = a_stack->next;
    }

    //ft_print(command);
    //verifier que le exit failure dans la fonction retourne bien exit failure au total. ne doit absolument pas continuer
	//checker si deja trié : si retour de la fonction de tri = ok alors ne rien faire sinon trier
	/*
	if (ac == 3)
        sort_3_int(&a_stack);
	while (a_stack)
	{
		printf("%d\n",  *((int*)(*a_stack)->content));
		*a_stack = (*a_stack)->next;
	}*/
    //else
    //{
    // trier le reste
   // }
    free(a_stack);
	return 0;
}

/*
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
		$>
 */