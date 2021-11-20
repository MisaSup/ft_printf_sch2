/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:05:26 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/06 18:12:06 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putpers(int *count);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_16(unsigned int num, char c);
char	*ft_ptoaddress(void *point);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		digit_len(long int n);
void	ft_free_mem(char *ita, int *count);

#endif
