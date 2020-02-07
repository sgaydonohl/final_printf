/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:11:11 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/01 14:32:41 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_intlen(int i)
{
	int len;

	len = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i = -i;
		len++;
	}
	while (i)
	{
		len++;
		i /= 10;
	}
	return (len);
}
