/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:45:46 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:46:48 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 0.2 == 1/5; integer cross-multiplication avoids float rounding. */
static int	is_low_disorder(long inv, long total)
{
	return (total == 0 || 5 * inv < total);
}

/* 0.5 == 1/2. */
static int	is_medium_disorder(long inv, long total)
{
	return (2 * inv < total);
}

int	select_strategy(t_ps *ps)
{
	long	total;

	if (ps->mode != MODE_ADAPTIVE)
		return (ps->mode);
	total = (long)ps->n * (ps->n - 1) / 2;
	if (is_low_disorder(ps->inv, total))
		return (MODE_SIMPLE);
	if (is_medium_disorder(ps->inv, total))
		return (MODE_MEDIUM);
	return (MODE_COMPLEX);
}
