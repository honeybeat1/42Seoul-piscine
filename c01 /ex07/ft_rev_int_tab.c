/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 00:09:08 by dachung           #+#    #+#             */
/*   Updated: 2020/01/27 01:11:41 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int num;
	int temp;

	num = size / 2;
	while (num > 0)
	{
		temp = tab[num - 1];
		tab[num - 1] = tab[size - num];
		tab[size - num] = temp;
		num--;
	}
}
