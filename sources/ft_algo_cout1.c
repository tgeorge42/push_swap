/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_cout1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:53:19 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/06 16:40:03 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*find_lowcost_a(t_list **stacka, t_list **stackb)
{
	t_list	*lowcost;
	t_list	*temp;
	int		cout_tot;

	temp = (*stacka);
	lowcost = (*stacka);
	cout_tot = ft_cout_a(stacka, temp) + ft_cout_b(stackb, temp);
	while (temp)
	{
		if (ft_cout_a(stacka, temp) + ft_cout_b(stackb, temp) < cout_tot)
		{
			cout_tot = ft_cout_a(stacka, temp) + ft_cout_b(stackb, temp);
			lowcost = temp;
		}
		temp = temp->next;
	}
	return (lowcost);
}

void	setup_stack_b(t_list **stack, t_list *lowcost)
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

void	setup_stack_a(t_list **stack, t_list *lowcost)
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
		while (i < ft_cout_a(stack, lowcost))
		{
			reverse_rotate_a(stack);
			i++;
		}
	}
}

void	push_lowcost_to_b(t_list **stacka, t_list **stackb)
{
	t_list	*lowcost_a;
	t_list	*lowcost_b;

	lowcost_a = find_lowcost_a(stacka, stackb);
	lowcost_b = find_lowcost_b_to_b(stackb, lowcost_a);
	setup_stack_b(stackb, lowcost_b);
	setup_stack_a(stacka, lowcost_a);
	push_b(stacka, stackb);
}

void	ft_algo_cout(t_list **stacka, t_list **stackb, int ac)
{
	push_b(stacka, stackb);
	push_b(stacka, stackb);
	while (ft_lstsize(*stackb) < ac - 4)
	{
		set_position(*stacka);
		set_position(*stackb);
		push_lowcost_to_b(stacka, stackb);
	}
	ft_algo3(stacka);
	while (ft_lstsize(*stacka) < ac - 1)
	{
		set_position(*stacka);
		set_position(*stackb);
		push_lowcost_to_a(stacka, stackb);
	}
	put_in_order(stacka);
}
