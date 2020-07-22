/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:53:35 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/23 01:36:18 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	free_and_return(char *s, int res)
{
	free(s);
	return (res);
}

int			ft_filling(int c, int size)
{
	int		n;

	if (size <= 0)
		return (0);
	n = size;
	while (size--)
		ft_putchar_fd(c, FD);
	return (n);
}

int			print_formated_d(int *mask, char *s)
{
	int		res;

	res = mask[6];
	if (*s == '-' && (mask[1] > 0 || (mask[5] <= 0 && mask[0] >= 0)))
		ft_putchar_fd(*s++, FD);
	if (mask[1] > 0)
	{
		res += ft_filling('0', mask[5] - mask[6]);
		ft_putstr_fd(s, FD);
		res += ft_filling(' ', mask[4] - ft_max(mask[5], mask[6]));
		return (res);
	}
	if (mask[3] > 0 || mask[0] < 0 || mask[5] >= 0)
		res += ft_filling(' ', mask[4] - ft_max(mask[5], mask[6]));
	else
		res += ft_filling('0', mask[4] - ft_max(mask[5], mask[6]));
	if (*s == '-')
		ft_putchar_fd(*s++, FD);
	res += ft_filling('0', mask[5] - mask[6]);
	ft_putstr_fd(s, FD);
	return (res);
}

int			print_formated_p(int *m, char *s)
{
	int		res;

	res = m[6];
	if (m[1] > 0)
	{
		ft_putstr_fd("0x", FD);
		res += ft_filling('0', m[5] - m[6] + 2);
		ft_putstr_fd(s, FD);
		res += ft_filling(' ', m[4] - ft_max(m[5] - m[6] + 2, 0) - m[6]);
		return (res);
	}
	else if (m[0] > 0 && m[5] < 0)
	{
		ft_putstr_fd("0x", FD);
		res += ft_filling('0', m[4] - m[6]);
		ft_putstr_fd(s, FD);
		return (res);
	}
	res += ft_filling(' ', m[4] - ft_max(m[5] - m[6] + 2, 0) - m[6]);
	ft_putstr_fd("0x", FD);
	res += ft_filling('0', m[5] - m[6] + 2);
	ft_putstr_fd(s, FD);
	return (res);
}

int			print_formated_s(int *mask, char *s)
{
	int		res;
	char	*substr;

	substr = ft_substr(s, 0, mask[5]);
	if (!substr)
		return (-1);
	res = ft_strlen(substr);
	mask[6] = res;
	if (mask[1] > 0)
	{
		ft_putstr_fd(substr, FD);
		res += ft_filling(' ', mask[4] - mask[6]);
		return (free_and_return(substr, res));
	}
	else if (mask[0] > 0)
	{
		res += ft_filling('0', mask[4] - mask[6]);
		ft_putstr_fd(substr, FD);
		return (free_and_return(substr, res));
	}
	res += ft_filling(' ', mask[4] - mask[6]);
	ft_putstr_fd(substr, FD);
	return (free_and_return(substr, res));
}
