#include "../push_swap.h"

void swap_nodes(t_lst **head,t_lst *temp_head, t_lst *min, t_lst *old_min)
{
	t_lst *temp;
	
	if (*head)
		*head = min;
	if (old_min)
		old_min->next = temp_head;
	temp = min->next;
	if (temp_head->next)
		min->next = temp_head->next;
	temp_head->next = temp;
}

t_lst *recursive_selection_sort(t_lst *head)
{
	t_lst	*min;
	t_lst	*old_min;
	t_lst	*temp;

	if (head->next == NULL)
		return head;
	min = head;
	temp = head;
	while(temp->next != NULL)
	{
		if (temp->next->content < min->content)
		{
			min = temp->next;
			old_min = temp;
		}
		temp = temp->next;
	}
	if (min != head)
		swap_nodes(&head, head, min, old_min);
	head->next = recursive_selection_sort(head->next);
	return head;
}

t_lst	*rssort(t_lst **head)
{
	t_lst	*temp;
	t_lst	*new;

	if (head == NULL)
		return (NULL);
	temp = *head;
	if (temp)
	{
		new = ps_lstnew(temp->content);
		temp = temp->next;
	}
	while (temp)
	{
		ps_lstadd_back(&new, temp->content);
		temp = temp->next;
	}
	return (recursive_selection_sort(new));
}

int	find_mid_num(t_lst **headRef)
{
	t_lst	*new;
	t_lst	*temp;
	t_lst	*ref;
	int		i; 
	int		len;

	if (!*headRef)
		return (0);
	new = rssort(headRef);
	ref = new;
	len = lst_len(new);
	i = 0;
	while (i++ < len/2)
		new = new->next;
	i = new->content;
	while(ref)
	{
		temp = ref->next;
		free(ref);
		ref = temp;
	}
	return (i);
}