#include "push_swap.h"
#include <stdio.h>

/// old below 
void swap_nodes(t_lst **head,t_lst *temp_head, t_lst *min, t_lst *old_min)
{
	t_lst *temp;
	
	*head = min;
	old_min->next = temp_head;
	temp = min->next;
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

void rssort(t_lst **head)
{
	if (head == NULL)
		return ;
	*head = recursive_selection_sort(*head);
}

void	print_stack(t_lst *stack)
{
	while (stack)
	{
		printf("-%d-",stack->content);
		stack = stack->next;
	}
}
/// old ^^^

void	maxsort(t_lst **headRef)
{
	t_lst	*head;
	t_lst	*min_ref;
	t_lst	*stack_b;
	int		num;

	stack_b = NULL;
	head = *headRef;
	num = INT_MAX;
	if (head == NULL)
		return ;
	while (head)
	{
		if (head->content <= num)
		{
			num = head->content;
			min_ref = head;
		}
		head = head->next;
	}
	head = *headRef;
	while (head != min_ref)
	{
		rotate_stack(headRef);
		head = *headRef;
	}
	push_stack(headRef, &stack_b);
	while ((*headRef))
	{
		push_stack(headRef, &stack_b);
		if (stack_b->content < stack_b->next->content)
			swap_stack(&stack_b);
	}
	print_stack(stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_lst	*stack_a;
	t_lst	*temp;
	t_lst	*stack_b;

	i = 0;
	stack_a = NULL;
	stack_b = malloc(sizeof(t_lst *));
	stack_b->content = 5;
	stack_b->next = NULL;
	while (argv[++i] && argc > 1)
	{
		if(!ft_isnum(argv[i]) || ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			ft_putstr_fd("Invalid input", 1);
			return (0);
		}
		ps_lstadd_back(&stack_a, stack_a, ft_atoi(argv[i]));
	}
	// rssort(&stack_a);
	maxsort(&stack_a);
	while(stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
}