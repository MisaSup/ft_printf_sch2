/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:57:30 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/06 17:57:33 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putpers(int *count)
{
	write(1, "%", 1);
	*count += 1;
}

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	if (s)
	{
		*count += ft_strlen(s);
		write(1, s, ft_strlen(s));
	}
}
