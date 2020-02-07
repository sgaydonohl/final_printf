/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:53:07 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 19:58:31 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_ifstr(t_attr attr)
{
	char	*s;
	int		len;
	int		ret;

	s = (char *)attr.arg;
	if (!s)
		s = "(null)";
	len = (attr.prec != -1 && attr.prec < ft_strlen(s)) ? \
		attr.prec : ft_strlen(s);
	ret = 0;
	if (attr.flag == 'w')
		while (attr.padd - len > 0)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	ret += write(1, s, len);
	if (attr.flag == '-')
		while (attr.padd - len > 0)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	return (ret);
}
