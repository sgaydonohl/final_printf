/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:24:40 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/01 14:56:37 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int		ft_printptr(unsigned long nb)
{
	char	s[16];
	int		i;
	int		ret;

	i = 14;
	while (nb > 0)
	{
		s[i--] = MINHEXA[nb % 16];
		nb /= 16;
	}
	s[15] = '\0';
	ret = 0;
	ret += write(1, &s[i + 1], 14 - i);
	return (ret);
}
