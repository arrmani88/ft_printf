/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:15:33 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/25 11:54:01 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct				s_var
{
	char					*s;
	char					*rtr;
	char					*tmp;
	char					*ptr;
	char					*str;
	char					*res;
	char					*dx;
	char					*pw;
	char					*mant;
	char					*expo;
	char					*pf;
	char					*sta;
	char					conv;
	char					signe;
	char					cr_sgn;
	int						shf;
	int						puis;
	int						bias;
	int						nval_n;
	int						vrg_pos;
	int						zr;
	int						pt;
	int						nb_len;
	int						prest;
	int						rv;
	int						j;
	int						fill;
	int						round;
	int						f_spc;
	int						f_zr;
	int						len;
	int						decilen;
	int						cond;
	int						diff;
	int						ltr;
	int						null;
	int						baselen;
	int						crs;
	int						strlen;
	int						len1;
	int						len2;
	int						i;
	unsigned long long int	n;
}							t_var;

typedef struct				s_parts
{
	unsigned long			mant:63;
	unsigned int			bit:1;
	unsigned int			puis:15;
	unsigned int			sign:1;
}							t_parts;

typedef	union				u_float
{
	long double				n;
	t_parts					prt;
}							t_float;

typedef struct				s_arg
{
	char					option[6];
	char					conv_tp;
	int						dollar;
	int						larg_min;
	int						point;
	int						precision;
	int						taille;
	int						arg_nb;
	int						fd;
}							t_arg;

typedef struct				s_rep
{
	int						vrg;
	char					*res;
	int						len;
}							t_rep;

void						modifcators(va_list ap, t_arg lst, char *s);
int							conv_xxscpobf(va_list ap, t_arg lst);
int							conv_diu(va_list ap, t_arg lst);
int							print_u(unsigned long long nb, t_arg lst);
int							inval(char **s);
char						*rounding(t_rep *f, int prec, int null);
int							calculate_float(long double nb, t_arg lst);
int							print_fl(t_rep rs, t_arg lst, t_var v);
char						*spow(char *s1, int n);
char						*smult(char *s1, char *s2);
char						*sadd(char *s1, char *s2);
int							set_for_p(t_arg *lst);
int							my_decilen(unsigned long long int nb);
void						my_putnbr_fd(unsigned long long int n, int fd);
void						incr(char **str);
void						get_arg_format(char *f, t_arg *lst);
void						set_t_arg(t_arg *lst);
int							print_s(t_arg lst, char *str);
void						print_lst(t_arg lst);
int							print_c(t_arg lst, char c);
int							print_d(long long int n, t_arg lst);
int							biggest_n(int a, int b, int c);
int							print_base(unsigned long long int n, t_arg lst);
int							ft_printf(char *str, ...);

#endif
