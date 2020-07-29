/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:15:27 by dachung           #+#    #+#             */
/*   Updated: 2020/02/07 13:32:33 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*pnt;
	int		i;

	i = 0;
	while (src[i] != 0)
		i++;
	pnt = (char *)malloc(sizeof(char) * (i + 1));
	if (pnt == 0)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		pnt[i] = src[i];
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}
