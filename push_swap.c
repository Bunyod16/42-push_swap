#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_lst *head)
{
	int	min;

	min = head->content;
	while(head)
	{
		printf("%d | %d\n",head->content,head->split);
		if (head->content >= min)
			min = head->content;
		else
			printf("\n\n||||NOT CORRECT||||\n\n");
		head = head->next;
	}
}


void	convert_to_places(t_lst **headRef)
{
	int		i;
	int		min;
	t_lst	*head;
	t_lst	*min_ref;

	i = -1;
	head = *headRef;
	min = head->content;
	while (lst_len(*headRef) - ++i)
	{
		head = *headRef;
		while (head)
		{
			if (head->content <= min && head->split == -1)
			{
				min = head->content;
				min_ref = head;
			}
			head = head->next;
		}
		min_ref->split = i;
		head = *headRef;
		while (head)
		{
			if (head->split == -1)
				min = head->content;
			head = head->next;
		}
	}
}

int		find_max_bit(t_lst **headRef)
{
	int		i;
	int		max;
	t_lst	*head;

	head = *headRef;
	max = 0;
	while (head)
	{
		i = 0;
		while (++i <= 31)
		{
			if ((head->split>>i & 1) == 1 && i > max)
				max = i;
		}
		head = head->next;
	}
	return (max + 1);
}

int		stack_sorted(t_lst *head)
{
	int	min;

	min = head->content;
	while(head)
	{
		if (head->content <= min)
			min = head->content;
		else
			return 0;
		head = head->next;
	}
	return (1);
}

void	sort_bitwise(t_lst **headRef, t_lst **stack_b)
{
	int			i;
	const int	biggest_bit = find_max_bit(headRef);
	int			len;
	int			j;

	i = -1;
	len = lst_len(*headRef);
	while (++i < biggest_bit)
	{
		j = 0;
		while (len - j++)
		{
			if (((*headRef)->split>>i & 1) == 1)
				rotate_stack(headRef, "ra\n");
			else
				push_stack(headRef, stack_b, "pb\n");
		}
		while (*stack_b)
			push_stack(stack_b, headRef, "pa\n");
		if (stack_sorted(*headRef))
			return ;
	}
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
	radix_sort(&stack_a);
	while(stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
}