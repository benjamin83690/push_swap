/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:41:57 by bfichot           #+#    #+#             */
/*   Updated: 2021/10/05 22:57:20 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_push(t_stack s, int mid)
{
	t_elem	*tmp;
	int		nb;
	int		count;

	tmp = s->begin;
	nb = nbr_groupid(s);
	count = 0;
	while (nb--)
	{
		if (tmp->index > mid)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	len_ac(int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
		i++;
	return (i);
}

int	len_argv(int ac, char **av)
{
	int		i;
	char	**tab;
	int		len;
	int		j;

	tab = NULL;
	len = 0;
	i = 0;
	while (++i < ac)
	{
		if (ft_strlen(*++av) == 0 || (ft_strlen(*av) == 1 && !is_digit(*av)))
			return (0);
		tab = ft_split(*av, ' ');
		if (!tab || !(*tab))
			return (0);
		j = 0;
		while (*(tab + j++))
		{
			len++;
			free(tab[j]);
		}
		free(*tab);
		free(tab);
	}
	return (len);
}

int	len_tab(t_stack s)
{
	t_elem	*tmp;
	int		i;

	tmp = s->begin;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_smaller(int index, int mid)
{
	if (index <= mid)
		return (1);
	return (0);
}
