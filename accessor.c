/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:03:49 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 11:48:09 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

const char	*op_name(t_op code)
{
	static const char *const names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	return (names[code]);
}

int	op_len(t_op code)
{
	static const int	lens[OP_COUNT] = {2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3};

	return (lens[code]);
}
