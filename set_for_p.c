/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_for_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:44:58 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/19 16:44:41 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_for_p(t_arg *lst)
{
	int len;

	len = ft_strlen(lst->option);
	if (!ft_strchr(lst->option, '#'))
	{
		lst->option[len] = '#';
		lst->option[len + 1] = 'p';
		lst->option[len + 2] = '\0';
	}
	lst->conv_tp = 'x';
	return (1);
}
