/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:53:35 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/23 01:33:39 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int			ft_defining_modifier(int c)
{
	const char	*massiv = "cspdiuxX%";
	int			i;

	i = 0;
	while (massiv[i] != '\0')
	{
		if ((char)c == massiv[i])
			return (++i);
		i++;
	}
	return (0);
}

static const char	*ft_print_text(const char *s, int *res)
{
	const char	*start = s;

	if (*res == -1)
		return (s);
	while (*s && *s != '%')
		s++;
	*res = *res + s - start;
	if (start)
		write(FD, start, s - start);
	return (s);
}

static int			ft_result_result(int *mask, int c, va_list ap, int *ret)
{
	int	(*oper[10]) (int *, va_list);
	int	res;

	if (c == 0)
		return (0);
	oper[0] = 0;
	oper[1] = ft_ch;
	oper[2] = ft_s;
	oper[3] = ft_p;
	oper[4] = ft_d;
	oper[5] = ft_d;
	oper[6] = ft_u;
	oper[7] = ft_x;
	oper[8] = ft_ux;
	oper[9] = ft_proc;
	res = oper[c](mask, ap);
	if (res == -1)
		*ret = -1;
	else
		*ret = *ret + res;
	return (1);
}

static const char	*ft_do_modifik(const char *s, va_list ap, int *ret)
{
	int	mask[7];

	ft_memset(mask, -9, sizeof(int) * 7);
	while (*s == '-' || *s == '0')
	{
		if (*s == '0')
			mask[0] = 1;
		if (*s == '-')
			mask[1] = 1;
		s++;
	}
	if (*s == '*')
		s = ft_first_star_4(s, mask, ap);
	else
		s = ft_number_is_str(s, &mask[4]);
	if (*s == '.')
	{
		if (*(++s) == '*')
			s = ft_second_star_5(s, mask, ap);
		else
			s = ft_number_is_str(s, &mask[5]);
	}
	ft_result_result(mask, ft_defining_modifier(*s), ap, ret);
	return (++s);
}

int					ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, s);
	res = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (res == -1)
			return (-1);
		if (*s == '%')
			s = ft_do_modifik(++s, ap, &res);
		s = ft_print_text(s, &res);
	}
	va_end(ap);
	return (res);
}
