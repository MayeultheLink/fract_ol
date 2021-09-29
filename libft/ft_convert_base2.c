/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:41:16 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/22 12:09:27 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_is_neg(int nbr)
{
	if (nbr < 0)
		return (-1);
	return (1);
}

char	*ft_strrev(char *str, int neg)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	if (ft_is_neg(neg) == -1)
		j = 1;
	while (str[i])
		i++;
	i -= 1;
	while (j < i)
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		j++;
		i--;
	}
	return (str);
}

char	*ft_putnbr(long nbrl, char *cpy, int size_base, char *base_to)
{
	int	i;

	i = 0;
	if (ft_is_neg(nbrl) == -1)
	{
		cpy[i] = '-';
		nbrl *= -1;
		i++;
	}
	while (nbrl)
	{
		cpy[i] = base_to[nbrl % size_base];
		nbrl /= size_base;
		i++;
	}
	return (cpy);
}

char	*ft_convert_base2(int nbr, char *base_to)
{
	int		size_base;
	int		i;
	char	*cpy;
	int		neg;
	long	nbrl;

	size_base = base_len(base_to);
	i = 0;
	neg = nbr;
	nbrl = nbr;
	cpy = (char *)malloc(sizeof(char) * 34);
	if (!cpy)
		return (0);
	ft_putnbr(nbrl, cpy, size_base, base_to);
	ft_strrev(cpy, neg);
	while (cpy[i])
		i++;
	cpy[i] = 0;
	return (cpy);
}
