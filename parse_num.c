/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:31:24 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 10:33:17 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_int(char *s, int len, int *out)
{
	long	value;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (i == len)
		return (0);
	value = 0;
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		value = value * 10 + (s[i] - '0');
		if (value * sign > 2147483647L || value * sign < -2147483647L - 1)
			return (0);
		i++;
	}
	*out = (int)(value * sign);
	return (1);
}

static int	same_word(char *word, int len, char *ref)
{
	int	i;

	i = 0;
	while (i < len && ref[i] && word[i] == ref[i])
		i++;
	return (i == len && ref[i] == '\0');
}

static int	set_mode(t_ps *ps, int mode)
{
	if (ps->mode >= 0)
		return (0);
	ps->mode = mode;
	return (1);
}

int	read_flag(t_ps *ps, char *word, int len)
{
	if (same_word(word, len, "--simple"))
		return (set_mode(ps, MODE_SIMPLE));
	if (same_word(word, len, "--medium"))
		return (set_mode(ps, MODE_MEDIUM));
	if (same_word(word, len, "--complex"))
		return (set_mode(ps, MODE_COMPLEX));
	if (same_word(word, len, "--adaptive"))
		return (set_mode(ps, MODE_ADAPTIVE));
	if (same_word(word, len, "--bench") && !ps->bench)
	{
		ps->bench = 1;
		return (1);
	}
	return (0);
}
