/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:24:40 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/01 14:32:32 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int		ft_printhex(unsigned int nb, int maj)
{
	char			s[9];
	int				i;
	unsigned int	nig;
	char			*base;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	base = maj == 0 ? MINHEXA : MAJHEXA;
	i = 7;
	nig = nb;
	while (nig > 0)
	{
		s[i--] = base[nig % 16];
		nig /= 16;
	}
	s[8] = '\0';
	write(1, &s[i + 1], 7 - i);
	return (7 - i);
}
