/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:56:27 by dachung           #+#    #+#             */
/*   Updated: 2020/02/06 19:35:55 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_count = 0;

void	print_answer(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

int		ft_abs(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}

int		check_rule(int *arr, int col)
{
	int i;

	i = col - 1;
	while (i >= 0)
	{
		if (arr[col] == arr[i] ||
			ft_abs(arr[col], arr[i]) == ft_abs(col, i))
			return (0);
		i--;
	}
	return (1);
}

void	insert_queens(int *arr, int col)
{
	int num;

	if (col == 10)
	{
		g_count++;
		print_answer(arr);
		write(1, "\n", 1);
		return ;
	}
	num = 0;
	while (num < 10)
	{
		arr[col] = num;
		if (check_rule(arr, col) == 1)
			insert_queens(arr, col + 1);
		num++;
	}
	return ;
}

int		ft_ten_queens_puzzle(void)
{
	int arr[10];
	int col;

	col = 0;
	insert_queens(arr, col);
	return (g_count);
}
