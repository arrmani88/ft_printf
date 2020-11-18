/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:15:37 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/23 20:54:06 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_conv(va_list ap, t_arg lst, char **s, int *nvl)
{
	int rv;

	rv = 0;
	get_arg_format(++*s, &lst);
	*nvl = ((inval(s))) ? 1 : 0;
	modifcators(ap, lst, *s);
	rv += conv_diu(ap, lst);
	rv += conv_xxscpobf(ap, lst);
	return (rv);
}

int		check_nxt_arg(char *s)
{
	t_arg	list;
	char	*p;

	p = s;
	while (*p && *p != '%')
		p++;
	get_arg_format(++p, &list);
	if (list.precision >= 2147483641 || list.larg_min >= 2147483641)
		return (0);
	return (1);
}

int		ft_printf(char *s, ...)
{
	va_list	ap;
	t_arg	lst;
	int		rv;
	int		nvl;

	rv = 0;
	lst.fd = 1;
	va_start(ap, s);
	while (*s)
	{
		nvl = 0;
		if (*s == '%' && *(s + 1) == '%' && ++rv && s++)
			ft_putchar_fd('%', lst.fd);
		else if (*s == '%' && ((rv += manage_conv(ap, lst, &s, &nvl)) || 1))
			(!nvl) ? incr(&s) : 0;
		else if ((check_nxt_arg(s) == 1) && ++rv)
			ft_putchar_fd(*s, lst.fd);
		else if (check_nxt_arg(s) == 0)
			return (-1);
		!nvl ? s++ : 0;
	}
	va_end(ap);
	return (rv);
}
