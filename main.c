/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:35:53 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 11:38:23 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorted up to a rotation: at most one place where v[i] > v[i+1]. */
static int	is_rotated_sorted(t_stack *a)
{
	int	i;
	int	breaks;

	breaks = 0;
	i = 0;
	while (i < a->size)
	{
		if (st_get(a, i) > st_get(a, (i + 1) % a->size))
			breaks++;
		i++;
	}
	return (breaks <= 1);
}

/* Would one sa leave a sorted-up-to-rotation stack? (tested, not printed) */
static int	sa_helps(t_stack *a)
{
	int	ok;

	st_swap(a);
	ok = is_rotated_sorted(a);
	st_swap(a);
	return (ok);
}

/* Cheap special cases first, then the strategy chosen for the class. */
static void	run_strategy(t_ps *ps)
{
	if (!is_rotated_sorted(&ps->a) && sa_helps(&ps->a))
		op(ps, OP_SA);
	if (is_rotated_sorted(&ps->a))
		rotate_to_top(ps, find_min_pos(&ps->a), 0);
	else if (ps->n <= 5)
		sort_small(ps);
	else if (ps->used == MODE_SIMPLE)
		sort_simple(ps);
	else if (ps->used == MODE_MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}

int	main(int ac, char **av)
{
	t_ps	ps;

	init_ps(&ps);
	if (ac < 2)
		return (0);
	parse_args(&ps, ac, av);
	if (ps.n == 0)
	{
		free_all(&ps);
		return (0);
	}
	check_duplicates_and_rank(&ps);
	ps.inv = count_inversions(ps.a.data, ps.n);
	ps.used = select_strategy(&ps);
	if (!is_sorted(&ps.a))
		run_strategy(&ps);
	if (ps.bench)
		print_bench(&ps);
	free_all(&ps);
	return (0);
}
