/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_ft_strcapitalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:07:13 by dachung           #+#    #+#             */
/*   Updated: 2020/01/29 22:29:51 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

char	ft_up(char ch)
{
	int dis;
	int i;

	i = 0;
	dis = 'a' - 'A';
	if (ch >= 'a' && ch <= 'z')
		ch = ch - dis;
	return (ch);
}

char	ft_low(char ch)
{
	int dis;
	int i;

	i = 0;
	dis = 'a' - 'A';
	if (ch >= 'A' && ch <= 'Z')
		ch = ch + dis;
	return (ch);
}

int		is_alpha_or_num(char ch)
{
	if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')
			|| (ch >= 'a' && ch <= 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = ft_up(str[0]);
	while (str[i] != 0)
	{
		if (is_alpha_or_num(str[i]) == 0 && is_alpha_or_num(str[i + 1]) == 1)
			str[i + 1] = ft_up(str[i + 1]);
		else if (is_alpha_or_num(str[i]) == 1
				&& is_alpha_or_num(str[i + 1]) == 1)
			str[i + 1] = ft_low(str[i + 1]);
		i++;
	}
	return (str);
}
