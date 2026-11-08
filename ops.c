/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:03:49 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/08 10:14:30 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ds_store.h"
#include "push_swap.h"

static void	push_from(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	st_push(to, st_pop(from));
}

static void	apply_swap(t_ps *ps, t_op code)
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

void	op(t_ps *ps, t_op code)
{
	op_apply(ps, code);
	ps->cnt[code]++;
	if (!ps->print)
		return ;
	ft_putendl_fd(op_name(code), 1);
}
