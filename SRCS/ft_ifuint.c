/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:54:07 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 21:27:18 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_addspace9(t_attr attr, unsigned int nb)
{
	int ret;

	ret = 0;
	if (attr.prec != -1)
		while (attr.prec - ft_uintlen(nb) > 0)
		{
			ret += write(1, "0", 1);
			attr.prec--;
		}
	return (ret);
}

int	ft_ifuint(t_attr attr)
{
	unsigned int	nb;
	int				ret;
	int				neg;
	int				len;
	int				k;

	nb = (unsigned int)attr.arg;
	neg = nb < 0 ? 1 : 0;
	len = attr.prec > ft_uintlen(nb) ? attr.prec : ft_uintlen(nb);
	ret = 0;
	if (nb == 0 && attr.prec == 0)
		attr.padd++;
	ret = 0 + ft_addspace3(attr, len);
	attr.padd -= ret;
	if (nb < 0)
	{
		nb = -nb;
		ret += write(1, "-", 1);
	}
	k = ft_addspace4(attr, len);
	ret += k;
	attr.padd -= k;
	ret += ft_addspace9(attr, nb);
	ret += ft_addspace6(attr, nb, len, 1);
	return (ret);
}
