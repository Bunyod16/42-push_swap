/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <bshamsid@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:18:35 by bshamsid          #+#    #+#             */
/*   Updated: 2021/09/30 14:04:43 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str)
{
	return ((*str >= 8 && *str <= 13) || *str == 32 );
}

static long long	char_to_int(const char *str)
{
	long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res = res + (*str - 48);
		str++;
		if (res > 2147483648)
			return (res);
	}
	return (res);
}

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (str[0] == '0')
		return (0);
	while (ft_isspace(str) != 0)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	result = sign * char_to_int(str);
	return (result);
}
