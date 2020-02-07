/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:26:35 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/01/11 16:04:26 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_ptr;
	const char	*src_ptr;

	src_ptr = (const char *)src;
	dst_ptr = (char *)dst;
	if (!n || (src_ptr == dst_ptr && src_ptr == NULL))
		return (dst);
	while (n > 0)
	{
		*dst_ptr++ = *src_ptr++;
		n--;
	}
	return (dst);
}
