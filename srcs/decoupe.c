/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:56:05 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 19:28:49 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_in_decoupe(t_stack s, t_stack d, int stack, t_elem **tmp)
{
	if (!stack)
		(*tmp)->id += 2;
	else
		(*tmp)->id++;
	d = push(s, d, 1);
	(*tmp) = s->begin;
}

int	rotate_in_decoupe(t_stack s, int stack, int nbr_rotate, t_elem **tmp)
{
	if (stack)
		(*tmp)->id += 2;
	else
		(*tmp)->id++;
	s = rotate(s, 1);
	nbr_rotate++;
	(*tmp) = s->begin;
	return (nbr_rotate);
}

t_stack	decoupe(t_stack s, t_stack d, int mid, int stack)
{
	t_elem	*tmp;
	int		nb;
	int		nbr_rotate;

	tmp = s->begin;
	nb = nbr_groupid(s) / 2;
	nbr_rotate = 0;
	while (nb)
	{
		if (!is_smaller(tmp->index, mid))
			nbr_rotate = rotate_in_decoupe(s, stack, nbr_rotate, &tmp);
		else
		{
			d = push(s, d, 0);
			nb--;
			tmp = s->begin;
		}
	}
	while (tmp->id == s->end->id - 2)
	{
		tmp->id += 2;
		tmp = tmp->next;
	}
	ft_rotate(s, nbr_rotate, stack);
	return (d);
}

t_stack	decoupe_first(t_stack s, t_stack d, int mid)
{
	t_elem		*tmp;
	int			nb;
	static int	id = 1;

	tmp = s->begin;
	nb = s->nb_elem / 2;
	while (nb)
	{
		if (!is_smaller(tmp->index, mid))
		{
			s = rotate(s, 1);
			tmp = s->begin;
		}
		else
		{
			tmp->id = id;
			d = push(s, d, 0);
			tmp = s->begin;
			nb--;
		}
	}
	id++;
	return (d);
}

t_stack	decoupe_b(t_stack s, t_stack d, int mid, int stack)
{
	t_elem	*tmp;
	int		nbr_rotate;
	int		res;

	tmp = s->begin;
	nbr_rotate = 0;
	res = count_push(s, mid);
	while (res)
	{
		if (is_smaller(tmp->index, mid))
		{
			if (stack)
				tmp->id += 2;
			nbr_rotate++;
			(s = rotate(s, 0)) && (tmp = s->begin);
		}
		else
		{
			push_in_decoupe(s, d, stack, &tmp);
			res--;
		}
	}
	ft_rotate(s, nbr_rotate, stack);
	return (d);
}
