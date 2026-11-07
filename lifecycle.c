/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r03b </var/spool/mail/r03b>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:14:39 by r03b              #+#    #+#             */
/*   Updated: 2026/11/07 12:29:38 by r03b             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ds_store.h"
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
	write(2, "Error\n", 6);
	free_all(ps);
	exit(1);
}
