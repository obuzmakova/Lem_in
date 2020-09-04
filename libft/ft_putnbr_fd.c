/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:57:38 by mleticia          #+#    #+#             */
/*   Updated: 2019/04/24 21:01:35 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	i = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = (unsigned int)(-n);
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((i % 10 + '0'), fd);
}
