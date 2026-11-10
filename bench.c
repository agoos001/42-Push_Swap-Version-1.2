/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:47:32 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 11:39:14 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char *const g_strat_names[] = {"adaptive", "simple O(n^2)",
	"medium O(n*sqrt(n))", "complex O(n*log(n))"};

/* Disorder as a percentage with two decimals, from integers only. */
static void	print_disorder(t_ps *ps)
{
	long	total;
	long	bp;

	total = (long)ps->n * (ps->n - 1) / 2;
	bp = 0;
	if (total > 0)
		bp = (ps->inv * 10000 + total / 2) / total;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(bp / 100, 2);
	ft_putstr_fd(".", 2);
	if (bp % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(bp % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_ps *ps)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (ps->mode == MODE_ADAPTIVE)
		ft_putstr_fd("adaptive -> ", 2);
	ft_putstr_fd(g_strat_names[ps->used], 2);
	ft_putstr_fd("\n", 2);
}

static void	print_counts(t_ps *ps, int from, int to)
{
	static const char *const OP_NAME[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	ft_putstr_fd("[bench]", 2);
	while (from <= to)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(OP_NAME[from], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(ps->cnt[from], 2);
		from++;
	}
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_ps *ps)
{
	long	total;
	int		i;

	print_disorder(ps);
	print_strategy(ps);
	total = 0;
	i = 0;
	while (i < OP_COUNT)
		total += ps->cnt[i++];
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_counts(ps, OP_SA, OP_PB);
	print_counts(ps, OP_RA, OP_RRR);
}
