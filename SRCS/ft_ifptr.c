/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:53:41 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 21:42:20 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_addspace7(t_attr attr, unsigned long ul)
{
	int ret;

	ret = 0;
	if (attr.prec != -1)
		while (attr.prec - ft_ptrlen(ul) + 2 > 0)
		{
			ret += write(1, "0", 1);
			attr.prec--;
		}
	return (ret);
}

int	ft_addspace8(t_attr attr, unsigned long ul)
{
	int ret;

	ret = 0;
	if (ul == 0 && attr.prec == 0)
		ret++;
	if (ul < 0 && attr.prec != -1 && attr.prec > ft_ptrlen(ul))
		ret--;
	return (ret);
}

int	ft_ifptr(t_attr attr)
{
	unsigned long	ul;
	int				len;
	int				ret;
	int				k;

	ul = (unsigned long)attr.arg;
	len = attr.prec > ft_ptrlen(ul) ? attr.prec : ft_ptrlen(ul);
	if (attr.padd && !ul)
		len++;
	attr.padd += ft_addspace8(attr, ul);
	ret = 0 + ft_addspace3(attr, len);
	attr.padd -= ret;
	ret += write(1, "0x", 2);
	k = ft_addspace4(attr, len);
	ret += k;
	attr.padd -= k;
	k = ft_addspace7(attr, ul);
	ret += k;
	attr.prec -= k;
	if (!(ul == 0 && attr.prec == 0))
		ret += ft_printptr(ul);
	if (ul == 0 && attr.prec == -1)
		ret += write(1, "0", 1);
	ret += ft_addspace6(attr, 0, len, 0);
	return (ret);
}
