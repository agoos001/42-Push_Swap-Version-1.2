/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:43:12 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:43:12 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max2(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

/* Position of the smallest value in a that is larger than x. */
static int	target_in_a(t_stack *a, int x)
{
	int	i;
	int	best;

	best = -1;
	i = 0;
	while (i < a->size)
	{
		if (st_get(a, i) > x && (best == -1 || st_get(a, i) < st_get(a, best)))
			best = i;
		i++;
	}
	if (best == -1)
		best = find_min_pos(a);
	return (best);
}

/*
** The four ways to bring both targets to the top.
** Both up and both down can be merged (rr / rrr):
** cost is max, not sum.
*/
static t_move	plan_move(t_ps *ps, int pa_pos, int pb_pos)
{
	int		da;
	int		db;
	t_move	up_up;
	t_move	dn_dn;
	t_move	up_dn;
	t_move	dn_up;
	t_move	best;

	da = ps->a.size - pa_pos;
	db = ps->b.size - pb_pos;
	up_up = (t_move){pa_pos, pb_pos, 0, 0, max2(pa_pos, pb_pos)};
	dn_dn = (t_move){0, 0, da, db, max2(da, db)};
	up_dn = (t_move){pa_pos, 0, 0, db, pa_pos + db};
	dn_up = (t_move){0, pb_pos, da, 0, da + pb_pos};
	best = up_up;
	if (dn_dn.cost < best.cost)
		best = dn_dn;
	if (up_dn.cost < best.cost)
		best = up_dn;
	if (dn_up.cost < best.cost)
		best = dn_up;
	return (best);
}

/* Execute the planned move, merging same-direction rotations. */
static void	do_move(t_ps *ps, t_move m)
{
	while (m.ra > 0 && m.rb > 0)
	{
		op(ps, OP_RR);
		m.ra--;
		m.rb--;
	}
	while (m.rra > 0 && m.rrb > 0)
	{
		op(ps, OP_RRR);
		m.rra--;
		m.rrb--;
	}
	op_repeat(ps, OP_RA, m.ra);
	op_repeat(ps, OP_RB, m.rb);
	op_repeat(ps, OP_RRA, m.rra);
	op_repeat(ps, OP_RRB, m.rrb);
	op(ps, OP_PA);
}

/* Try every element of b, execute the cheapest insertion. */
void	insert_cheapest(t_ps *ps)
{
	t_move	best;
	t_move	m;
	int		i;

	best = plan_move(ps, target_in_a(&ps->a, st_get(&ps->b, 0)), 0);
	i = 1;
	while (i < ps->b.size)
	{
		m = plan_move(ps, target_in_a(&ps->a, st_get(&ps->b, i)), i);
		if (m.cost < best.cost)
			best = m;
		i++;
	}
	do_move(ps, best);
}
