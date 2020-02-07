/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:24:40 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 19:52:11 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_printnum(int nb)
{
	char			s[12];
	int				i;
	unsigned int	nig;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	nig = (nb < 0) ? -nb : nb;
	i = 10;
	while (nig > 0)
	{
		s[i--] = nig % 10 + 48;
		nig /= 10;
	}
	if (nb < 0)
		s[i--] = '-';
	s[11] = '\0';
	write(1, &s[i + 1], 10 - i);
	return (10 - i);
}
