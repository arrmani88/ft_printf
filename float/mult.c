/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:41:51 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/21 21:29:00 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*clc(char n, char *s, t_var v)
{
	int		i;
	int		tmp;
	int		rst;

	i = 0;
	rst = 0;
	v.tmp[0] = '0';
	if (n == 0 && (v.tmp[1] = 0) + 3)
		return (v.tmp);
	while (v.i)
		v.tmp[v.i-- + v.len1] = '0';
	i = v.len1--;
	while (v.len1 >= 0)
	{
		tmp = n * (s[v.len1] - '0') + rst;
		v.tmp[i--] = (tmp % 10) + '0';
		rst = tmp / 10;
		v.len1--;
	}
	rst ? v.tmp[0] = (rst + '0') : '0';
	return (v.tmp);
}

char		*smult(char *s1, char *s2)
{
	t_var v;

	v.i = 0;
	*s1 == '0' ? s1++ : 0;
	*s2 == '0' ? s2++ : 0;
	v.len1 = ft_strlen(s1);
	v.len2 = ft_strlen(s2);
	v.rtr = ft_strdup("0");
	while (--v.len2 >= 0)
	{
		v.ptr = v.rtr;
		v.tmp = ft_stralloc(v.tmp, v.len1 + 1 + v.i);
		v.rtr = sadd(v.rtr, clc(s2[v.len2] - '0', s1, v));
		free(v.tmp);
		free(v.ptr);
		v.i++;
	}
	return (v.rtr);
}
