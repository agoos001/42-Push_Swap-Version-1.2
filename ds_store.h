/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_store.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:45:24 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/07 12:45:24 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DS_STORE_H
# define DS_STORE_H
# define MODE_ADAPTIVE 0
# define MODE_SIMPLE 1
# define MODE_MEDIUM 2
# define MODE_COMPLEX 3

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}			t_op;

typedef struct s_stack
{
	int		*data;
	int		cap;
	int		head;
	int		size;
}			t_stack;

typedef struct s_move
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		cost;
}			t_move;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	int		*nums;
	int		n;
	long	cnt[OP_COUNT];
	int		print;
	int		mode;
	int		used;
	int		bench;
	long	inv;

}			t_ps;

#endif
