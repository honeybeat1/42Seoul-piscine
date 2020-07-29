/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:17:48 by dachung           #+#    #+#             */
/*   Updated: 2020/02/10 14:27:58 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != 0)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_row_count(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		while (str[i] != 0 && is_charset(str[i++], charset) == 0)
			;
		count++;
	}
	return (count);
}

void	ft_strcpy(char *str, char *from, char *to)
{
	while (from < to)
	{
		*(str++) = *(from++);
	}
	*str = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		size;
	int		from;
	int		index;

	size = ft_row_count(str, charset);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], charset) == 0)
		{
			from = i;
			while (str[i] != '\0' && is_charset(str[i], charset) == 0)
				i++;
			arr[index] = (char *)malloc(sizeof(char) * (i - from) + 1);
			ft_strcpy(arr[index], &str[from], &str[i]);
			index++;
		}
		i++;
	}
	arr[index] = 0;
	return (arr);
}
