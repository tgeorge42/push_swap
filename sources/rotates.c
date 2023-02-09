/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:28:28 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 12:27:18 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_list **stacka)
{
	rotate_elem(stacka);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stackb)
{
	rotate_elem(stackb);
	ft_printf("rb\n");
}

void	reverse_rotate_a(t_list **stacka)
{
	reverse_rotate_elem(stacka);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stackb)
{
	reverse_rotate_elem(stackb);
	ft_printf("rrb\n");
}
