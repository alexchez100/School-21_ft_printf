/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_formats_pcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:53:35 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/22 21:58:10 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_ch(int *mask, va_list ap)
{
	char	c;
	int		res;

	c = (char)va_arg(ap, int);
	res = 1;
	if (mask[1] > 0)
	{
		ft_putchar_fd(c, FD);
		res += ft_filling(' ', mask[4] - 1);
		return (res);
	}
	if (mask[0] > 0)
		res += ft_filling('0', mask[4] - 1);
	else
		res += ft_filling(' ', mask[4] - 1);
	ft_putchar_fd(c, FD);
	return (res);
}

int		ft_s(int *mask, va_list ap)
{
	char	*s;
	int		res;
	int		flag;

	flag = 0;
	s = va_arg(ap, char *);
	if (!s)
	{
		s = ft_strdup("(null)");
		flag = 1;
	}
	res = print_formated_s(mask, s);
	if (flag == 1)
		free(s);
	return (res);
}

int		ft_p(int *mask, va_list ap)
{
	char			*s;
	unsigned long	res;
	int				len;

	res = va_arg(ap, unsigned long);
	s = ft_itoa_base(res, 16);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s) + 2;
	len = print_formated_p(mask, s);
	free(s);
	return (len);
}

int		ft_proc(int *mask, va_list ap)
{
	const char	c = '%';
	int			res;
	va_list		a;

	va_copy(a, ap);
	va_end(a);
	res = 1;
	if (mask[1] > 0)
	{
		ft_putchar_fd(c, FD);
		res += ft_filling(' ', mask[4] - 1);
		return (res);
	}
	if (mask[0] > 0)
		res += ft_filling('0', mask[4] - 1);
	else
		res += ft_filling(' ', mask[4] - 1);
	ft_putchar_fd(c, FD);
	return (res);
}
