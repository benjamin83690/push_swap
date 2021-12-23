/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:34:16 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 22:54:28 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	suite_tab_index(int ac, char **av, t_stack a, int **tab_index)
{
	char	**tab;
	t_var	v;

	init_var(&v);
	while (++v.i < ac)
	{
		if (ft_strlen(*++av) == 0 || (ft_strlen(*av) == 1 && !is_digit(*av)))
			return (0);
		tab = ft_split(*av, ' ');
		v.k = 0;
		while (*(tab + v.k))
		{
			v.check = 1;
			v.nb = ft_atoi(tab[v.k], &v.check);
			if (!is_digit(*tab) || !v.check)
				return (0);
			(*tab_index)[v.j++] = v.nb;
			a = add_new_elem(v.nb, a);
			v.k++;
		}
		free(*tab);
		free(tab);
	}
	return (a);
}

void	suite_sort_b(t_stack a, t_stack b, int mid, int end)
{
	if (b->begin->index < mid && b->begin->index > end && mid > end)
	{
		swap(b, 0);
		push(b, a, 1);
		push(b, a, 1);
	}
	else if (b->begin->index > mid && mid < end)
	{
		push(b, a, 1);
		swap(b, 0);
		push(b, a, 1);
	}
	else if (b->begin->index < mid && b->begin->index < end)
	{
		swap(b, 0);
		push(b, a, 1);
		swap(b, 0);
		push(b, a, 1);
		if (mid < end)
			swap(a, 1);
	}
}

void	suite_final_sort2(t_stack s, t_stack b)
{
	int	mid;
	int	end;

	mid = s->begin->next->index;
	end = s->begin->next->next->index;
	swap(s, 1);
	rotate(s, 1);
	if (b->nb_elem > 2 && b->begin->index < b->begin->next->index)
		double_swap(s, b);
	else
		swap(s, 1);
	r_rotate(s, 1);
	if (mid > end)
	{
		if (b->nb_elem > 2 && b->begin->index < b->begin->next->index)
			double_swap(s, b);
		else
			swap(s, 1);
	}
}

void	suite_final_sort1(t_stack s, t_stack b)
{
	int	begin;
	int	end;

	begin = s->begin->index;
	end = s->begin->next->next->index;
	rotate(s, 1);
	swap(s, 1);
	r_rotate(s, 1);
	if (begin > end)
	{
		if (b->nb_elem > 2 && b->begin->index < b->begin->next->index)
			double_swap(s, b);
		else
			swap(s, 1);
	}
}

t_stack	suite_push(t_stack *s, t_stack *d, t_elem **tmp, t_elem **tmp_next)
{
	if (*d == NULL)
	{
		*d = malloc(sizeof(struct s_stack));
		(*d)->nb_elem = 0;
		if (*d == NULL)
			exit(1);
		(*d)->begin = *tmp;
		(*d)->end = *tmp;
		(*tmp)->next = NULL;
	}
	else
	{
		(*tmp)->next = (*d)->begin;
		(*d)->begin->prev = *tmp;
		(*d)->begin = *tmp;
		(*s)->begin = *tmp_next;
	}
	return (*d);
}
