/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <bshamsid@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:24:28 by bshamsid          #+#    #+#             */
/*   Updated: 2021/10/01 02:24:28 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_min(t_lst **headRef)
{
	t_lst	*head;
	int		min;

	head = *headRef;
	min = head->content;
	while (head)
	{
		if (head->content < min)
			min = head->content;
		head = head->next;
	}
	return (min);
}

int	lst_max(t_lst **headRef)
{
	t_lst	*head;
	int		max;

	head = *headRef;
	max = head->content;
	while (head)
	{
		if (head->content > max)
			max = head->content;
		head = head->next;
	}
	return (max);
}
