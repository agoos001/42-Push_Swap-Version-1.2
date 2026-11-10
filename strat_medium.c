/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:44:15 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:44:15 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

/*
** MEDIUM, O(n * sqrt(n)): chunk sort with a sliding window.
** Phase 1: push to b every rank in [0, pushed + range]; small values
**          are rotated to b's bottom (rb) so b ends up roughly sorted.
** Phase 2: pull b's maximum back each time.
*/
void	sort_medium(t_ps *ps)
{
	int	range;
	int	pushed;
	int	x;

	range = int_sqrt(ps->n) * 3 / 2;
	pushed = 0;
	while (ps->a.size > 0)
	{
		x = st_get(&ps->a, 0);
		if (x <= pushed + range)
		{
			op(ps, OP_PB);
			if (x <= pushed && ps->b.size > 1)
				op(ps, OP_RB);
			pushed++;
		}
		else
			op(ps, OP_RA);
	}
	while (ps->b.size > 0)
	{
		rotate_to_top(ps, find_max_pos(&ps->b), 1);
		op(ps, OP_PA);
	}
}
