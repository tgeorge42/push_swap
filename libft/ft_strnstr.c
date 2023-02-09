/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:18:34 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 12:26:03 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	while (little[size])
		size++;
	if (size == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (little[j] == big[i + j] && i + j < len)
		{
			j++;
			if (j == size)
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
