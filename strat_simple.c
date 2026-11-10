/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:42:25 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:42:25 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* len[i] = length of the longest increasing run ending at position i. */
static int	lis_lengths(t_stack *a, int *len, int *prev)
{
	int	i;
	int	j;
	int	best;

	best = 0;
	i = -1;
	while (++i < a->size)
	{
		len[i] = 1;
		prev[i] = -1;
		j = -1;
		while (++j < i)
		{
			if (st_get(a, j) < st_get(a, i) && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
		}
		if (len[i] > len[best])
			best = i;
	}
	return (best);
}

/* keep[v] = 1 for every value v belonging to the LIS. */
static void	mark_lis(t_stack *a, int *len, int *prev, int *keep)
{
	int	i;
	int	pos;

	i = 0;
	while (i < a->size)
		keep[i++] = 0;
	pos = lis_lengths(a, len, prev);
	while (pos != -1)
	{
		keep[st_get(a, pos)] = 1;
		pos = prev[pos];
	}
}

/* Push every value outside the LIS, nearest first. */
static void	push_non_lis(t_ps *ps, int *keep)
{
	int	up;
	int	down;

	while (1)
	{
		up = 0;
		while (up < ps->a.size && keep[st_get(&ps->a, up)])
			up++;
		if (up == ps->a.size)
			return ;
		down = ps->a.size - 1;
		while (keep[st_get(&ps->a, down)])
			down--;
		if (up <= ps->a.size - down)
			rotate_to_top(ps, up, 0);
		else
			rotate_to_top(ps, down, 0);
		op(ps, OP_PB);
	}
}

static int	split_lis(t_ps *ps)
{
	int	*len;
	int	*prev;
	int	*keep;
	int	ok;

	len = malloc(sizeof(int) * ps->n);
	prev = malloc(sizeof(int) * ps->n);
	keep = malloc(sizeof(int) * ps->n);
	ok = (len && prev && keep);
	if (ok)
	{
		mark_lis(&ps->a, len, prev, keep);
		push_non_lis(ps, keep);
	}
	free(len);
	free(prev);
	free(keep);
	return (ok);
}

/*
** SIMPLE: insertion sort with two stacks, O(n^2) operations.
**   1. keep the LIS in a, push the rest to b;
**   2. insert the elements of b back into a, cheapest first;
**   3. rotate a until its minimum is on top.
*/
void	sort_simple(t_ps *ps)
{
	if (!split_lis(ps))
		exit_er(ps);
	while (ps->b.size > 0)
		insert_cheapest(ps);
	rotate_to_top(ps, find_min_pos(&ps->a), 0);
}
