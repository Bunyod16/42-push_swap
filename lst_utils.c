#include "push_swap.h"
#include <stdio.h>

t_lst	*ps_lstnew(int content)
{
	t_lst	*ret;

	ret = (t_lst *)malloc(sizeof(t_lst));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

void	ps_lstadd_back(t_lst **lst, t_lst *copy, int value)
{
	t_lst	*node;

	if (!*lst)
	{
		node = malloc(sizeof(t_lst));
		node->content = value;
		node->next = NULL;
		*lst = node;
	}
	else
	{
		while (copy->next)
			copy = copy->next;
		node = malloc(sizeof(t_lst));
		copy->next = node;
		node->content = value;
		node->next = NULL;
	}
}