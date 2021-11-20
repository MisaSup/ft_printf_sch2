/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:00:30 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/06 18:00:32 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_printf.h"

static int	get_hex_len(unsigned long long num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

static char	*iter_tohex(unsigned long long num,
		const char *set, char *answ, int str_len)
{
	while (num > 0 && str_len > 1)
	{
		answ[str_len] = set[num % 16];
		num /= 16;
		str_len--;
	}
	return (answ);
}	

char	*ft_ptoaddress(void *point)
{
	const char	*set;
	char		*answ;
	int			str_len;
	long long	num;

	if (!point)
		return (ft_strdup("0x0"));
	num = (long long)point;
	set = "0123456789abcdef";
	str_len = get_hex_len(num) + 3;
	answ = malloc(sizeof(char) * str_len);
	if (!answ)
		return (NULL);
	answ[str_len - 1] = '\0';
	answ[0] = '0';
	answ[1] = 'x';
	return (iter_tohex(num, set, answ, str_len - 2));
}

/*int main(void)
{
	// int j = 0;
	char *p = NULL;
	// unsigned int u = -1;
	printf("%lld \n", (long long)p);
	printf("%s\n", ft_ptoaddress(p));
	printf("%d\n", printf("%p\n", p));
	// printf("%s\n", ft_lltopointer(149079860));
	// printf("%s\n", ft_lltopointer(140736939079860));
	return 0;
}*/
