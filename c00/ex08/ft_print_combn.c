/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ft_print_combn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:10:40 by dachung           #+#    #+#             */
/*   Updated: 2020/02/08 10:16:16 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_rule(int *arr, int i)
{
	int j;

	j = i - 1;
	while (j >= 0)
	{
		if (arr[i] == arr[j] || arr[i] < arr[j])
			return (0);
		j--;
	}
	return (1);
}

void	ft_combn(int i, int *arr, int n)
{
	int		num;
	char	c;

	if (i == n)
	{
		i = 0;
		while (i < n)
		{
			c = arr[i] + '0';
			write(1, &c, 1);
			i++;
		}
		if (arr[i - n] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	num = 0;
	while (num < 10)
	{
		arr[i] = num;
		if (check_rule(arr, i) == 1)
			ft_combn(i + 1, arr, n);
		num++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[n];

	ft_combn(0, arr, n);
}
