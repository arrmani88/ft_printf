/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:49:44 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/23 23:31:33 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define PRECS lst.precision
#define MAX_EXPO f.prt.puis == 32767
#define TWO ft_strdup("2")
#define FIVE ft_strdup("5")

int		cal_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*calc_mant(unsigned long n, int nrmzd)
{
	t_var v;

	v.shf = 63;
	v.puis = 0;
	if (n == 0 && !nrmzd)
		return (ft_strdup("0"));
	v.dx = ft_strdup("10");
	v.res = ft_strdup("1");
	while (--v.shf >= 0 && ++v.puis)
	{
		v.tmp = v.res;
		v.res = smult(v.res, v.dx);
		free(v.tmp);
		if ((n >> v.shf) & 1)
		{
			v.pw = spow(ft_strdup("5"), v.puis);
			v.ptr = v.res;
			v.res = sadd(v.res, v.pw);
			free(v.pw);
			free(v.ptr);
		}
	}
	free(v.dx);
	return (v.res);
}

int		calculate_float(long double nb, t_arg lst)
{
	t_rep	s;
	t_float	f;
	t_var	v;

	f.n = nb;
	s.vrg = 0;
	v.nval_n = (MAX_EXPO) * ((MAX_EXPO) | (!f.prt.mant << 1));
	v.bias = (nb == 0 ? 0 : (f.prt.puis - 16383) - (f.prt.bit == 0));
	if (nb != 0 && !v.nval_n)
		s.vrg = v.bias >= 0 ? 63 : (v.bias * -1) + 63;
	v.null = (nb == 0 ? 1 : 0);
	if (!v.nval_n)
	{
		v.expo = v.bias >= 0 ? spow(TWO, v.bias) : spow(FIVE, v.bias * -1);
		v.mant = calc_mant(f.prt.mant, !!(f.prt.puis));
		s.res = smult(v.mant, v.expo);
		free(v.mant);
		free(v.expo);
	}
	if (v.nval_n && (s.len = 3)
								&& (PRECS = 3))
		s.res = ((v.nval_n == 3) ? ft_strdup("inf") : ft_strdup("nan"));
	s.len = cal_len(s.res);
	v.signe = (f.prt.sign == 1);
	return (print_fl(s, lst, v));
}
