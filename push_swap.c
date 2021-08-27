#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_lst *stack)
{
	while (stack)
	{
		printf("-%d-",stack->content);
		stack = stack->next;
	}
}

// void	push_stack(t_lst *from, t_lst *to)
// {
// 	int		new_value;
// 	int		temp;

// 	new_value = from->content;
// 	while (from)
// 	{
// 		from->content = from->next->content;
// 		if (from->next->next == NULL)
// 		{
// 			free(from->next);
// 			from->next = NULL;
// 			break;
// 		}
// 		from = from->next;
// 	}
// 	while (to->next)
// 	{
// 		to->content = to->next->content;
// 		to = to->next;
// 	}
// 	to->next = ps_lstnew(temp);
// } 

int	main(int argc, char **argv)
{
	int	i;
	t_lst *stack_a;

	i = 0;
	stack_a = NULL;
	while (argv[++i] && argc > 1)
	{
		if(!ft_isnum(argv[i]) || ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			ft_putstr_fd("Invalid input", 1);
			return (0);
		}
		ps_lstadd_back(&stack_a, stack_a, ft_atoi(argv[i]));
	}
	// sort(stack_a)
	print_stack(stack_a);
}