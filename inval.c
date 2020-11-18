/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inval.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:07:44 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/23 19:25:56 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char *s)
{
	while (*s && !(ft_strchr("cspfdiouxXegbrk", *s)))
	{
		if ((*s > '9' || *s < '0') && !(ft_strchr("#$*.-+0 zjthlL", *s)))
			return (1);
		s++;
	}
	if (*s && ft_strchr("cspfdiouxXegbrk", *s))
		return (0);
	return (1);
}

int	inval(char **s)
{
	int n;

	n = check(*s);
	if (n)
	{
		while (**s && ft_strchr("0123456789.#$*.-+0 hlLzjt", **s))
			(*s)++;
	}
	return (n);
}
