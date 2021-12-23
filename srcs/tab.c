/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:50:36 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 19:30:10 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	tab_index(int ac, char **av, t_stack a)
{
	int		i;
	int		j;
	int		*tab_index;
	int		len;

	len = len_argv(ac, av);
	(i = 0) && (j = 0);
	tab_index = malloc(sizeof(int) * len);
	if (!tab_index)
		return (0);
	a = suite_tab_index(ac, av, a, &tab_index);
	if (!check_doublon(tab_index, len) || a == 0)
		return (0);
	sort_tab(tab_index, len);
	insert_index(tab_index, a, len);
	free(tab_index);
	return (a);
}

int	*sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = i + 1;
	while (i < len)
	{
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			else
				j++;
		}
		i++;
		j = i + 1;
	}
	return (tab);
}

int	put_in_tab(t_stack s)
{
	int		pivot;
	int		*tab;
	t_elem	*tmp;
	int		i;

	tab = malloc(sizeof(int) * s->nb_elem);
	if (!tab)
		return (0);
	pivot = 0;
	tmp = s->begin;
	i = 0;
	while (tmp != NULL)
	{
		tab[i] = tmp->index;
		tmp = tmp->next;
		i++;
	}
	sort_tab(tab, len_tab(s));
	pivot = reindex(tab, s);
	free(tab);
	return (pivot);
}

int	put_in_tab_b(t_stack s)
{
	int		pivot;
	int		*tab;
	t_elem	*tmp;
	int		i;
	int		x;

	tab = malloc(sizeof(int) * nbr_groupid(s));
	if (!tab)
		return (0);
	pivot = 0;
	tmp = s->begin;
	i = 0;
	x = nbr_groupid(s);
	while (x--)
	{
		tab[i] = tmp->index;
		tmp = tmp->next;
		i++;
	}
	sort_tab(tab, nbr_groupid(s));
	pivot = reindex_b(tab, s);
	free(tab);
	return (pivot);
}
