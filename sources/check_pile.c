/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:44:34 by tgeorge           #+#    #+#             */
/*   Updated: 2023/02/06 16:20:10 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = stack;
	while (i < ft_lstsize(stack))
	{
		if (temp->elem > temp->next->elem)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

int	check_doublon(int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 2)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *elem)
{
	long	atol;
	int		i;
	int		sign;
	int		maxlen;

	i = -1;
	sign = 1;
	atol = 0;
	maxlen = 0;
	if (elem[++i] == '+' || elem[i] == '-')
	{
		if (elem[i++] == 45)
			sign *= -1;
		maxlen += 1;
	}
	while (elem[i] == '0')
		i++;
	while (elem[i] > 47 && elem[i] < 58)
	{
		atol = atol * 10 + elem[i++] - 48;
		maxlen += 1;
	}
	if (maxlen > 11)
		return (2147483648);
	return (sign * atol);
}

int	check_number(char *elem)
{
	int	i;

	i = 0;
	if ((elem[i] < 48 || elem[i] > 57) && elem[i] != 43 && elem[i] != 45)
		return (1);
	if (elem[i] == 43 || elem[i] == 45)
	{
		if (elem[i + 1] < 48 || elem[i + 1] > 57)
			return (1);
	}
	i++;
	while (elem[i])
	{
		if ((elem[i] < 48 || elem[i] > 57))
			return (1);
		i++;
	}
	return (0);
}

int	check_pile(int ac, char **av)
{
	int	i;
	int	*tab;

	i = 1;
	while (i < ac)
	{
		if (check_number(av[i]) == 1)
			return (1);
		if (ft_atol(av[i]) < -2147483648 || ft_atol(av[i]) > 2147483647)
			return (1);
		i++;
	}
	tab = get_tab(ac, av);
	if (check_doublon(tab, ac) == 1)
		return (free(tab), 1);
	return (free(tab), 0);
}
