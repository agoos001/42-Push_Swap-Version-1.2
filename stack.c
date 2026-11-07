/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:52:12 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/07 16:42:32 by r03b             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_get(t_stack *s, int i)
{
	return (s->data[(s->head + i) % s->cap]);
}

int	st_pop(t_stack *s)
{
	int	v;

	if (!s || s->size == 0)
		return (-1);
	v = s->data[s->head];
	s->head = (s->head + 1) % s->cap;
	s->size--;
	return (v);
}

void	st_push(t_stack *s, int v)
{
	s->head = (s->head - 1 + s->cap) % s->cap;
	s->data[s->head] = v;
	s->size++;
}

void	st_rotate(t_stack *s)
{
	int	v;

	if (s->size < 2)
		return ;
	v = st_pop(s);
	s->data[(s->head + s->size) % s->cap] = v;
	s->size++;
}

void	st_rrotate(t_stack *s)
{
	int	v;

	v = s->data[(s->head + s->size - 1) % s->cap];
	s->size--;
	st_push(s, v);
}
/*
void	st_swap(t_stack *s)
{
}
*/
