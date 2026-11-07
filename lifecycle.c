/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:45:10 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/07 12:52:35 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_ps *ps)
{
	int	i;

	ps->a.data = NULL;
	ps->a.cap = 0;
	ps->a.head = 0;
	ps->a.size = 0;
	ps->nums = NULL;
	ps->b.data = NULL;
	ps->b.cap = 0;
	ps->b.head = 0;
	ps->b.size = 0;
	ps->n = 0;
	ps->print = 1;
	ps->mode = -1;
	ps->used = MODE_ADAPTIVE;
	ps->bench = 0;
	ps->inv = 0;
	i = 0;
	while (i < OP_COUNT)
		ps->cnt[i++] = 0;
}

void	free_all(t_ps *ps)
{
	free(ps->nums);
	free(ps->a.data);
	free(ps->b.data);
	ps->nums = NULL;
	ps->a.data = NULL;
	ps->b.data = NULL;
}
void	exit_er(t_ps *ps)
{
	ft_putendl_fd("Error\n", 2);
	free_all(ps);
	exit(1);
}
