/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_cout3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:21 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/06 16:38:13 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_cout_a(t_list **stacka, t_list *to_count)
{
	int	cout_a;

	cout_a = 1;
	if (to_count->position <= (ft_lstsize(*stacka) / 2) + 1)
		cout_a += to_count->position - 1;
	else
		cout_a += ft_lstsize(*stacka) - to_count->position + 1;
	return (cout_a);
}

int	is_outbound(t_list **stack, t_list *to_count)
{
	int		lowest;
	int		heighest;	

	lowest = find_lowest(*stack)->elem;
	heighest = find_heighest(*stack)->elem;
	if (to_count->elem < lowest || to_count->elem > heighest)
		return (1);
	return (0);
}

t_list	*find_lowcost_b_to_b(t_list **stackb, t_list *to_count)
{
	t_list	*lowest;
	t_list	*temp;

	if (is_outbound(stackb, to_count) == 1)
		return (find_heighest(*stackb));
	lowest = (*stackb);
	temp = (*stackb);
	while (temp)
	{
		if (temp->elem < to_count->elem)
		{
			lowest = temp;
			break ;
		}
		temp = temp->next;
	}
	temp = lowest;
	while (temp)
	{
		if (temp->elem > lowest->elem && temp->elem < to_count->elem)
			lowest = temp;
		temp = temp->next;
	}
	return (lowest);
}

t_list	*find_lowcost_b_to_a(t_list **stackb, t_list *to_count)
{
	t_list	*heighest;
	t_list	*temp;

	if (is_outbound(stackb, to_count) == 1)
		return (find_lowest(*stackb));
	heighest = (*stackb);
	temp = (*stackb);
	while (temp)
	{
		if (temp->elem > to_count->elem)
		{
			heighest = temp;
			break ;
		}
		temp = temp->next;
	}
	temp = heighest;
	while (temp)
	{
		if (temp->elem < heighest->elem && temp->elem > to_count->elem)
			heighest = temp;
		temp = temp->next;
	}
	return (heighest);
}
