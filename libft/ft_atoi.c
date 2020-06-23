/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:06:38 by mleticia          #+#    #+#             */
/*   Updated: 2019/04/23 16:09:36 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(int i)
{
	if (i < 0)
		return (0);
	else
		return (-1);
}

int				ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == ' ' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((result * 10 + (*str - '0')) / 10 != result)
			return (ft_check(sign));
		else
			result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)result * sign);
}
