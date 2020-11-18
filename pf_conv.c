/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:27:53 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/25 15:16:00 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define C_TP lst.conv_tp
#define CONV_BS (C_TP == 'X' || C_TP == 'x' || C_TP == 'o' || C_TP == 'b')
#include "ft_printf.h"

void	modifcators(va_list ap, t_arg lst, char *s)
{
	if (*s == '}' && *(s + 1) == 'w' && *(s + 2) == '{')
		lst.fd = open((va_arg(ap, char *)), O_CREAT | O_RDWR);
	else if (*s == '}' && *(s + 1) == 'a' && *(s + 2) == '{')
		lst.fd = open((va_arg(ap, char *)), O_CREAT | O_RDWR | O_APPEND);
	else if (*s == '}' && *(s + 1) == 'e' && *(s + 2) == '{')
		lst.fd = 1;
	else if (*s == '{')
		manage_cols(s);
}

int		conv_xxscpobf(va_list ap, t_arg lst)
{
	if (C_TP == 'p' && (set_for_p(&lst)))
		return (print_base(va_arg(ap, unsigned long long), lst));
	else if (CONV_BS && lst.taille == 3)
		return (print_base(va_arg(ap, unsigned long), lst));
	else if (CONV_BS && lst.taille == 4)
		return (print_base(va_arg(ap, unsigned long long), lst));
	else if (CONV_BS && lst.taille == 2)
		return (print_base((unsigned short)va_arg(ap, unsigned int), lst));
	else if (CONV_BS && lst.taille == 1)
		return (print_base((unsigned char)va_arg(ap, unsigned int), lst));
	else if (CONV_BS)
		return (print_base(va_arg(ap, unsigned int), lst));
	else if (C_TP == 'f' && (lst.taille == 5 || lst.taille == 4))
		return (calculate_float(va_arg(ap, long double), lst));
	else if (C_TP == 'f')
		return (calculate_float(va_arg(ap, double), lst));
	else if (C_TP == 'c')
		return (print_c(lst, va_arg(ap, int)));
	else if (C_TP == 's')
		return (print_s(lst, va_arg(ap, char *)));
	return (0);
}

int		conv_diu(va_list ap, t_arg lst)
{
	if ((C_TP == 'd' || C_TP == 'i') && lst.taille == 3)
		return (print_d(va_arg(ap, long), lst));
	else if ((C_TP == 'd' || C_TP == 'i') &&
	(lst.taille == 4 || lst.taille == 6 || lst.taille == 7 || lst.taille == 8))
		return (print_d(va_arg(ap, long long), lst));
	else if ((C_TP == 'd' || C_TP == 'i') && lst.taille == 2)
		return (print_d((short)va_arg(ap, int), lst));
	else if ((C_TP == 'd' || C_TP == 'i') && lst.taille == 1)
		return (print_d((char)va_arg(ap, int), lst));
	else if (C_TP == 'd' || C_TP == 'i')
		return (print_d(va_arg(ap, int), lst));
	else if ((C_TP == 'u') && lst.taille == 3)
		return (print_u(va_arg(ap, unsigned long), lst));
	else if ((C_TP == 'u') && lst.taille == 4)
		return (print_u(va_arg(ap, unsigned long long), lst));
	else if ((C_TP == 'u') && lst.taille == 2)
		return (print_u((unsigned short)va_arg(ap, unsigned int), lst));
	else if ((C_TP == 'u') && lst.taille == 1)
		return (print_u((unsigned char)va_arg(ap, unsigned int), lst));
	else if (C_TP == 'u')
		return (print_u(va_arg(ap, unsigned int), lst));
	return (0);
}
