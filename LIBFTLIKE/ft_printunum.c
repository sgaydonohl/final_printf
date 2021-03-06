/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:24:40 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/01 14:00:33 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_printunum(unsigned int nb)
{
	char			s[12];
	int				i;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 10;
	while (nb > 0)
	{
		s[i--] = nb % 10 + 48;
		nb /= 10;
	}
	if (nb < 0)
		s[i--] = '-';
	s[11] = '\0';
	write(1, &s[i + 1], 10 - i);
	return (10 - i);
}
