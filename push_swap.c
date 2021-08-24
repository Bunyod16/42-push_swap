#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	t_lst *stack_a;
	t_lst *new;

	i = 0;
	while (argv[++i] && argc > 1)
	{
		if(!ft_isnum(argv[i]) || ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			ft_putstr_fd("Invalid input", 1);
			return (0);
		}
		if (i == 1)
			stack_a = ps_lstnew(ft_atoi(argv[i]));
		else
		{
			new = malloc(sizeof(t_lst));
			new->content = ft_atoi(argv[i]);
			new->next = NULL;
			ps_lstadd_back(stack_a, new);
		}
	}
	while (stack_a && argc > 1)
	{
		printf("%d\n",stack_a->content);
		stack_a = stack_a->next;
	}
}