/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:41:00 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/09 14:18:52 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_freestack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}

t_list	*get_stacka(int	*tab, int ac)
{
	int		i;
	t_list	*stacka;
	t_list	*temp;

	i = 1;
	stacka = 0;
	while (i < ac)
	{
		temp = ft_lstnewint(tab[i - 1]);
		if (temp == 0)
		{
			ft_freestack(&stacka);
			free(tab);
			return (0);
		}
		ft_lstadd_back(&stacka, temp);
		i++;
	}
	ft_putindex(stacka, ac);
	set_position(stacka);
	free(tab);
	return (stacka);
}

int	*get_tab(int ac, char **av)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	i = 1;
	while (i < ac)
	{
		tab[i - 1] = ft_atol(av[i]);
		i++;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	int		*tab;
	t_list	*stacka;
	t_list	*stackb;

	if (ac >= 2)
	{
		if (check_pile(ac, av) == 1)
		{
			ft_printf("Error\n");
			return (0);
		}
		tab = get_tab(ac, av);
		stacka = get_stacka(tab, ac);
		if (!stacka)
			return (0);
		stackb = 0;
		ft_algo(&stacka, &stackb, ac);
		ft_freestack(&stacka);
	}
}
