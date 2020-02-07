/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:27:45 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 19:52:01 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_itohex(int nb)
{
	char			s[12];
	int				i;
	unsigned int	nig;
	char			base[17];

	ft_memcpy(base, "0123456789abcdef", 16);
	nig = (nb < 0) ? -nb : nb;
	i = 10;
	while (nig > 16)
	{
		s[i--] = base[nig % 16];
		nig /= 16;
	}
	s[i--] = base[nig % 16];
	s[11] = '\0';
	write(1, &s[i], 11 - i);
	return (11 - i);
}
