#include "push_swap.h"

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

void	ps_lstadd_back(t_lst *lst, t_lst *new)
{
	t_lst *newl;

	newl = malloc(sizeof(t_lst));
	newl->content = new->content;
	newl->next = NULL;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = newl;
	return ;
}