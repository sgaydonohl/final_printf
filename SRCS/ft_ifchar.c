/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:52:07 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 19:54:18 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_ifchar(t_attr attr)
{
	int		ret;
	char	c;

	c = (unsigned char)attr.arg;
	ret = 0;
	if (attr.flag != '-')
		while (attr.padd > 1)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	ret += write(1, &c, 1);
	if (attr.flag == '-')
		while (attr.padd > 1)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	return (ret);
}
