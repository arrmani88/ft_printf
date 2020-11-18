/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:38:10 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/23 20:17:09 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define A2I ft_atoi(f)
#define TAILLE lst->taille

void	ignore_spc_n_zero(char *s)
{
	if (ft_strchr(s, ' ') && ft_strchr(s, '+'))
		ft_del_char(s, ' ');
	if (ft_strchr(s, '-') && ft_strchr(s, '0'))
		ft_del_char(s, '0');
}

int		taille(char *f)
{
	if (*f == 'h' && *(f + 1) == 'h')
		return (1);
	else if (*f == 'h' && *(f + 1) != 'h')
		return (2);
	else if (*f == 'l' && *(f + 1) != 'l')
		return (3);
	else if (*f == 'l' && *(f + 1) == 'l')
		return (4);
	else if (*f == 'L')
		return (5);
	else if (*f == 'z')
		return (6);
	else if (*f == 'j')
		return (7);
	else if (*f == 't')
		return (8);
	return (0);
}

int		get_taille(char **f, t_arg *lst)
{
	if (**f == 'l' || **f == 'h' || **f == 'L' || **f == 'z'
													|| **f == 't' || **f == 'j')
	{
		TAILLE = taille(*f);
		*f = ((TAILLE == 1 || TAILLE == 4) ? (*f + 2) : (*f + 1));
		return (1);
	}
	return (0);
}

void	get_arg_format(char *f, t_arg *lst)
{
	int tmp;

	set_t_arg(lst);
	tmp = 0;
	(*f == '0') ? lst->option[0] = '0' : 0;
	if (*f >= '0' && *f <= '9')
		tmp = (A2I < 0) ? -1 : A2I;
	while (*f >= '0' && *f <= '9')
		f++;
	(*f == '$') ? (lst->dollar = tmp) : 0;
	(*f != '$') ? (lst->larg_min = tmp) : 0;
	f = ((*f == '$') ? (f + 1) : f);
	tmp = ((lst->option[0]) ? 1 : 0);
	while (*f == '-' || *f == '+' || *f == '#' || *f == '0' || *f == ' ')
		(!ft_strchr((lst->option), *f)) ? lst->option[tmp++] = *f++ : 0;
	ignore_spc_n_zero(lst->option);
	(*f >= '0' && *f <= '9') ? lst->larg_min = A2I : 0;
	while (*f >= '0' && *f <= '9')
		f++;
	if (*f == '.' && ++lst->point && *(++f) >= '0' && *f <= '9')
		lst->precision = (A2I < 0) ? 6 : A2I;
	while (*f >= '0' && *f <= '9')
		f++;
	(get_taille(&f, lst));
	(ft_strchr("cspfdiouxXegbrk", *f)) ? lst->conv_tp = *f : 0;
}
