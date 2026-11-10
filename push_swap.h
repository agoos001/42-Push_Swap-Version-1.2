/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:45:40 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/10 11:37:43 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ds_store.h"
# include <stdlib.h>
# include <unistd.h>
// PS init
void		init_ps(t_ps *ps);
void		free_ps(t_ps *ps);
void		exit_er(t_ps *ps);
void		free_all(t_ps *ps);
// utils
size_t		ft_strlen(char const *s);
void		ft_putchar_fd(const char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(long n, int fd);
int			ft_isspace(int c);
// stack elements
int			st_get(t_stack *s, int i);
int			st_pop(t_stack *s);
void		st_push(t_stack *s, int v);
void		st_rotate(t_stack *s);
void		st_rrotate(t_stack *s);
void		st_swap(t_stack *s);
// accessors
const char	*op_name(t_op code);
int			op_len(t_op code);
// operations
void		op(t_ps *ps, t_op code);
void		op_apply(t_ps *ps, t_op code);
void		op_repeat(t_ps *ps, t_op code, int n);
// parsing
void		parse_args(t_ps *ps, int argc, char **argv);
int			parse_int(char *s, int len, int *out);
int			read_flag(t_ps *ps, char *word, int len);
// analysis
long		count_inversions(int *v, int n);
int			is_sorted(t_stack *a);
int			find_min_pos(t_stack *s);
int			find_max_pos(t_stack *s);
int			find_pos(t_stack *s, int value);
// rank
void		check_duplicates_and_rank(t_ps *ps);
// stratigies
void		sort_small(t_ps *ps);
void		sort_simple(t_ps *ps);
void		sort_medium(t_ps *ps);
void		sort_complex(t_ps *ps);
void		insert_cheapest(t_ps *ps);
int			select_strategy(t_ps *ps);
void		rotate_to_top(t_ps *ps, int pos, int is_b);
// output
void		ft_putstr(int fd, const char *s);
void		ft_putnbr(int fd, long n);
void		print_bench(t_ps *ps);
#endif
