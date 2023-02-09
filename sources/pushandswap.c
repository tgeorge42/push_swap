/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushandswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:17:01 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 12:27:08 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_list **stacka, t_list **stackb)
{
	push_elem(stacka, stackb);
	ft_printf("pa\n");
}

void	push_b(t_list **stacka, t_list **stackb)
{
	push_elem(stackb, stacka);
	ft_printf("pb\n");
}

void	swap_a(t_list **stacka)
{
	swap_elem(stacka);
	ft_printf("sa\n");
}

void	swap_b(t_list **stackb)
{
	swap_elem(stackb);
	ft_printf("sb\n");
}
