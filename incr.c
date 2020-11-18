/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 05:52:02 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/22 18:54:51 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	incr(char **str)
{
	if (**str == '{')
		while (**str != '}')
			(*str)++;
	else if (**str == '}')
		while (**str != '{')
			(*str)++;
	else
		while (**str && !ft_strchr("cspfdiouxXegbrk", **str))
			(*str)++;
}
