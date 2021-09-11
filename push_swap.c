#include "push_swap.h"
#include <stdio.h>

void	recursive_split(t_lst **headRef, t_lst **stack_b, int midnum, int split)
{
	t_lst	*head;

	head = *headRef;
	if ((*headRef) == NULL || (*headRef)->next == NULL)
		return ;
	while (head)
	{
		if (head->content < midnum)
		{
			while(head->content != (*headRef)->content)
				rotate_stack(headRef, "ra\n");
			(*headRef)->split = split;
			push_stack(headRef, stack_b, "pb\n");
			head = *headRef;
		}
		else
			head = head->next;
	}
	recursive_split(headRef, stack_b, find_mid_num(headRef), split + 1);
}

void	back_push(t_lst **headRef, t_lst **stack_b)
{
	t_lst		*head;
	int			split;
	int			num;
	int			i;

	head = *stack_b;
	while (head)
	{
		i = 0;
		split = (*stack_b)->split;
		num = find_min(*stack_b, split);
		while (head->content != num)
				head = head->next;
		while ((*stack_b)->content != head->content)
		{
			i++;
			rotate_stack(stack_b, "rb\n");
		}
		push_stack(stack_b, headRef, "pa\n");
		while (i--)
			rrotate_stack(stack_b, "rrb\n");
		head = *stack_b;
	}
}

void	maxsort(t_lst **headRef)
{
	t_lst	*stack_b;
	if (*headRef == NULL)
		return ;
	stack_b = NULL;
	recursive_split(headRef, &stack_b, find_mid_num(headRef), 0);
	back_push(headRef, &stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_lst	*stack_a;
	t_lst	*temp;
	i = 0;

	if (argc < 2 || sorted(argv))
	return (0);
	while (++i < argc)
	{
		if(!ft_isnum(argv[i]) || argc < 2)
		{
			ft_putstr_fd("Invalid input", 1);
			return (0);
		}
		if (i == 1)
			stack_a = ps_lstnew(ft_atoi(argv[i]));
		else
			ps_lstadd_back(&stack_a, ft_atoi(argv[i]));
	}
	maxsort(&stack_a);
	while(stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
}