# ifndef PUSH_SWAP_h
# define PUSH_SWAP_h

#include "libft.h"
#include <limits.h>
typedef struct b_list
{
	int				content;
	int				split;
	struct b_list	*next;
}				t_lst;
void	push_stack(t_lst **src, t_lst **dest);
void	rotate_stack(t_lst	**headRef);
void	rrotate_stack(t_lst	**headRef);
void	ps_lstadd_back(t_lst **lst, int value);
void	swap_stack(t_lst **headRef);
void	print_stack(t_lst *stack);
int		find_min(t_lst *head, int split_num);
int		find_mid_num(t_lst **headRef);
int		lst_len(t_lst *head);
int		ft_isnum(char *s);
t_lst	*last_item(t_lst *head);
t_lst	*ps_lstnew(int content);
# endif