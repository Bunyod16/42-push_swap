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
int		sorted(char **argv);
void	push_stack(t_lst **src, t_lst **dest, char *str);
void	rotate_stack(t_lst	**headRef, char *str);
void	rrotate_stack(t_lst	**headRef, char *str);
void	swap_stack(t_lst **headRef, char *str);
void	ps_lstadd_back(t_lst **lst, int value);
int		find_mid_num(t_lst **headRef);
int		lst_len(t_lst *head);
int		ft_isnum(char *s);
t_lst	*last_item(t_lst *head);
t_lst	*ps_lstnew(int content);
# endif