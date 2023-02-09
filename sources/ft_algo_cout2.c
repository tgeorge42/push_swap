/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_cout2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:24:55 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/06 16:35:50 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_cout_b(t_list **stackb, t_list *to_count)
{
	t_list	*lowcost_b;

	lowcost_b = find_lowcost_b_to_b(stackb, to_count);
	return (ft_cout_a(stackb, lowcost_b) - 1);
}

void	setup_stack_b_to_a(t_list **stack, t_list *lowcost)
{
	int	i;

	i = 0;
	if (lowcost->position <= (ft_lstsize(*stack) / 2) + 1)
	{
		while (i < ft_cout_a(stack, lowcost) - 1)
		{
			rotate_b(stack);
			i++;
		}
	}
	else
	{
		while (i < ft_cout_a(stack, lowcost) - 1)
		{
			reverse_rotate_b(stack);
			i++;
		}
	}
}

void	setup_stack_a_to_a(t_list **stack, t_list *lowcost)
{
	int	i;

	i = 0;
	if (lowcost->position <= (ft_lstsize(*stack) / 2) + 1)
	{
		while (i < ft_cout_a(stack, lowcost) - 1)
		{
			rotate_a(stack);
			i++;
		}
	}
	else
	{
		while (i < ft_cout_a(stack, lowcost) - 1)
		{
			reverse_rotate_a(stack);
			i++;
		}
	}
}

void	push_lowcost_to_a(t_list **stacka, t_list**stackb)
{
	t_list	*lowcost_a;
	t_list	*lowcost_b;

	lowcost_b = find_lowcost_a(stackb, stacka);
	lowcost_a = find_lowcost_b_to_a(stacka, lowcost_b);
	setup_stack_b_to_a(stackb, lowcost_b);
	setup_stack_a_to_a(stacka, lowcost_a);
	push_a(stacka, stackb);
}

void	put_in_order(t_list **stacka)
{
	t_list	*temp;

	if (is_sorted(*stacka) == 0)
		return ;
	temp = (*stacka);
	set_position(*stacka);
	while (temp)
	{
		if (temp->index == 1)
			break ;
		temp = temp->next;
	}
	while (is_sorted(*stacka) == 1)
	{
		if (temp->position <= (ft_lstsize(*stacka) / 2) + 1)
			rotate_a(stacka);
		else
			reverse_rotate_a(stacka);
	}
}
