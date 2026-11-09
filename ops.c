/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:03:49 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/09 09:49:09 by r03b             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push_from(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	st_push(to, st_pop(from));
}

static void	apply_swaps(t_ps *ps, t_op code)
{
	if (code == OP_SA || code == OP_SS)
		st_swap(&ps->a);
	if (code == OP_SA || code == OP_SS)
		st_swap(&ps->b);
}

static void	apply_pushes(t_ps *ps, t_op code)
{
	if (code == OP_PA)
		push_from(&ps->b, &ps->a);
	if (code == OP_PB)
		push_from(&ps->a, &ps->b);
}

static void	apply_rotations(t_ps *ps, t_op code)
{
	if (code == OP_RA || code == OP_RR)
		st_rotate(&ps->a);
	if (code == OP_RB || code == OP_RR)
		st_rotate(&ps->b);
	if (code == OP_RRA || code == OP_RRR)
		st_rrotate(&ps->a);
	if (code == OP_RRB || code == OP_RRR)
		st_rrotate(&ps->b);
}

void	op_apply(t_ps *ps, t_op code)
{
	apply_swaps(ps, code);
	apply_pushes(ps, code);
	apply_rotations(ps, code);
}

void	op(t_ps *ps, t_op code)
{
	op_apply(ps, code);
	ps->cnt[code]++;
	if (!ps->print)
		return ;
	ft_putendl_fd(op_name(code), 1);
}

void	repeat_op(t_ps *ps, t_op code, int n)
{
	while (n-- > 0)
		op(ps, code);
}
