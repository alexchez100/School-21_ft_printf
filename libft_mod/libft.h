/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 02:07:38 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/22 22:08:44 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void					*ft_memset(void *s, int c, size_t n);
void					*ft_bzero(void *s, size_t n);
size_t					ft_strlen(const char *s);
int						ft_toupper(int c);
char					*ft_strdup(const char *s);
void					*ft_calloc(size_t memb, size_t size);
char					*ft_substr(char const *s, unsigned int st, size_t len);
char					*ft_itoa(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);

#endif
