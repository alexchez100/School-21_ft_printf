/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 02:07:38 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/23 01:48:53 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define FD 1

# include <stdarg.h>
# include "libft_mod/libft.h"

const char	*ft_first_star_4(const char *s, int *mask, va_list ap);
const char	*ft_second_star_5(const char *s, int *mask, va_list ap);
const char	*ft_number_is_str(const char *str, int *mask_4_5);

int			ft_max(int a, int b);
int			ft_filling(int c, int size);
int			print_formated_d(int *mask, char *s);
int			print_formated_p(int *m, char *s);
int			print_formated_s(int *mask, char *s);

int			ft_d(int *mask, va_list ap);
int			ft_u(int *mask, va_list ap);
int			ft_x(int *mask, va_list ap);
int			ft_ux(int *mask, va_list ap);
int			ft_ch(int *mask, va_list ap);
int			ft_s(int *mask, va_list ap);
int			ft_p(int *mask, va_list ap);
int			ft_proc(int *mask, va_list ap);

char		*ft_itoa_base(unsigned long n, int base);
int			ft_printf(const char *s, ...);

#endif
