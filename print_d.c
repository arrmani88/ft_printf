/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:28:08 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/23 23:28:44 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LARG_M lst.larg_min
#define PRECS lst.precision

#include "ft_printf.h"

int		print(t_arg lst, t_var *v)
{
	int r;
	int cond;

	r = 0;
	cond = 1;
	if (v->n == 0 && lst.precision == -1 && lst.point)
		cond = 0;
	if (v->signe && !v->f_spc && ++r)
		ft_putchar_fd(v->signe, lst.fd);
	if (!ft_strchr(lst.option, '-') && (r += v->f_spc))
		ft_putnchar_fd(' ', v->f_spc, lst.fd);
	if (v->signe && v->f_spc && ++r)
		ft_putchar_fd(v->signe, lst.fd);
	if (v->f_zr && (r += v->f_zr))
		ft_putnchar_fd('0', v->f_zr, lst.fd);
	if (cond && (r += my_decilen(v->n)))
		my_putnbr_fd(v->n, lst.fd);
	if (v->n == 0 && lst.larg_min && lst.point && lst.precision == -1 &&
	!ft_strchr(lst.option, '+') && !ft_strchr(lst.option, ' ') && ++r)
		ft_putchar_fd(' ', lst.fd);
	if (ft_strchr(lst.option, '-') && (r += v->f_spc))
		ft_putnchar_fd(' ', v->f_spc, lst.fd);
	return (r);
}

void	ft_continue(t_var *v, t_arg lst)
{
	if (v->signe && LARG_M > PRECS && v->len != v->decilen)
		v->len--;
	if (v->len != v->decilen)
	{
		if (LARG_M > PRECS && PRECS > v->decilen)
		{
			v->f_spc = v->len - PRECS;
			v->f_zr = v->len - v->f_spc - v->decilen;
		}
		else if (LARG_M > PRECS && PRECS < v->len && (!ft_strchr(lst.option,
		'0') || (ft_strchr(lst.option, '0') && lst.point)))
		{
			v->f_spc = LARG_M - v->decilen;
			if (v->signe && v->cond)
				v->f_spc--;
		}
		else
			v->f_zr = v->len - v->decilen;
	}
}

int		print_d(long long int nb, t_arg lst)
{
	t_var v;

	v.signe = 0;
	v.f_zr = 0;
	v.f_spc = 0;
	v.cond = 1;
	if (nb >= 0 && ft_strchr(lst.option, '+'))
		v.signe = '+';
	if (nb >= 0 && ft_strchr(lst.option, ' '))
		v.signe = ' ';
	if (nb < 0 && (v.signe = '-'))
		v.n = -nb;
	else
		v.n = nb;
	if (v.n == 0 && lst.precision == -1 && lst.point)
		v.cond = 0;
	v.decilen = my_decilen(v.n);
	v.len = biggest_n(LARG_M, PRECS, v.decilen);
	if (v.len == v.decilen && ft_strchr(lst.option, ' ') && !v.signe)
		v.len++;
	ft_continue(&v, lst);
	return (print(lst, &v));
}
