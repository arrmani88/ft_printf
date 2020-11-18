/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:15:04 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/20 23:50:22 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*spow(char *s1, int n)
{
	char *res;
	char *tmp;

	res = ft_strdup("1");
	n == 0 ? free(s1) : 0;
	while (n > 0)
	{
		if (n & 1)
		{
			tmp = res;
			res = smult(res, s1);
			ft_strdel(&tmp);
		}
		n >>= 1;
		tmp = s1;
		s1 = n > 0 ? smult(s1, s1) : tmp;
		ft_strdel(&tmp);
	}
	return (res);
}
