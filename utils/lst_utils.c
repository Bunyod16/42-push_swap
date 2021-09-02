#include "../push_swap.h"
#include <stdio.h>

t_lst	*ps_lstnew(int content)
{
	t_lst	*ret;

	ret = (t_lst *)malloc(sizeof(t_lst));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->split = 0;
	ret->next = NULL;
	return (ret);
}

int	lst_len(t_lst *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return i;
}

void	ps_lstadd_back(t_lst **lst, int value)
{
	t_lst	*node;
	// t_lst	*copy;

	// copy = *lst;
	if (!*lst)
	{
		node = malloc(sizeof(t_lst *));
		node->content = value;
		node->next = NULL;
		node->split = 0;
		*lst = node;
	}
	else
	{
		while (*lst)
			lst = &(*lst)->next;
		node = ps_lstnew(value);
		*lst = node;
	}
}

t_lst	*last_item(t_lst *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int		find_min(t_lst *head, int split_num)
{
	int	min;

	if (!head)
		return 0;
	min = head->content;
	while (head)
	{
		if (head->content > min && head->split == split_num)
			min = head->content;
		head = head->next;
	}
	return (min);
}