# ifndef PUSH_SWAP_h
# define PUSH_SWAP_h

#include "libft.h"
#include <limits.h>
typedef struct b_list
{
	int				content;
	struct b_list	*next;
}				t_lst;
int	ft_isnum(char *s);
t_lst	*ps_lstnew(int content);
void	ps_lstadd_back(t_lst **lst, int value);
# endif