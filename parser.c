/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r03b </var/spool/mail/r03b>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:57:56 by r03b              #+#    #+#             */
/*   Updated: 2026/11/09 09:57:56 by r03b             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	w_count(const char *s, char c)
{
	int		found;
	size_t	count;

	count = 0;
	found = 0;
	while (*s)
	{
		if (*s == c)
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
