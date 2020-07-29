/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:00:01 by dachung           #+#    #+#             */
/*   Updated: 2020/02/11 16:50:50 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *base)
{
	int i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

int		is_in_base(char c, char *base)
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

char	*ft_strcat(char *dest, char c)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dest[i] = c;
	i++;
	dest[i] = '\0';
	return (dest);
}

void	ft_preprocess(long *num, int nbr, char **conv_num)
{
	int length;

	length = 0;
	if (*num == 0)
		length = 1;
	if (*num < 0)
	{
		*num *= -1;
		length++;
	}
	while (*num > 0)
	{
		*num /= 10;
		length++;
	}
	*conv_num = (char *)malloc(sizeof(char) * (length + 1));
	*num = (long)nbr;
	if (*num < 0)
	{
		*num *= -1;
		(*conv_num)[0] = '-';
		(*conv_num)[1] = '\0';
	}
	else if (*num >= 0)
		(*conv_num)[0] = '\0';
}
