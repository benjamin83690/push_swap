/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:39:59 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 19:29:24 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_var(t_var *v)
{
	v->nb = 0;
	v->i = 0;
	v->j = 0;
	v->k = 0;
	v->check = 0;
}

void	init_struct(t_elem **elem)
{
	*elem = malloc(sizeof(struct s_elem));
	if (*elem == NULL)
		exit(1);
	(*elem)->value = 0;
	(*elem)->index = 0;
	(*elem)->id = 0;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;
}

t_stack	add_new_elem(int val, t_stack a)
{
	t_elem	*elem;

	init_struct(&elem);
	elem->value = val;
	if (a == NULL)
	{
		a = malloc(sizeof(struct s_stack));
		a->nb_elem = 0;
		if (a == NULL)
			exit(1);
		a->begin = elem;
		a->end = elem;
	}
	else
	{
		a->end->next = elem;
		elem->prev = a->end;
		a->end = elem;
		elem->next = NULL;
	}
	a->nb_elem++;
	return (a);
}
