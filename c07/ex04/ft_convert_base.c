/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:10:10 by dachung           #+#    #+#             */
/*   Updated: 2020/02/11 16:31:23 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *base);
int		is_in_base(char c, char *base);
int		ft_base_error(char *base);
char	*ft_strcat(char *dest, char c);
void	ft_preprocess(long *num, int nbr, char **conv_num);

char	*ft_putnbr_base(long num, char *base, char *conv_num)
{
	int		base_length;

	base_length = ft_len(base);
	if (num < base_length)
		conv_num = ft_strcat(conv_num, base[num]);
	else
	{
		ft_putnbr_base(num / base_length, base, conv_num);
		ft_putnbr_base(num % base_length, base, conv_num);
	}
	return (conv_num);
}

char	*ft_conv_num(int nbr, char *base)
{
	long	num;
	char	*conv_num;

	num = (long)nbr;
	ft_preprocess(&num, nbr, &conv_num);
	conv_num = ft_putnbr_base(num, base, conv_num);
	return (conv_num);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int result;
	int sign;
	int length;

	i = 0;
	result = 0;
	sign = 1;
	length = ft_len(base);
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (is_in_base(str[i], base) != 0)
	{
		result = length * result + is_in_base(str[i++], base) - 1;
		if (is_in_base(str[i], base) == 0)
			return (result * sign);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal_num;
	char	*conv_num;

	if (ft_base_error(base_from) == 0)
		return (0);
	if (ft_base_error(base_to) == 0)
		return (0);
	decimal_num = ft_atoi_base(nbr, base_from);
	conv_num = ft_conv_num(decimal_num, base_to);
	return (conv_num);
}
