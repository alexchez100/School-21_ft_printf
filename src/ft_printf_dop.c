/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:53:35 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/22 21:57:58 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

const char	*ft_first_star_4(const char *s, int *mask, va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	mask[2] = 1;
	if (num < 0)
	{
		mask[4] = num * (-1);
		mask[1] = 1;
	}
	else
		mask[4] = num;
	return (++s);
}

const char	*ft_second_star_5(const char *s, int *mask, va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	mask[3] = 1;
	if (num < 0)
	{
		mask[5] = -9;
		mask[3] = 0;
	}
	else
		mask[5] = num;
	return (++s);
}

const char	*ft_number_is_str(const char *str, int *mask_4_5)
{
	long long	n;

	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + ((*str) - '0');
		str++;
	}
	*mask_4_5 = (int)n;
	return (str);
}
