/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:59:39 by dachung           #+#    #+#             */
/*   Updated: 2020/02/04 18:03:40 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long square;

	square = 0;
	while (square * square <= nb)
	{
		if (square * square == nb)
			return (square);
		square++;
	}
	return (0);
}
