/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <bshamsid@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:25:49 by bshamsid          #+#    #+#             */
/*   Updated: 2021/10/01 02:25:49 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_lst **h, char	*sa, char *rra)
{
	if ((*h)->content > (*h)->next->content)
	{
		swap_stack(h, sa);
		if ((*h)->next->content > (*h)->next->next->content)
			rrotate_stack(h, rra);
	}
	if ((*h)->content > (*h)->next->content)
		swap_stack(h, sa);
	if ((*h)->next->content > (*h)->next->next->content)
		rrotate_stack(h, rra);
	if ((*h)->content > (*h)->next->content)
		swap_stack(h, sa);
}

void	sort_2(t_lst **h, char *str)
{
	if ((*h)->content > (*h)->next->content)
		swap_stack(h, str);
}

void	sort_halves(t_lst **headRef, t_lst **stack_b)
{
	if (lst_len(*headRef) == 2)
		sort_2(headRef, "sa\n");
	if (lst_len(*headRef) == 3)
		sort_3(headRef, "sa\n", "rra\n");
	if (lst_len(*stack_b) == 2)
		sort_2(stack_b, "sb\n");
	if (lst_len(*stack_b) == 3)
		sort_3(stack_b, "sb\n", "rrb\n");
}

void	insertion_sort(t_lst **headRef, t_lst **stack_b)
{
	while (*stack_b)
	{	
		if ((*stack_b)->content > lst_max(headRef))
		{
			while ((*headRef)->content != lst_min(headRef))
				rotate_stack(headRef, "ra\n");
			push_stack(stack_b, headRef, "pa\n");
		}
		else if ((*stack_b)->content < (*headRef)->content)
			push_stack(stack_b, headRef, "pa\n");
		else
			rotate_stack(headRef, "ra\n");
	}
	while ((*headRef)->content != lst_min(headRef))
		rotate_stack(headRef, "ra\n");
}

void	split_half(t_lst **headRef, t_lst **stack_b)
{
	int	len;
	int	i;

	i = 0;
	len = lst_len(*headRef);
	while (len - ++i > (len / 2))
		push_stack(headRef, stack_b, "pb\n");
}
