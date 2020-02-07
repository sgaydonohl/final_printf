/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:36:20 by sgaydon-          #+#    #+#             */
/*   Updated: 2020/02/02 21:45:42 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MINHEXA "0123456789abcdef"
# define MAJHEXA "0123456789ABCDEF"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_attr
{
	char	flag;
	int		padd;
	int		prec;
	char	conv_spec;
	void	*arg;
}				t_attr;

int				ft_strlen(const char *str);
int				ft_intlen(int i);
int				ft_uintlen(unsigned int i);
int				ft_hexlen(unsigned int i);
int				ft_isdigit(int i);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_printnum(int nb);
int				ft_printunum(unsigned int nb);
int				ft_printhex(unsigned int nb, int maj);
int				ft_printptr(unsigned long nb);
int				ft_ptrlen(unsigned long nb);
int				ft_atoi(const char *str);
int				ft_isdigit(int i);
int				ft_inarray(char c, char *s);
int				ft_addspace2(t_attr attr, int nb);
int				ft_addspace3(t_attr attr, int len);
int				ft_addspace4(t_attr attr, int len);
int				ft_addspace5(t_attr attr, unsigned int n);
int				ft_addspace6(t_attr attr, unsigned int n, int len, int print);

int				ft_ifchar(t_attr attr);
int				ft_ifint(t_attr attr);
int				ft_ifuint(t_attr attr);
int				ft_ifptr(t_attr attr);
int				ft_ifstr(t_attr attr);
int				ft_ifhex(t_attr attr, int maj);
int				ft_ifpercent(t_attr attr);

char			ft_whichflag(const char **str);
int				ft_whichpadd(const char **str, va_list *args);
int				ft_whichprec(const char **str, va_list *args);

int				ft_printf(const char *str, ...);
#endif
