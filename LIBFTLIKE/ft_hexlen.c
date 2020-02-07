/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:11:11 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/01 14:36:54 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_hexlen(unsigned int nb)
{
	char			s[9];
	int				i;
	unsigned int	nig;
	char			*base;

	if (nb == 0)
	{
		return (1);
	}
	base = MAJHEXA;
	i = 7;
	nig = nb;
	while (nig > 0)
	{
		s[i--] = base[nig % 16];
		nig /= 16;
	}
	s[8] = '\0';
	return (7 - i);
}
