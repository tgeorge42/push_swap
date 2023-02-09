/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cinq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:56:10 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 14:26:29 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_quatre(t_list **stacka, t_list **stackb)
{
	t_list	*temp;

	temp = *stacka;
	while (temp->index != 1)
		temp = temp->next;
	while ((*stacka)->index != 1)
	{
		if (temp->position <= 3)
			rotate_a(stacka);
		else
			reverse_rotate_a(stacka);
	}
	push_b(stacka, stackb);
	printf_algo_trois(stacka);
	push_a(stacka, stackb);
}

void	ft_prep_cinq(t_list **stacka, t_list **stackb)
{
	t_list	*temp;

	temp = *stacka;
	while (temp->index != 1)
		temp = temp->next;
	while ((*stacka)->index != 1)
	{
		if (temp->position <= 3)
			rotate_a(stacka);
		else
			reverse_rotate_a(stacka);
	}
	push_b(stacka, stackb);
	set_position(*stacka);
	temp = *stacka;
	while (temp->index != 2)
		temp = temp->next;
	while ((*stacka)->index != 2)
	{
		if (temp->position <= 3)
			rotate_a(stacka);
		else
			reverse_rotate_a(stacka);
	}
	push_b(stacka, stackb);
}

void	algo_cinq(t_list **stacka, t_list **stackb)
{
	ft_prep_cinq(stacka, stackb);
	printf_algo_trois(stacka);
	push_a(stacka, stackb);
	push_a(stacka, stackb);
}
