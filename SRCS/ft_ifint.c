/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:54:07 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 21:08:23 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_ifint(t_attr attr)
{
	unsigned int	n;
	int				ret;
	int				len;
	int				nb;
	int				k;

	nb = (int)attr.arg;
	len = attr.prec > ft_intlen(nb) ? attr.prec : ft_intlen(nb);
	attr.padd += ft_addspace2(attr, nb);
	ret = 0 + ft_addspace3(attr, len);
	attr.padd -= ret;
	if (nb < 0)
		ret += write(1, "-", 1);
	n = nb < 0 ? -nb : nb;
	k = ft_addspace4(attr, len);
	ret += k;
	attr.padd -= k;
	k = ft_addspace5(attr, n);
	ret += k;
	attr.prec -= k;
	ret += ft_addspace6(attr, n, len, 1);
	return (ret);
}
