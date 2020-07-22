/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_formats_dxu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:53:35 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/23 01:39:57 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_d(int *mask, va_list ap)
{
	char	*s;
	int		res;

	s = ft_itoa((int)va_arg(ap, int));
	if (!s)
		return (-1);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s);
	if (*s == '-')
		mask[5]++;
	res = print_formated_d(mask, s);
	free(s);
	return (res);
}

int			ft_u(int *mask, va_list ap)
{
	char	*s;
	int		res;

	s = ft_itoa_base(va_arg(ap, unsigned int), 10);
	if (!s)
		return (-1);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s);
	res = print_formated_d(mask, s);
	free(s);
	return (res);
}

int			ft_x(int *mask, va_list ap)
{
	char	*s;
	int		res;

	s = ft_itoa_base(va_arg(ap, unsigned int), 16);
	if (!s)
		return (-1);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s);
	res = print_formated_d(mask, s);
	free(s);
	return (res);
}

char		*ft_upstr(char *str)
{
	char	*metka;

	metka = str;
	while (*metka)
	{
		*metka = ft_toupper(*metka);
		metka++;
	}
	return (str);
}

int			ft_ux(int *mask, va_list ap)
{
	char	*s;
	int		res;

	s = ft_itoa_base(va_arg(ap, unsigned int), 16);
	if (!s)
		return (-1);
	s = ft_upstr(s);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s);
	res = print_formated_d(mask, s);
	free(s);
	return (res);
}
