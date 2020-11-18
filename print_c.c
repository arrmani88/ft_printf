/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:01:26 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/11 18:16:28 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_arg lst, char c)
{
	int m;
	int rv;

	m = 1;
	rv = 1;
	if (!ft_strchr((lst.option), '-'))
	{
		m = -1;
		if (lst.larg_min > 1)
		{
			ft_putnchar_fd(' ', lst.larg_min - 1, lst.fd);
			rv += lst.larg_min - 1;
		}
	}
	ft_putchar_fd(c, lst.fd);
	if (m == 1 && lst.larg_min > 1)
	{
		ft_putnchar_fd(' ', lst.larg_min - 1, lst.fd);
		rv += lst.larg_min - 1;
	}
	return (rv);
}
