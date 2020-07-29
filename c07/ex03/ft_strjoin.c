/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:43:15 by dachung           #+#    #+#             */
/*   Updated: 2020/02/10 17:30:16 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_all_len(int size, char **strs, char *sep)
{
	int i;
	int j;
	int len;
	int sep_sum;

	i = 0;
	len = 0;
	sep_sum = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++] != 0)
			len++;
		i++;
	}
	while (size > 1)
	{
		i = 0;
		while (sep[i] != 0)
			i++;
		sep_sum += i;
		size--;
	}
	len = len + sep_sum;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		all_len;
	char	*arr;
	int		i;
	int		j;
	int		m;

	all_len = ft_all_len(size, strs, sep);
	arr = (char *)malloc(sizeof(char) * (all_len + 1));
	if (arr == 0)
		return (0);
	i = 0;
	m = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
			arr[m++] = strs[i][j++];
		j = 0;
		if (i < size - 1)
			while (sep[j] != 0)
				arr[m++] = sep[j++];
		i++;
	}
	arr[m] = '\0';
	return (arr);
}
