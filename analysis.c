/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:37:17 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:37:17 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_inversions(int *v, int n)
{
	long	inv;
	int		i;
	int		j;

	inv = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (v[i] > v[j])
				inv++;
			j++;
		}
		i++;
	}
	return (inv);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (st_get(a, i) > st_get(a, i + 1))
			return (0);
		i++;
	}
	return (1);
}

int	find_pos(t_stack *s, int value)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (st_get(s, i) == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_min_pos(t_stack *s)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < s->size)
	{
		if (st_get(s, i) < st_get(s, best))
			best = i;
		i++;
	}
	return (best);
}

int	find_max_pos(t_stack *s)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < s->size)
	{
		if (st_get(s, i) > st_get(s, best))
			best = i;
		i++;
	}
	return (best);
}
