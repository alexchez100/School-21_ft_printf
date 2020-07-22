/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:53:35 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/22 21:57:45 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_len_itoa_base(unsigned long n, int base)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(unsigned long n, int base)
{
	char			*str;
	int				i;
	const char		*massiv = "0123456789abcdef";

	i = ft_len_itoa_base(n, base);
	str = ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	i--;
	*(str + i) = massiv[n % base];
	while (n != 0)
	{
		*(str + i) = massiv[n % base];
		n = n / base;
		i--;
	}
	return (str);
}
