/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifpercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:52:07 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/01/31 12:29:46 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_ifpercent(t_attr attr)
{
	int ret;

	ret = 0;
	if (attr.flag == 'w' || attr.flag == '0')
		while (attr.padd > 1)
		{
			ret += attr.flag == 'w' ? write(1, " ", 1) : write(1, "0", 1);
			attr.padd--;
		}
	ret += write(1, "%", 1);
	if (attr.flag == '-')
		while (attr.padd > 1)
		{
			ret += write(1, " ", 1);
			attr.padd--;
		}
	return (ret);
}
