# ifndef PUSH_SWAP_h
# define PUSH_SWAP_h

#include "libft.h"
#include <limits.h>
typedef struct b_list
{
	int				content;
	struct b_list	*next;
}				t_lst;
void	push_stack(t_lst **src, t_lst **dest);
void	rotate_stack(t_lst	**headRef);
void	rrotate_stack(t_lst	**headRef);
void	ps_lstadd_back(t_lst **lst, t_lst *copy, int value);
void	swap_stack(t_lst **headRef);
t_lst	*ps_lstnew(int content);
int	ft_isnum(char *s);
# endif