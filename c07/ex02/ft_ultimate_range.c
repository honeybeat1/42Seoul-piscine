/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:38:57 by dachung           #+#    #+#             */
/*   Updated: 2020/02/11 19:59:16 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	long	diff;
	int		*temp;

	if (min >= max)
		return (0);
	diff = max - min;
	temp = (int *)malloc(sizeof(int) * diff);
	*range = temp;
	if (*range == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		temp[i] = min;
		i++;
		min++;
	}
	return (diff);
}
