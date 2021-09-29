/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:30:45 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/22 12:13:34 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_gen(int i, int max, t_data *img)
{
	int	color;

	if (img->color == 0)
		color = color_gen_0(i, max);
	if (img->color == 1)
		color = color_gen_1(i, max);
	if (img->color == 2)
		color = color_gen_2(i, max);
	if (img->color == 3)
		color = color_gen_3(i, max);
	return (color);
}

int	color_gen_0(int i, int max)
{
	int	color;

	if (i < (max / 3))
		color = 16777215 - (65536 * (i * 100 / (max / 3)));
	else if (i <= ((max / 3) * 2))
		color = 16121855 - ((65793 * ((i - (max / 3)) * 100 / (max / 3))) * 2);
	if (i <= max && i > ((max / 3) * 2))
		color = 3891849 + ((65793) * ((i - ((max / 3) * 2)) * 100 / (max / 3)));
	return (color);
}

int	color_gen_1(int i, int max)
{
	int	color;

	if (i < (max / 3))
		color = (1537 * (i * 100 / (max / 3)));
	else if (i <= ((max / 3) * 2))
		color = 16121 - ((65793 * ((i - (max / 3)) * 100 / (max / 3))) * 2);
	if (i <= max && i > ((max / 3) * 2))
		color = 38 + ((65793) * ((i - ((max / 3) * 2)) * 100 / (max / 3)));
	return (color);
}

int	color_gen_2(int i, int max)
{
	int	color;

	if (i < (max / 3))
		color = 5729 + (521 * (i * 100 / (max / 3)));
	else if (i <= ((max / 3) * 2))
		color = 15592568 - ((65700 * ((i - (max / 3)) * 100 / (max / 3))) * 2);
	if (i <= max && i > ((max / 3) * 2))
		color = 389000 - ((65793) * ((i - ((max / 3) * 2)) * 100 / (max / 3)));
	return (color);
}

int	color_gen_3(int i, int max)
{
	int	color;

	if (i < (max / 3))
		color = 65536 * (i * 100 / (max / 3));
	else if (i <= ((max / 3) * 2))
		color = 4718689 + ((65536 * ((i - (max / 3)) * 100 / (max / 3))) * 2);
	if (i <= max && i > ((max / 3) * 2))
		color = 29734 + ((65793) * ((i - ((max / 3) * 2)) * 100 / (max / 3)));
	return (color);
}
