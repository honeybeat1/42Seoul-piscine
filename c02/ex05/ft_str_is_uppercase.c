/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:54:49 by dachung           #+#    #+#             */
/*   Updated: 2020/01/28 22:59:41 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	if (str[0] == 0)
		return (1);
	while (str[i] != 0)
	{
		if (64 < str[i] && str[i] < 91)
			i++;
		else
			return (0);
	}
	return (1);
}