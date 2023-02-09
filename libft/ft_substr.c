/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:40:06 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 12:26:12 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_initmal(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (len > ft_strlen(s) - start)
		res = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
	{
		if (len <= ft_strlen(s))
			res = malloc(sizeof(char) * (len + 1));
		else
			res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	}
	if (!res)
		return (0);
	return (res);
}

char	*ft_boucle(char const *s, unsigned int start, size_t len, char *res)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start)
		{
			if (s[i] && j < len)
			{
				res[j] = s[i];
				j++;
			}
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		res = malloc(sizeof(char) * 1);
		if (!res)
			return (0);
		res[0] = '\0';
		return (res);
	}
	res = ft_initmal(s, start, len);
	res = ft_boucle(s, start, len, res);
	return (res);
}
