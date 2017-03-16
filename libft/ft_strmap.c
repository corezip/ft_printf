/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:13:27 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/12 16:13:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*x;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(x = malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		x[i] = (*f)(s[i]);
		i++;
	}
	x[i] = '\0';
	return (x);
}
