/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:07:39 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/06 18:07:41 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_hex_len(unsigned int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

static char	*iter_tohex(unsigned int num, const char *set,
		char *answ, int str_len)
{
	if (num == 0)
		answ[str_len] = '0';
	while (num > 0)
	{
		answ[str_len] = set[num % 16];
		num /= 16;
		str_len--;
	}
	return (answ);
}	

char	*ft_itoa_16(unsigned int num, char c)
{
	const char	*set;
	char		*answ;
	int			str_len;

	if (c == 'X')
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	str_len = get_hex_len(num) + 1;
	answ = malloc(sizeof(char) * str_len);
	if (!answ)
		return (NULL);
	answ[str_len - 1] = '\0';
	return (iter_tohex(num, set, answ, str_len - 2));
}
