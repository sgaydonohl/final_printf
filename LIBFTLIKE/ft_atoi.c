/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:29:15 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/01/30 16:06:31 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int			ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while (*str > 47 && *str < 58)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result);
}
