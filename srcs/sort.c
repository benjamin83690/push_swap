/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:47:25 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 23:29:18 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_b(t_stack a, t_stack b)
{
	int	mid;
	int	end;

	mid = b->begin->next->index;
	if (nbr_groupid(b) == 2 && b->begin->index < mid)
	{
		swap(b, 0);
		push(b, a, 1);
	}
	else
	{
		end = b->begin->next->next->index;
		suite_sort_b(a, b, mid, end);
	}
	push(b, a, 1);
}

void	final_sort(t_stack s, t_stack b)
{
	int	begin;
	int	mid;
	int	end;

	begin = s->begin->index;
	mid = s->begin->next->index;
	end = s->begin->next->next->index;
	if ((begin > mid && begin < end && mid < end) || (nbr_groupid(s) == 2))
	{
		if (b->nb_elem > 2 && b->begin->index < b->begin->next->index)
			double_swap(s, b);
		else
			swap(s, 1);
	}
	else if (begin < mid && mid > end)
		suite_final_sort1(s, b);
	else if (begin > mid && begin > end)
		suite_final_sort2(s, b);
	reset_id(s);
}

void	sort(t_stack a, t_stack b)
{
	int		start;
	int		mid;

	start = a->nb_elem;
	mid = a->nb_elem / 2;
	while (a->begin && a->nb_elem > 3)
	{
		b = decoupe_first(a, b, mid);
		mid = put_in_tab(a);
	}
	if (!already_sort(a))
		sort_a(a, b);
	reset_id(a);
	while (a->nb_elem != start || !already_sort(a))
	{
		if (which_stack(a, b))
			trie_a(a, b, mid);
		else
			trie_b(a, b, mid);
	}
	free(b);
}

void	sort_a(t_stack a, t_stack b)
{
	int	begin;
	int	mid;
	int	end;

	begin = a->begin->index;
	mid = a->begin->next->index;
	end = a->end->index;
	if ((begin > mid && begin < end) || (a->nb_elem <= 2 && begin > end))
	{
		if (b && b->nb_elem > 2 && b->begin->index < b->begin->next->index)
			double_swap(a, b);
		else
			swap(a, 1);
	}
	else if (begin < mid && end < begin)
		a = r_rotate(a, 1);
	else if (mid > begin && mid > end && begin < end)
		(r_rotate(a, 1)) && (swap(a, 1));
	else if (begin > mid && mid > end)
		(a = rotate(a, 1)) && (a = swap(a, 1));
	else if (begin > mid && mid < end)
		a = rotate(a, 1);
}
