/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_trois.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:13:23 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 12:54:47 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	algo_trois(t_list *stack)
// {
// 	t_list	*temp;

// 	temp = stack;
// 	if (stack->elem < stack->next->elem)
// 	{
// 		temp = stack->next;
// 		if (temp->elem < temp->next->elem)
// 			return (0);
// 		else
// 		{
// 			if (temp->next->elem > stack->elem)
// 				return (1);
// 			else
// 				return (2);
// 		}
// 	}
// 	else
// 	{
// 		temp = stack->next;
// 		if (temp->elem < temp->next->elem)
// 		{
// 			if (temp->next->elem > stack->elem)
// 				return (3);
// 			else
// 				return (4);
// 		}
// 		else
// 			return (5);
// 	}
// }
// 
void	printf_algo_trois(t_list **stack)
{
	while (is_sorted(*stack) == 1)
	{
		if ((*stack) == find_heighest(*stack))
			rotate_a(stack);
		else if (ft_lstlast(*stack) == find_heighest(*stack))
			swap_a(stack);
		else if ((*stack)->next == find_heighest(*stack))
			reverse_rotate_a(stack);
	}
}

// void	printf_algo_trois(t_list **stack)
// {
// 	if (algo_trois(*stack) == 0)
// 		return ;
// 	else if (algo_trois(*stack) == 1)
// 	{
// 		swap_a(stack);
// 		rotate_a(stack);
// 	}
// 	else if (algo_trois(*stack) == 2)
// 		reverse_rotate_a(stack);
// 	else if (algo_trois(*stack) == 3)
// 		swap_a(stack);
// 	else if (algo_trois(*stack) == 4)
// 		rotate_a(stack);
// 	else if (algo_trois(*stack) == 5)
// 	{
// 		swap_a(stack);
// 		reverse_rotate_a(stack);
// 	}
// 	return ;
// }
