/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:45:29 by dachung           #+#    #+#             */
/*   Updated: 2020/01/29 18:10:14 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	dec_to_hex(char c)
{
	int		r;
	int		q;

	ft_putchar('\\');
	q = c / 16;
	r = c % 16;
	ft_putchar(q + '0');
	if (r < 10)
		c = 48 + r;
	if (r >= 10)
		c = 87 + r;
	ft_putchar(c);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (31 < str[i] && str[i] < 127)
			ft_putchar(str[i]);
		else
			dec_to_hex(str[i]);
		i++;
	}
}
