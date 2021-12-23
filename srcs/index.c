/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:54:00 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 19:30:53 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	reindex(int *tab, t_stack s)
{
	int	pivot;

	pivot = tab[(s->nb_elem / 2) - 1];
	return (pivot);
}

int	reindex_b(int *tab, t_stack s)
{
	int	pivot;

	pivot = tab[(nbr_groupid(s) / 2) - 1];
	return (pivot);
}

void	insert_index(int *tab, t_stack a, int ac)
{
	t_elem		*tmp;
	static int	i;
	int			j;

	tmp = a->begin;
	i = 1;
	j = 0;
	while (j < ac && tmp != NULL)
	{
		if (tmp->value == tab[j])
		{
			j++;
			tmp->index = i++;
			tmp = a->begin;
		}
		else
			tmp = tmp->next;
	}
}
