/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r03b </var/spool/mail/r03b>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:57:56 by r03b              #+#    #+#             */
/*   Updated: 2026/11/10 11:47:15 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	w_count(const char *s)
{
	int		found;
	size_t	count;

	count = 0;
	found = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			found = 0;
		else if (found == 0)
		{
			found = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	handle_word(t_ps *ps, char *word, int len)
{
	int	value;

	if (ps->n == 0 && len > 2 && word[0] == '-' && word[1] == '-')
	{
		if (!read_flag(ps, word, len))
			exit_er(ps);
		return ;
	}
	if (!parse_int(word, len, &value))
		exit_er(ps);
	ps->nums[ps->n++] = value;
}

static void	split_argument(t_ps *ps, char *s)
{
	int	len;

	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		len = 0;
		while (s[len] && !ft_isspace(s[len]))
			len++;
		if (len > 0)
			handle_word(ps, s, len);
		s += len;
	}
}

void	parse_args(t_ps *ps, int ac, char **av)
{
	int	i;
	int	total;

	total = 0;
	i = 1;
	while (i < ac)
	{
		if (w_count(av[i]) == 0)
			exit_er(ps);
		total += w_count(av[i]);
		i++;
	}
	ps->nums = malloc(sizeof(int) * total);
	if (!ps->nums)
		exit_er(ps);
	i = 1;
	while (i < ac)
		split_argument(ps, av[i++]);
	if (ps->mode < 0)
		ps->mode = MODE_ADAPTIVE;
}
