/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:36:58 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 12:25:47 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// 
// void	ft_tolouche(unsigned int i, char *s)
// {
// 	if (s[i] >= 'a' && s[i] <= 'z')
// 		s[i] = s[i] - 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(f)(i, s + i);
		i++;
	}
}
