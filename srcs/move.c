/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:37:43 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 19:31:22 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	swap(t_stack s, int stack)
{
	t_elem	*tmp;

	tmp = s->begin;
	func_swap(s);
	if (s->nb_elem == 3)
		s->end->prev = tmp;
	if (s->nb_elem == 2)
		s->end = tmp;
	if (stack)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return (s);
}

void	double_swap(t_stack a, t_stack b)
{
	t_elem	*tmp_a;
	t_elem	*tmp_b;

	tmp_a = a->begin;
	tmp_b = b->begin;
	func_swap(a);
	func_swap(b);
	write(1, "ss\n", 3);
}

t_stack	rotate(t_stack s, int stack)
{
	t_elem	*tmp;

	tmp = s->begin;
	s->begin = tmp->next;
	s->begin->prev = NULL;
	s->end->next = tmp;
	tmp->prev = s->end;
	s->end = tmp;
	tmp->next = NULL;
	if (stack)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	return (s);
}

t_stack	push(t_stack s, t_stack d, int stack)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = s->begin;
	tmp_next = s->begin->next;
	if (tmp->next != NULL)
	{
		s->begin = tmp->next;
		s->begin->prev = NULL;
	}
	else
		s->end = NULL;
	suite_push(&s, &d, &tmp, &tmp_next);
	if (stack)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	tmp->prev = NULL;
	s->nb_elem--;
	d->nb_elem++;
	return (d);
}

t_stack	r_rotate(t_stack s, int stack)
{
	t_elem	*tmp;

	tmp = s->end;
	s->end = tmp->prev;
	s->end->next = NULL;
	tmp->next = s->begin;
	s->begin = tmp;
	s->begin->prev = NULL;
	if (stack)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	return (s);
}
