/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:58:45 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/19 01:27:39 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	if (!s)
		return ;
	while (*s)
	{
		c = *s;
		write(fd, &c, 1);
		s++;
	}
	c = '\n';
	write(fd, &c, 1);
}
