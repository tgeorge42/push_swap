/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:52:40 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/06 13:30:33 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_elem(t_list **stack)
{
	t_list	*temp;

	if (!(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
}

void	rotate_elem(t_list **stack)
{
	t_list	*temp;

	if (!(*stack)->next)
		return ;
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->next = 0;
	ft_lstadd_back(stack, temp);
}

void	reverse_rotate_elem(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;
	int		size;

	if (!(*stack)->next)
		return ;
	temp = ft_lstlast((*stack));
	temp2 = (*stack);
	size = ft_lstsize((*stack));
	i = 0;
	while (i < size - 2)
	{
		temp2 = temp2->next;
		i++;
	}
	temp2->next = 0;
	ft_lstadd_front(stack, temp);
	(*stack) = temp;
}

void	push_elem(t_list **stack1, t_list **stack2)
{
	t_list	*temp;

	if (!(*stack2))
		return ;
	temp = (*stack2);
	(*stack2) = (*stack2)->next;
	ft_lstadd_front(stack1, temp);
}
