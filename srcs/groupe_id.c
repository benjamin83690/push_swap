/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groupe_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:58:35 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 19:29:07 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	nbr_groupid(t_stack s)
{
	t_elem	*tmp;
	int		i;
	int		id;

	tmp = s->begin;
	i = 0;
	id = biggest_groupid(s);
	while (tmp != NULL && id == tmp->id)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	biggest_groupid(t_stack s)
{
	int		id;
	t_elem	*tmp;

	id = s->begin->id;
	tmp = s->begin;
	while (tmp->next != NULL)
	{
		if (id < tmp->id)
			id = tmp->id;
		tmp = tmp->next;
	}
	return (id);
}

void	reset_id(t_stack s)
{
	t_elem	*tmp;

	tmp = s->begin;
	while (tmp != NULL)
	{
		tmp->id = 0;
		tmp = tmp->next;
	}
}

int	one_groupid(t_stack s)
{
	t_elem	*tmp;
	int		id;

	id = s->begin->id;
	tmp = s->begin->next;
	while (tmp != NULL)
	{
		if (id != tmp->id)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
