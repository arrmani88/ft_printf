/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:45:12 by anel-bou          #+#    #+#             */
/*   Updated: 2019/10/24 00:35:20 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STRLEN rs.len
#define VRG rs.vrg
#define LARG_M lst.larg_min
#define PRC lst.precision
#define VP v.vrg_pos
#define SRCH(x) ft_strchr(lst.option, x)
#define ROUND (rs.res = rounding(&rs, PRC, v.null))

#include "../ft_printf.h"

int	prnt_c(t_arg lst, t_rep rs, t_var v)
{
	if (v.zr != -1 && !v.nval_n)
	{
		v.pt ? write(1, "0.", 2) : write(1, "0", 1);
		v.pt ? (v.rv += (2 + v.prest + PRC)) : (v.rv += (1 + v.prest + PRC));
		ft_putnchar_fd('0', v.zr, lst.fd);
		ft_putnstr_fd(&rs.res[v.i], PRC, lst.fd);
		(VRG < PRC) ? ft_putnchar_fd('0', PRC - VRG, lst.fd) : 0;
	}
	v.nval_n ? ft_putstr_fd(rs.res, lst.fd) : 0;
	v.nval_n ? v.rv += 3 : 0;
	if (v.null && LARG_M && lst.point && lst.precision == -1 &&
	!SRCH('+') && !SRCH(' ') && ++v.rv)
		ft_putchar_fd(' ', lst.fd);
	(SRCH('-') && (v.rv += v.f_spc)) ? ft_putnchar_fd(' ', v.f_spc, lst.fd) : 0;
	free(v.pf);
	return (v.rv);
}

int	prnt(t_arg lst, t_rep rs, t_var v)
{
	v.i = 0;
	v.rv = 0;
	(v.cr_sgn && !v.f_spc && ++v.rv) ? ft_putchar_fd(v.cr_sgn, lst.fd) : 0;
	(!SRCH('-') && (v.rv += v.f_spc)) ?
									ft_putnchar_fd(' ', v.f_spc, lst.fd) : 0;
	(v.cr_sgn && v.f_spc && ++v.rv) ? ft_putchar_fd(v.cr_sgn, lst.fd) : 0;
	(v.f_zr && (v.rv += v.f_zr)) ? ft_putnchar_fd('0', v.f_zr, lst.fd) : 0;
	while (rs.res[v.i] && VP != -1 && v.i != VP && !v.nval_n && ++v.rv)
		write(lst.fd, &rs.res[v.i++], 1);
	if (v.i == VP && !v.nval_n)
	{
		v.pt || (!v.pt && SRCH('#') && lst.point) ? write(1, ".", 1)
													&& (v.rv += (PRC + 1)) : 0;
		ft_putnstr_fd(&rs.res[v.i], PRC, lst.fd);
		(VRG < PRC) ? ft_putnchar_fd('0', PRC - VRG, lst.fd) : 0;
	}
	return (prnt_c(lst, rs, v));
}

int	print_fl_c(t_rep rs, t_arg lst, t_var v)
{
	if (v.len != (PRC + v.nb_len + v.pt) || v.nval_n)
	{
		if (LARG_M > PRC && SRCH('0') && v.pt && !v.nval_n && LARG_M >
														(PRC + v.nb_len + v.pt))
		{
			v.f_zr = LARG_M - (PRC + v.nb_len + v.pt);
			(v.cr_sgn) ? v.f_zr-- : 0;
		}
		else if (LARG_M > PRC && (v.pt || (!v.pt && !v.nval_n) || v.nval_n)
							&& (LARG_M > (PRC + v.nb_len + v.pt) || v.nval_n))
		{
			v.f_spc = (v.nval_n ? (LARG_M - PRC) :
											(LARG_M - (PRC + v.nb_len + v.pt)));
			(v.cr_sgn) ? v.f_spc-- : 0;
		}
		if (v.zr >= PRC && v.zr != -1 && ((v.prest = PRC) || 1))
		{
			v.zr = PRC;
			PRC = 0;
		}
		else if (PRC > v.zr && v.zr != -1 && PRC <= VRG &&
														((v.prest = v.zr) || 1))
			PRC = PRC - v.zr;
	}
	return (prnt(lst, rs, v));
}

int	print_fl(t_rep rs, t_arg lst, t_var v)
{
	v.prest = 0;
	v.null ? rs.len = 1 : 0;
	v.cr_sgn = 0;
	v.f_zr = 0;
	v.f_spc = 0;
	lst.precision == -1 && !lst.point ? lst.precision = 6 : 0;
	lst.precision == -1 && lst.point ? lst.precision = 0 : 0;
	(!v.null && rs.res[0] == '0') ? rs.len-- : 0;
	v.zr = (STRLEN <= VRG) ? VRG - STRLEN : -1;
	!v.nval_n && !v.null && (v.zr < PRC || ((v.zr + STRLEN) < PRC)) ? ROUND : 0;
	v.pf = rs.res;
	(!v.null && rs.res[0] == '0') ? rs.res++ : 0;
	v.pt = (lst.precision == 0 && lst.point && !SRCH('#')) ? 0 : 1;
	VP = (STRLEN > VRG) ? STRLEN - VRG : -1;
	v.zr = (STRLEN <= VRG) ? VRG - STRLEN : -1;
	v.nb_len = (VRG >= STRLEN) ? 1 : STRLEN - VRG;
	(!v.signe && SRCH('+') && v.nval_n != 1) ? v.cr_sgn = '+' : 0;
	(!v.signe && SRCH(' ') && v.nval_n != 1) ? v.cr_sgn = ' ' : 0;
	(v.signe && v.nval_n != 1) ? v.cr_sgn = '-' : 0;
	v.len = biggest_n(LARG_M, PRC, STRLEN);
	return (print_fl_c(rs, lst, v));
}
