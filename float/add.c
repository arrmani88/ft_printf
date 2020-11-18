/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:53:06 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/23 04:33:13 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*set_str(char *s1, char *s2, int len1, int len2)
{
	char	*rtr;
	int		mlc;
	int		rest;
	int		a;
	int		b;

	mlc = ((len1 > len2 ? len1 : len2) + 1);
	rest = 0;
	rtr = NULL;
	rtr = ft_stralloc(rtr, mlc);
	rtr[0] = '0';
	while (len2 || len1)
	{
		a = !len1 ? 0 : (s1[--len1] - '0');
		b = !len2 ? 0 : (s2[--len2] - '0');
		rtr[--mlc] = ((a + b + rest) % 10) + '0';
		rest = (a + b + rest) / 10;
	}
	rest ? rtr[0] = rest + '0' : 0;
	return (rtr);
}

char	*sadd(char *s1, char *s2)
{
	char	*p2;
	char	*p1;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	while (*s1 == '0')
		s1++;
	while (*s2 == '0')
		s2++;
	p1 = s1;
	p2 = s2;
	while (p1[len1])
		len1++;
	while (p2[len2])
		len2++;
	return (set_str(p1, p2, len1, len2));
}
