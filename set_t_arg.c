/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:27:43 by anel-bou          #+#    #+#             */
/*   Updated: 2019/08/04 17:20:11 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_t_arg(t_arg *lst)
{
	ft_memset(lst->option, 0, 6);
	(lst)->dollar = -1;
	(lst)->larg_min = -1;
	(lst)->precision = -1;
	lst->point = 0;
	(lst)->taille = -1;
	(lst)->conv_tp = -1;
	(lst)->arg_nb = -1;
}
