/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:14:16 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/06 18:14:18 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(char c, int *count, va_list ap);
void	ft_free_mem(char *ita, int *count);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			count += write(1, &format[i], 1);
		if (format[i] == '%' && ft_strchr("csdiupxX%", format[i + 1]))
		{
			ft_parse(format[i + 1], &count, ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

void	ft_parse(char c, int *count, va_list ap)
{
	if (c == '%')
		ft_putpers(count);
	if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	if (c == 'd' || c == 'i')
		ft_free_mem(ft_itoa(va_arg(ap, int)), count);
	if (c == 'u')
		ft_free_mem(ft_itoa_unsigned(va_arg(ap, int)), count);
	if (c == 'x' || c == 'X')
		ft_free_mem(ft_itoa_16(va_arg(ap, int), c), count);
	if (c == 'p')
		ft_free_mem(ft_ptoaddress(va_arg(ap, void *)), count);
}

void	ft_free_mem(char *ita, int *count)
{
	ft_putstr(ita, count);
	free(ita);
}
