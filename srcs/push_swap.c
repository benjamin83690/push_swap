/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:49:51 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 22:57:53 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate(t_stack s, int nbr_rotate, int stack)
{
	if (!one_groupid(s))
	{
		while (nbr_rotate)
		{
			s = r_rotate(s, stack);
			nbr_rotate--;
		}
	}
}

t_stack	func_swap(t_stack s)
{
	t_elem	*tmp;

	tmp = s->begin;
	s->begin = tmp->next;
	s->begin->prev = NULL;
	tmp->prev = s->begin;
	tmp->next = s->begin->next;
	s->begin->next = tmp;
	return (s);
}

int	main_func(t_stack a, t_stack b, int stack)
{
	if (stack)
	{
		if (a == NULL)
			return (printf("Error\n"));
		else
			if (!already_sort(a))
				sort_a(a, b);
	}
	else
	{
		if (a == NULL)
			return (printf("Error\n"));
		else
			if (!already_sort(a))
				sort(a, b);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	b = NULL;
	a = NULL;
	if (ac > 1)
	{
		if (len_argv(ac, av) <= 3)
		{
			a = tab_index(ac, av, a);
			main_func(a, b, 1);
		}
		else
		{
			a = tab_index(ac, av, a);
			main_func(a, b, 0);
		}
	}
}
