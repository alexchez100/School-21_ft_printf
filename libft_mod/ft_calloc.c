/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 22:07:20 by gsansa            #+#    #+#             */
/*   Updated: 2020/05/18 14:57:07 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t num, size_t size)
{
	void	*mem;

	if (!(mem = (void*)malloc(num * size)))
		return (NULL);
	ft_memset(mem, 0, num * size);
	return (mem);
}
