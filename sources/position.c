/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:35:50 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 14:22:27 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_sousindex(t_list	*stacka, t_list *temp, int i, int min)
{
	temp = stacka;
	while (temp)
	{
		if (temp->elem == min)
		{
			temp->index = i;
			break ;
		}
		temp = temp->next;
	}
	return (temp);
}

void	ft_putindex(t_list *stacka, int ac)
{
	int		min;
	int		i;
	t_list	*temp;

	i = 1;
	while (i < ac)
	{
		temp = stacka;
		while (temp && temp->index != 0)
			temp = temp->next;
		min = temp->elem;
		temp = stacka;
		while (temp)
		{
			if (temp->elem < min && temp->index == 0)
				min = temp->elem;
			temp = temp->next;
		}
		temp = ft_sousindex(stacka, temp, i, min);
		i++;
	}
}

void	set_position(t_list	*stack)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = stack;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

t_list	*find_lowest(t_list *stack)
{
	t_list	*lowest;
	t_list	*temp;

	temp = stack;
	lowest = stack;
	while (temp)
	{
		if (temp->elem < lowest->elem)
			lowest = temp;
		temp = temp->next;
	}
	return (lowest);
}

t_list	*find_heighest(t_list *stack)
{
	t_list	*heighest;
	t_list	*temp;

	temp = stack;
	heighest = stack;
	while (temp)
	{
		if (temp->elem > heighest->elem)
			heighest = temp;
		temp = temp->next;
	}
	return (heighest);
}
