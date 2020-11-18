/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:28:08 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/24 14:36:27 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define C_TP lst.conv_tp
#define LARG_M lst.larg_min
#define PRECS lst.precision
#define SRCH(x) ft_strchr(lst.option, x)
#include "ft_printf.h"

int				ft_len_str_base(unsigned long long int n, int baselen)
{
	int i;

	i = 1;
	while (n /= baselen)
		i++;
	return (i);
}

static int		print(char *s, t_arg lst, t_var v)
{
	int r;
	int cond;

	r = 0;
	cond = 1;
	(v.null && PRECS == -1 && lst.point && ((!v.crs && C_TP == 'o')
												|| C_TP != 'o')) ? cond = 0 : 0;
	(v.f_zr && !cond && (v.f_spc = v.f_zr)) ?
												v.f_zr = 0 : 0;
	(!SRCH('-') && (r += v.f_spc)) ? ft_putnchar_fd(' ', v.f_spc, lst.fd) : 0;
	(!v.null && v.crs && v.baselen == 16 && C_TP == 'X' && (r += 2)) ?
												ft_putstr_fd("0X", lst.fd) : 0;
	((!v.null || C_TP == 'p') && v.crs && (C_TP == 'x' || C_TP == 'p') &&
									(r += 2)) ? ft_putstr_fd("0x", lst.fd) : 0;
	(!v.null && v.crs && v.baselen == 2 && C_TP == 'b' && (r += 2)) ?
												ft_putstr_fd("0b", lst.fd) : 0;
	!v.null && v.crs && v.baselen == 8 && ++r ? ft_putchar_fd('0', lst.fd) : 0;
	(v.f_zr && (r += v.f_zr)) ? ft_putnchar_fd('0', v.f_zr, lst.fd) : 0;
	(cond && (r += ft_strlen(s))) ? ft_putstr_fd(s, lst.fd) : 0;
	(v.null && LARG_M && lst.point && PRECS == -1 && !SRCH('+') && !SRCH(' ') &&
								!cond && ++r) ? ft_putchar_fd(' ', lst.fd) : 0;
	(SRCH('-') && (r += v.f_spc)) ? ft_putnchar_fd(' ', v.f_spc, lst.fd) : 0;
	free(s);
	return (r);
}

int				calculate(char *s, t_arg lst, t_var v)
{
	v.f_zr = 0;
	v.f_spc = 0;
	v.cond = (v.null && PRECS == -1 && lst.point) ? 1 : 0;
	v.strlen = ft_strlen(s);
	(SRCH('#') && (C_TP == 'x' || C_TP == 'X' || C_TP == 'b') && !v.null
									&& v.strlen >= PRECS) ? v.strlen += 2 : 0;
	v.len = biggest_n(LARG_M, PRECS, v.strlen);
	if (v.len != v.strlen)
	{
		if (LARG_M > PRECS && PRECS > v.strlen &&
											((v.f_spc = v.len - PRECS) || 1))
			v.f_zr = v.len - v.f_spc - v.strlen;
		else if (LARG_M > PRECS && PRECS < v.len && (!SRCH('0')
							|| (SRCH('0') && lst.point)))
			v.f_spc = LARG_M - v.strlen;
		else
			v.f_zr = v.len - v.strlen;
	}
	(LARG_M > v.strlen && PRECS > v.strlen && PRECS > 0 && !v.null && v.crs &&
												C_TP != 'o') ? v.f_spc -= 2 : 0;
	v.f_spc && v.crs && C_TP == 'o' && !v.null && v.strlen > PRECS ?
																v.f_spc-- : 0;
	(v.f_zr && v.crs && C_TP == 'o' && !v.null) ? v.f_zr-- : 0;
	return (print(s, lst, v));
}

int				print_base(unsigned long long int n, t_arg lst)
{
	t_var v;

	if (ft_strchr(lst.option, 'p') && n == 0 && write(1, "0x0", 3))
		return (3);
	v.baselen = ((C_TP == 'o') ? 8 : 16);
	(C_TP == 'b') ? (v.baselen = 2) : 0;
	v.crs = ((SRCH('#') ? 1 : 0));
	v.null = ((n == 0) ? 1 : 0);
	v.len = ft_len_str_base(n, v.baselen);
	v.str = ft_strnew(v.len);
	v.diff = (v.baselen == 16 ? 10 : 0);
	v.ltr = ((C_TP == 'X') ? 'A' : 'a');
	v.str[v.len] = '\0';
	while (v.len--)
	{
		v.str[v.len] = n % v.baselen +
									(n % v.baselen > 9 ? v.ltr - v.diff : '0');
		n /= v.baselen;
	}
	return (calculate(v.str, lst, v));
}
