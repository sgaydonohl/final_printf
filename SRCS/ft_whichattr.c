/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whichattr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 07:18:46 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/01 16:25:54 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

char	ft_whichflag(const char **str)
{
	char f;

	f = 'w';
	while (ft_inarray(**str, "0-"))
	{
		if (f != '-')
			f = **str;
		*str += 1;
	}
	return (f);
}

int		ft_whichpadd(const char **str, va_list *args)
{
	int p;

	p = 0;
	if (**str == '*')
	{
		p = va_arg(*args, int);
		*str += 1;
	}
	else
	{
		p = ft_atoi(*str);
		while (ft_isdigit(**str))
			*str += 1;
	}
	return (p);
}

int		ft_whichprec(const char **str, va_list *args)
{
	int p;

	p = -1;
	if (**str == '.')
	{
		*str += 1;
		if (**str == '*')
		{
			p = va_arg(*args, int);
			*str += 1;
		}
		else
		{
			p = ft_atoi(*str);
			while (ft_isdigit(**str))
				*str += 1;
		}
		p = p < 0 ? -1 : p;
	}
	return (p);
}
