#include "push_swap.h"
#include <stdio.h>

int	check_alignment(int *stack, int len)
{
	long max;

	max = INT_MIN - 1;
	while(len--)
	{
		if (*stack > max)
		{
			max = *stack;
			stack++;
		}
		else	
			return 0;
	}
	return 1;
}

int	ft_strstr(char *needle, char **haystack)
{
	int	i;

	i = 0;
	while (*haystack)
	{
		if (ft_strncmp(*haystack, needle, ft_strlen(needle) == 0))
			return 1;
		haystack++;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;
	int	*stack_b;

	i = 1;
	stack_a = malloc(sizeof(int) * argc - 1);
	stack_b = malloc(sizeof(int) * argc - 1);
	if (!stack_a || !stack_b)
		return (0);
	while (argv[i])
	{
		if(!ft_isnum(argv[i]) || ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN || ft_strnstr())
		{
			ft_putstr_fd("Invalid input", 1);
			return (0);
		}
		stack_a[i - 1] = ft_atoi(argv[i]);
		printf("%d\n", stack_a[i - 1]);
		i++;
	}
	while(!check_alignment(stack_a, argc - 1))
	{

	}
}