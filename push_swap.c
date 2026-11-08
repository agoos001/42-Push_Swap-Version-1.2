/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:45:56 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/08 10:00:51 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ds_store.h"
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		v;

	a = malloc(sizeof(*a));
	if (!a)
		free(a);
	a->cap = 5;
	a->size = 0;
	a->data = malloc(sizeof(*a->data) * a->cap);
	if (!(a->data))
	{
		free(a->data);
		return (-1);
	}
	st_push(a, 0);
	st_push(a, 1);
	st_push(a, 2);
	st_push(a, 3);
	st_push(a, 4);
	for (int i = 0; i < a->size; i++)
		printf("%d\n", st_get(a, i));
	v = st_pop(a);
	printf("poped: %d\n", v);
	for (int i = 0; i < a->size; i++)
		printf("%d\n", st_get(a, i));
	printf("swaped: %d & %d\n", 3, 2);
	st_swap(a);
	for (int i = 0; i < a->size; i++)
		printf("%d\n", st_get(a, i));
	free(a->data);
	free(a);
	return (0);
}
