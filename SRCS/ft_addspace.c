/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:55:57 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 21:22:03 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_addspace2(t_attr attr, int nb)
{
	int ret;

	ret = 0;
	if (nb == 0 && attr.prec == 0)
		ret++;
	if (nb < 0 && attr.prec != -1 && attr.prec + 1 > ft_intlen(nb))
		ret--;
	return (ret);
}

int	ft_addspace3(t_attr attr, int len)
{
	int ret;

	ret = 0;
	if (attr.flag == 'w' || (attr.flag == '0' && attr.prec != -1))
		while (attr.padd - len > 0)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	return (ret);
}

int	ft_addspace4(t_attr attr, int len)
{
	int ret;

	ret = 0;
	if (attr.flag == '0')
		while (attr.padd - len > 0)
		{
			ret += write(1, "0", 1);
			attr.padd--;
		}
	return (ret);
}

int	ft_addspace5(t_attr attr, unsigned int n)
{
	int ret;

	ret = 0;
	if (attr.prec != -1)
		while (attr.prec - ft_intlen(n) > 0)
		{
			ret += write(1, "0", 1);
			attr.prec--;
		}
	return (ret);
}

int	ft_addspace6(t_attr attr, unsigned int n, int len, int print)
{
	int ret;

	ret = 0;
	if (print)
		if (!(n == 0 && attr.prec == 0))
			ret += ft_printunum(n);
	if (attr.flag == '-')
		while (attr.padd - len > 0)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	return (ret);
}
