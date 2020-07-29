/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:16:37 by dachung           #+#    #+#             */
/*   Updated: 2020/01/25 22:22:56 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	l_num;

	l_num = nb;
	if (l_num < 0)
	{
		ft_putchar('-');
		l_num = -l_num;
	}
	if (l_num < 10)
	{
		ft_putchar(l_num + '0');
	}
	else
	{
		ft_putnbr(l_num / 10);
		ft_putnbr(l_num % 10);
	}
}
