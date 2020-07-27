/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:53:21 by dachung           #+#    #+#             */
/*   Updated: 2020/02/03 19:37:53 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int		ft_base_error(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == 32 || (9 <= base[i] && base[i] <= 13))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

int		check_valid(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int r;
	int sign;
	int length;

	i = 0;
	sign = 1;
	r = 0;
	length = ft_len(base);
	if (ft_base_error(base) == 0)
		return (0);
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (check_valid(str[i], base) != 0)
	{
		r = length * r + check_valid(str[i++], base) - 1;
		if (check_valid(str[i], base) == 0)
			return (r * sign);
	}
	return (0);
}
