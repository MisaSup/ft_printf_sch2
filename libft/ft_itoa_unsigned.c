/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:42 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/06 18:02:45 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	digit_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (i == 0)
		++i;
	return (i);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char		*answ;
	int			i;

	answ = (char *)malloc(sizeof(char) * (digit_len(n) + 1));
	if (answ == NULL)
		return (NULL);
	i = digit_len(n) - 1;
	answ[i + 1] = '\0';
	while (i >= 0)
	{
		answ[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (answ);
}
