/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 22:33:40 by gsansa            #+#    #+#             */
/*   Updated: 2020/05/18 21:31:09 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(int n)
{
	int	i;

	i = 0;
	while ((n /= 10) != 0)
		i++;
	return (i + 1);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		flag;
	int		i;

	i = ft_len_int(n) + 1;
	flag = 1;
	if (n < 0)
	{
		flag = -1;
		i++;
	}
	if (!(res = ft_calloc(sizeof(char), i)))
		return (NULL);
	i = i - 2;
	*(res + i) = (n % 10) * flag + '0';
	while (i-- && (n /= 10) != 0)
		*(res + i) = (n % 10) * flag + '0';
	if (flag == -1)
		*res = '-';
	return (res);
}
