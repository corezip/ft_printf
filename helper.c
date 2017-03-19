/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/17 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*reverse_array(char *s)
{
	int			i;
	int			j;
	char		*x;

	j = 0;
	i = ft_strlen(s);
	x = (char*)malloc(i);
	i -= 1;
	while (i != -1)
	{
		x[j] = s[i];
		i--;
		j++;
	}
	ft_strcpy(s, x);
	return (s);
}

char			*ft_strlowcase(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (str[i] + 32);
		}
		i++;
	}
	return (str);
}
