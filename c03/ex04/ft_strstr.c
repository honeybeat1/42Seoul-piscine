/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:50:55 by dachung           #+#    #+#             */
/*   Updated: 2020/02/02 00:27:45 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int m;

	i = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i] != 0)
	{
		if (str[i] == to_find[0])
		{
			m = i;
			j = 0;
			while ((to_find[j] != 0) && (str[m] != 0))
			{
				if (to_find[j] != str[m++])
					break ;
				j++;
			}
			if (to_find[j] == 0)
				return (str + i);
		}
		i++;
	}
	return (0);
}
