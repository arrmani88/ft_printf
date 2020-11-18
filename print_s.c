/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:45:33 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/23 22:46:42 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LARG_M lst.larg_min
#define PRECS lst.precision

static int	print(char *s, t_arg lst, int spc, int null)
{
	int r;
	int len;

	len = ((ft_strlen(s) < PRECS || PRECS == -1) ? ft_strlen(s) : PRECS);
	r = len;
	if (!ft_strchr(lst.option, '-') && (r += spc))
		ft_putnchar_fd(' ', spc, lst.fd);
	ft_putnstr_fd(s, len, lst.fd);
	if (ft_strchr(lst.option, '-') && (r += spc))
		ft_putnchar_fd(' ', spc, lst.fd);
	null ? free(s) : 0;
	return (r);
}

int			print_s(t_arg lst, char *s)
{
	int	fill_spc;
	int	len;
	int null;
	int	strlen;

	fill_spc = 0;
	null = 0;
	strlen = 0;
	if (!s && ++null)
		s = ft_strdup("(null)");
	if (*s)
		strlen = ((ft_strlen(s) < PRECS || PRECS == -1) ? ft_strlen(s) : PRECS);
	len = biggest_n(LARG_M, strlen, 0);
	if (len != strlen)
		fill_spc = LARG_M - strlen;
	return (print(s, lst, fill_spc, null));
}
