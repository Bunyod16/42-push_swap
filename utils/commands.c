#include "../push_swap.h"

void	push_stack(t_lst **src, t_lst **dest)
{
	t_lst	*temp;
	t_lst	*temp2;

	if (!*dest)
	{
		temp = (*src)->next;
		*dest = (*src);
		(*dest)->next = NULL;
		(*src) = temp;	
	}
	else
	{
		temp = *dest;
		temp2 = (*src)->next;
		*dest = (*src);
		(*dest)->next = temp;
		*src = temp2;
	}
}

void	rotate_stack(t_lst	**headRef)
{
	t_lst	*temp;
	t_lst	*head;
	t_lst	*second_node;

	if ((*headRef)->next == NULL || !*headRef)
		return;
	head = *headRef;
	temp = *headRef;
	second_node = (*headRef)->next;
	while(head->next)
		head = head->next;
	head->next = temp;
	temp->next = NULL;
	*headRef = second_node;
}

void	rrotate_stack(t_lst	**headRef)
{
	t_lst	*temp;
	t_lst	*head;
	t_lst	*second_node;

	if ((*headRef)->next == NULL || !*headRef)
		return;
	head = *headRef;
	temp = *headRef;
	while(head->next)
	{
		if (head->next->next == NULL)
			second_node = head;
		head = head->next;
	}
	*headRef = head;
	head->next = temp;
	second_node->next = NULL;
}

void	swap_stack(t_lst **headRef)
{
	t_lst	*temp;
	t_lst	*head;

	if (!(*headRef) || !(*headRef)->next)
		return;
	head = *headRef;
	temp = (*headRef)->next;
	head->next = temp->next;
	*headRef = temp;
	temp->next = head;
}