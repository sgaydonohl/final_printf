/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:54:07 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 20:12:28 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_addspace1(t_attr attr, int len)
{
	int ret;

	ret = 0;
	if (attr.flag == 'w' || (attr.flag == '0' && attr.prec != -1))
		while (attr.padd - len > 0)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	if (attr.flag == '0')
		while (attr.padd - len > 0)
		{
			ret += write(1, "0", 1);
			attr.padd--;
		}
	return (ret);
}

int	ft_ifhex(t_attr attr, int maj)
{
	int nb;
	int ret;
	int len;

	nb = (unsigned int)attr.arg;
	len = attr.prec > ft_hexlen(nb) ? attr.prec : ft_hexlen(nb);
	if (nb == 0 && attr.prec == 0)
		attr.padd++;
	ret = 0 + ft_addspace1(attr, len);
	attr.padd -= ret;
	if (attr.prec != -1)
		while (attr.prec - ft_hexlen(nb) > 0)
		{
			ret += write(1, "0", 1);
			attr.prec--;
		}
	if (!(nb == 0 && attr.prec == 0))
		ret += ft_printhex(nb, maj);
	if (attr.flag == '-')
		while (attr.padd - len > 0)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	return (ret);
}
