/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:38:45 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:38:45 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_ps *ps, int pos, int is_b)
{
	t_stack	*s;
	t_op	rot;
	t_op	rrot;

	s = &ps->a;
	rot = OP_RA;
	rrot = OP_RRA;
	if (is_b)
	{
		s = &ps->b;
		rot = OP_RB;
		rrot = OP_RRB;
	}
	if (pos <= s->size / 2)
		op_repeat(ps, rot, pos);
	else
		op_repeat(ps, rrot, s->size - pos);
}

static void	sort_three(t_ps *ps)
{
	int	x;
	int	y;
	int	z;

	x = st_get(&ps->a, 0);
	y = st_get(&ps->a, 1);
	z = st_get(&ps->a, 2);
	if (x > y && x > z)
		op(ps, OP_RA);
	else if (y > x && y > z)
		op(ps, OP_RRA);
	if (st_get(&ps->a, 0) > st_get(&ps->a, 1))
		op(ps, OP_SA);
}

void	sort_small(t_ps *ps)
{
	if (ps->a.size == 2)
	{
		if (st_get(&ps->a, 0) > st_get(&ps->a, 1))
			op(ps, OP_SA);
		return ;
	}
	while (ps->a.size > 3)
	{
		rotate_to_top(ps, find_min_pos(&ps->a), 0);
		op(ps, OP_PB);
	}
	sort_three(ps);
	while (ps->b.size > 0)
		op(ps, OP_PA);
}
