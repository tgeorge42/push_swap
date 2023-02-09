/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:41:21 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 14:17:48 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

int		check_pile(int ac, char	**av);
int		is_sorted(t_list *stack);
long	ft_atol(char *elem);
int		*get_tab(int ac, char **av);
int		check_doublon(int *tab, int ac);
void	set_position(t_list	*stack);
void	ft_putindex(t_list *stacka, int ac);

t_list	*find_lowest(t_list *stack);
t_list	*find_heighest(t_list *stack);
int		ft_cout_a(t_list **stacka, t_list *to_count);
int		ft_coup_b(t_list **stackb, t_list *to_count);

void	swap_elem(t_list **stack);
void	rotate_elem(t_list **stack);
void	reverse_rotate_elem(t_list **stack);
void	push_elem(t_list **stack1, t_list **stack2);
void	push_a(t_list **stacka, t_list **stackb);
void	push_b(t_list **stacka, t_list **stackb);
void	swap_a(t_list **stacka);
void	swap_b(t_list **stackb);
void	rotate_a(t_list **stacka);
void	rotate_b(t_list **stackb);
void	reverse_rotate_a(t_list **stacka);
void	reverse_rotate_b(t_list **stackb);

void	ft_algo(t_list **stacka, t_list **stackb, int ac);
void	ft_algo3(t_list **stacka);
void	printf_algo_trois(t_list **stack);
void	algo_quatre(t_list **stacka, t_list **stackb);
void	algo_cinq(t_list **stacka, t_list **stackb);
void	ft_algo_cout(t_list **stacka, t_list **stackb, int ac);

void	ft_affiche(t_list *stacka, t_list *stackb);

int		ft_cout_a(t_list **stacka, t_list *to_count);
int		is_outbound(t_list **stack, t_list *to_count);
t_list	*find_lowcost_b_to_b(t_list **stackb, t_list *to_count);
t_list	*find_lowcost_b_to_a(t_list **stackb, t_list *to_count);
t_list	*find_lowcost_a(t_list **stacka, t_list **stackb);
void	setup_stack_b(t_list **stack, t_list *lowcost);
void	setup_stack_a(t_list **stack, t_list *lowcost);
void	push_lowcost_to_b(t_list **stacka, t_list **stackb);
void	ft_algo_cout(t_list **stacka, t_list **stackb, int ac);
int		ft_cout_b(t_list **stackb, t_list *to_count);
void	setup_stack_b_to_a(t_list **stack, t_list *lowcost);
void	setup_stack_a_to_a(t_list **stack, t_list *lowcost);
void	push_lowcost_to_a(t_list **stacka, t_list**stackb);
void	put_in_order(t_list **stacka);

#endif
