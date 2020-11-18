/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:05:48 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/22 17:33:05 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LEN f->len
#define VRG f->vrg

#include "../ft_printf.h"

int		verif_vrg(char *s, int fill, int null)
{
	int i;

	i = 0;
	if (!null && s[0] == '0')
		s++;
	while (s[i] && s[i] == '9' && i < fill)
		i++;
	if (i == fill)
		return (1);
	return (0);
}

char	*str_to_add(int n)
{
	char	*res;
	int		i;

	i = 1;
	res = NULL;
	res = ft_stralloc(res, n + 1);
	res[0] = '1';
	while (i <= n)
		res[i++] = '0';
	return (res);
}

char	*rounding_c(t_rep *f, int null, t_var v)
{
	if (v.round == 1)
	{
		f->vrg -= verif_vrg(f->res, v.i, null);
		v.tmp = NULL;
		v.tmp = f->res;
		v.sta = str_to_add(v.fill);
		f->res = sadd(v.sta, f->res);
		ft_strdel(&v.sta);
		ft_strdel(&v.tmp);
		return (f->res);
	}
	return (f->res);
}

char	*rounding(t_rep *f, int prec, int null)
{
	t_var v;

	v.i = (LEN > VRG) ? LEN - VRG + prec : prec - (VRG - LEN);
	v.fill = LEN - v.i;
	v.round = 0;
	if (v.i > LEN)
		return (f->res);
	if (f->res && f->res[v.i] && f->res[v.i + 1] < '5')
		return (f->res);
	else if (f->res && f->res[v.i] && f->res[v.i + 1] > '5')
		v.round = 1;
	if (f->res && f->res[v.i] && f->res[v.i + 1] == '5')
	{
		v.j = v.i + 2;
		while (f->res[v.j - 1] && f->res[v.j] && f->res[v.j] == '0')
			v.j++;
		if (f->res[v.j] != 0)
			v.round = 1;
		if (f->res[v.j] == 0 && ((f->res[v.i] - '0') % 2))
			v.round = 1;
	}
	return (rounding_c(f, null, v));
}
