/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:33:38 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:33:38 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rank_of(t_ps *ps, int i)
{
	int	j;
	int	rank;

	rank = 0;
	j = 0;
	while (j < ps->n)
	{
		if (j != i && ps->nums[j] == ps->nums[i])
			exit_er(ps);
		if (ps->nums[j] < ps->nums[i])
			rank++;
		j++;
	}
	return (rank);
}

static void	init_stack(t_ps *ps, t_stack *s)
{
	s->cap = 1;
	if (ps->n > 0)
		s->cap = ps->n;
	s->data = malloc(sizeof(int) * s->cap);
	if (!s->data)
		exit_er(ps);
	s->head = 0;
	s->size = 0;
}

void	check_duplicates_and_rank(t_ps *ps)
{
	int	i;

	init_stack(ps, &ps->a);
	init_stack(ps, &ps->b);
	i = 0;
	while (i < ps->n)
	{
		ps->a.data[i] = rank_of(ps, i);
		i++;
	}
	ps->a.size = ps->n;
}
