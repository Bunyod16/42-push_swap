#include "push_swap.h"

void	error_check(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc < 2 || sorted(argv))
		exit (0);
	while (argv[i])
	{
		if(!ft_isnum(argv[i]))
		{
			ft_putstr_fd("Error\n", 1);
			exit (0);
		}
		j = 0;
		while (argv[++j])
		{
			if ((ft_atoi(argv[j]) == ft_atoi(argv[i]) && j != i) ||
			(ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN))
			{
				ft_putstr_fd("Error\n", 1);
				exit (0);
			}
		}
		i++;
	}
}

void	small_sort(t_lst **headRef)
{
	t_lst	*stack_b;

	stack_b = NULL;
	if (*headRef == NULL)
		return ;
	convert_to_places(headRef);
	split_half(headRef, &stack_b);
	sort_halves(headRef, &stack_b);
	insertion_sort(headRef, &stack_b);
}

void	radix_sort(t_lst **headRef)
{
	t_lst	*stack_b;

	if (*headRef == NULL)
		return ;
	stack_b = NULL;
	convert_to_places(headRef);
	sort_bitwise(headRef, &stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_lst	*stack_a;
	t_lst	*temp;
	i = 0;

	error_check(argc, argv);
	while (++i < argc)
	{
		if (i == 1)
			stack_a = ps_lstnew(ft_atoi(argv[i]));
		else
			ps_lstadd_back(&stack_a, ft_atoi(argv[i]));
	}
	if (argc > 6)
		radix_sort(&stack_a);
	else
		small_sort(&stack_a);
	while(stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
}