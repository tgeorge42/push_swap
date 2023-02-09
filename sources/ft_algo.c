/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:32:17 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/06 16:18:39 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algo3(t_list **stacka)
{
	if (ft_lstsize(*stacka) == 1)
		return ;
	else if (ft_lstsize(*stacka) == 2)
	{
		if (is_sorted(*stacka) == 0)
			return ;
		else
		{
			swap_a(stacka);
			return ;
		}
	}
	else if (ft_lstsize(*stacka) == 3)
	{
		printf_algo_trois(stacka);
		return ;
	}
}

void	ft_algo5(t_list	**stacka, t_list **stackb)
{
	if (ft_lstsize(*stacka) == 4)
	{
		algo_quatre(stacka, stackb);
		return ;
	}
	else if (ft_lstsize(*stacka) == 5)
	{
		algo_cinq(stacka, stackb);
		return ;
	}
}

void	ft_algo(t_list **stacka, t_list **stackb, int ac)
{
	if (is_sorted(*stacka) == 0)
		return ;
	if (ft_lstsize(*stacka) <= 3)
	{
		ft_algo3(stacka);
		return ;
	}
	else if (ft_lstsize(*stacka) <= 5)
	{
		ft_algo5(stacka, stackb);
		return ;
	}
	else if (ft_lstsize(*stacka) > 5)
	{
		ft_algo_cout(stacka, stackb, ac);
		return ;
	}
	return ;
}
