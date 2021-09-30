#include "../push_swap.h"

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
	}
}
