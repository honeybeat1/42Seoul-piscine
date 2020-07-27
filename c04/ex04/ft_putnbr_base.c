/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:20:48 by dachung           #+#    #+#             */
/*   Updated: 2020/02/03 19:37:22 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_length(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int		ft_print_error(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j] != 0)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long		num;
	int				length;
	char			base_num;
	int				i;

	num = nbr;
	length = ft_length(base);
	i = 0;
	if (ft_print_error(base) == 0)
		return ;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num < length)
	{
		base_num = base[num];
		write(1, &base_num, 1);
	}
	else
	{
		ft_putnbr_base(num / length, base);
		ft_putnbr_base(num % length, base);
	}
}
