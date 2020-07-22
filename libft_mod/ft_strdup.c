/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:07:13 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/22 22:05:49 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*p;
	char	*start;

	p = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(p))
		return (NULL);
	start = p;
	while (*str)
		*p++ = *str++;
	*p = '\0';
	return (start);
}
