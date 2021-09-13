/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:02:18 by mde-la-s          #+#    #+#             */
/*   Updated: 2020/09/30 19:47:54 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base2(int nbr, char *base_to);
char	*ft_strrev(char *str, int neg);
int		base_len(char *base);

int		check_base(char *base)
{
	int	size_base;
	int	i;
	int	j;

	size_base = 0;
	i = 0;
	j = 0;
	while (base[size_base] && base[size_base] != '+' && base[size_base] != '-'
			&& base[size_base] >= 32 && base[size_base] < 127)
		size_base++;
	if (base[size_base] != 0)
		return (0);
	if (size_base == 0 || size_base == 1)
		return (0);
	while (base[i])
	{
		while (base[++j])
			if (base[i] == base[j])
				return (0);
		i++;
		j = i;
	}
	return (size_base);
}

int		ft_is_in_base(char nbr, char *base)
{
	int i;

	i = 0;
	while (nbr != base[i] && base[i])
		i++;
	if (nbr == base[i])
		return (1);
	return (0);
}

int		ft_pos_base(char nbr, char *base)
{
	int pos;

	pos = 0;
	while (nbr != base[pos] && base[pos])
		pos++;
	return (pos);
}

int		ft_atoi_base(char *nbr, char *base)
{
	int res;
	int size_base;
	int neg;
	int i;

	res = 0;
	size_base = check_base(base);
	neg = 1;
	i = 0;
	if (nbr == 0)
		return (0);
	if (size_base == 0)
		return (0);
	while (nbr[i] == ' ' || nbr[i] == '\f' || nbr[i] == '\n' || nbr[i] == '\r'
			|| nbr[i] == '\t' || nbr[i] == '\v')
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (ft_is_in_base(nbr[i], base) && nbr[i])
		res = res * size_base + ft_pos_base(nbr[i++], base);
	return (res * neg);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		res;
	char	*cpy;
	int		neg;

	res = 0;
	neg = ft_atoi_base(nbr, base_from);
	if (neg < 0)
		neg *= -1;
	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (0);
	if (!(cpy = (char *)malloc(sizeof(char) * 34)))
		return (0);
	if (ft_atoi_base(nbr, base_from) == 0)
	{
		cpy[res] = base_to[res];
		cpy[res + 1] = '\0';
		return (cpy);
	}
	cpy = ft_convert_base2(ft_atoi_base(nbr, base_from), base_to);
	return (cpy);
}
