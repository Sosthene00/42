/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:29:18 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/30 20:11:28 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*reverse(char *str, int len)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		res[i] = str[len - 1 - i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static	size_t	negative(int n)
{
	size_t	nb;

	if (n == INT_MIN)
	{
		nb = (n + 1) * -1;
		return (nb + 1);
	}
	else
		return (nb = n * -1);
}

static	int		to_string(size_t nb, char *tmp, int len)
{
	if (nb == 0)
	{
		tmp[0] = '0';
		len++;
	}
	while (nb != 0)
	{
		tmp[len] = (nb % 10) + '0';
		nb /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		neg;
	int		len;
	size_t	nb;
	char	tmp[15];
	char	*res;

	neg = 0;
	len = 0;
	if (n < 0)
	{
		neg = 1;
		nb = negative(n);
	}
	else
		nb = n;
	len = to_string(nb, tmp, len);
	if (neg == 1)
	{
		tmp[len] = '-';
		len++;
	}
	return (res = reverse(tmp, len));
}
