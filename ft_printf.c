/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:00:14 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/01 16:57:27 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/ft_printf.h"

int		ft_printarg(t_attr attr)
{
	int ret;

	if (attr.conv_spec == 'c')
		ret = ft_ifchar(attr);
	if (attr.conv_spec == 's')
		ret = ft_ifstr(attr);
	if (attr.conv_spec == 'p')
		ret = ft_ifptr(attr);
	if (attr.conv_spec == 'd')
		ret = ft_ifint(attr);
	if (attr.conv_spec == 'i')
		ret = ft_ifint(attr);
	if (attr.conv_spec == 'u')
		ret = ft_ifuint(attr);
	if (attr.conv_spec == 'x')
		ret = ft_ifhex(attr, 0);
	if (attr.conv_spec == 'X')
		ret = ft_ifhex(attr, 1);
	if (attr.conv_spec == '%')
		ret = ft_ifpercent(attr);
	return (ret);
}

t_attr	ft_handleattr(const char **str, va_list *args)
{
	t_attr	attr;

	attr.flag = ft_whichflag(str);
	attr.padd = ft_whichpadd(str, args);
	if (attr.padd < 0)
	{
		attr.padd = -attr.padd;
		attr.flag = '-';
	}
	attr.prec = ft_whichprec(str, args);
	attr.conv_spec = **str;
	if (!(**str == '%'))
		attr.arg = va_arg(*args, void *);
	return (attr);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_attr	attr;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			attr = ft_handleattr(&str, &args);
			if (!ft_inarray(*str, "cspdiuxX%"))
				return (count);
			count += ft_printarg(attr);
			str++;
		}
		else
			count += write(1, str++, 1);
	}
	va_end(args);
	return (count);
}
