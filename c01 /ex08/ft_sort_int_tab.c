/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 01:13:26 by dachung           #+#    #+#             */
/*   Updated: 2020/01/27 18:13:28 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int n;
	int i;
	int min;
	int temp;

	n = 0;
	while (n < size - 1)
	{
		min = n;
		i = n + 1;
		while (i < size)
		{
			if (tab[min] > tab[i])
				min = i;
			i++;
		}
		if (min != n)
		{
			temp = tab[n];
			tab[n] = tab[min];
			tab[min] = temp;
		}
		n++;
	}
}
