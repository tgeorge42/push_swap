/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:45:16 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 12:30:30 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	long	nb;
	int		i;

	i = 0;
	nb = nbr;
	if (nb >= 16)
	{
		i += ft_putnbr_base(nb / 16, base);
		i += ft_putnbr_base(nb % 16, base);
	}
	else
	{
		write(1, &base[nb % 16], 1);
		i++;
	}
	return (i);
}

int	ft_put_hexamin(int nbr)
{
	int	i;

	i = 0;
	i += ft_putnbr_base(nbr, "0123456789abcdef");
	return (i);
}

int	ft_put_hexamaj(int nbr)
{
	int	i;

	i = 0;
	i += ft_putnbr_base(nbr, "0123456789ABCDEF");
	return (i);
}
