/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:44:30 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:44:30 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Digit of `value` at place `place` in base 2: (value / place) % 2. */
static int	digit_at(int value, int place)
{
	return ((value / place) % 2);
}

/* One LSD pass: zeros go to b, ones rotate; then push everything back. */
static void	radix_pass(t_ps *ps, int place)
{
	int	count;

	count = ps->a.size;
	while (count-- > 0)
	{
		if (digit_at(st_get(&ps->a, 0), place) == 0)
			op(ps, OP_PB);
		else
			op(ps, OP_RA);
	}
	while (ps->b.size > 0)
		op(ps, OP_PA);
}

/*
** COMPLEX, O(n log n): binary LSD radix on the ranks 0..n-1.
** There are ceil(log2 n) passes, each at most 2n operations.
** `place` doubles: 1, 2, 4, 8, ... until it reaches n.
*/
void	sort_complex(t_ps *ps)
{
	int	place;

	if (ps->n < 2)
		return ;
	place = 1;
	while (place < ps->n)
	{
		if (is_sorted(&ps->a))
			break ;
		radix_pass(ps, place);
		place *= 2;
	}
}
