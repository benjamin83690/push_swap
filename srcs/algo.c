/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:12:40 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 19:27:59 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	which_stack(t_stack a, t_stack b)
{
	int	sa;
	int	sb;

	sa = biggest_groupid(a);
	if (b->begin)
	{
		sb = biggest_groupid(b);
		if (sa < sb)
			return (0);
		if (sa == sb)
			return (1);
	}
	return (1);
}

t_stack	trie_a(t_stack a, t_stack b, int mid)
{
	if (nbr_groupid(a) > 3)
	{
		mid = put_in_tab_b(a);
		b = decoupe(a, b, mid, 1);
	}
	else
	{
		if (!already_sort(a))
			final_sort(a, b);
		reset_id(a);
	}
	return (b);
}

t_stack	trie_b(t_stack a, t_stack b, int mid)
{
	if (b->begin && nbr_groupid(b) <= 3)
	{
		if (!already_sort_b(b, nbr_groupid(b)))
			sort_b(a, b);
		else
			push(b, a, 1);
	}
	else
	{
		mid = put_in_tab_b(b);
		a = decoupe_b(b, a, mid, 0);
	}
	return (a);
}

int	already_sort(t_stack s)
{
	t_elem	*elem;
	t_elem	*tmp;

	elem = s->begin;
	tmp = s->begin->next;
	while (tmp != NULL)
	{
		if (elem->index > tmp->index)
			return (0);
		elem = elem->next;
		tmp = tmp->next;
	}
	return (1);
}

int	already_sort_b(t_stack s, int nb)
{
	t_elem	*elem;
	t_elem	*tmp;
	int		i;

	elem = s->begin;
	tmp = NULL;
	if (s->nb_elem == 1)
		return (1);
	if (s->nb_elem > 2)
	{
		tmp = s->begin->next;
		i = -1;
		while (++i < nb - 1)
		{
			if (elem->index < tmp->index)
				return (0);
			elem = elem->next;
			tmp = tmp->next;
		}
	}
	else if (s->nb_elem == 2)
		return (s->begin->index > s->begin->next->index);
	return (1);
}
