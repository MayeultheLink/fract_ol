/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:30:45 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/13 16:15:16 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	create_img(t_data img)
{
	int		y;
	int		x;

	y = 0;
	while (y < img.height)
	{
		while (x < img.width)
		{
			img = draw_img(x, y, img);
			x++;
		}
		y++;
		x = 0;
	}
	return (img);
}

t_data	draw_img(int x, int y, t_data img)
{
	double cRe, cIm;
	double newRe, newIm, oldRe, oldIm;
	cRe = -0.8;
	cIm = 0.156;
	int	max = 300;
	int i;
	int color = 0;

	newRe = 1.5 * (x - img.width / 2) / (0.5 * img.width);
	newIm = (y - img.height / 2) / (0.5 * img.height);
	i = 0;
	while (i < max)
	{
		oldRe = newRe;
		oldIm = newIm;

		newRe = oldRe * oldRe - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;

		if ((newRe * newRe + newIm * newIm) > 4)
			break ;
		i++;
	}
	color = 0;
	if (i < (max / 3))
		color = 16777215 - (65536 * (i * 100 / (max / 3)));
	else if (i < ((max / 3) * 2))
		color = 12493687 - (65793 * ((i - (max / 3)) * 100 / (max / 3)));
	if (i < max && i > ((max / 3) * 2))
		color = 14408667 - (65793 * ((i - (max / 3)) * 100 / (max / 3)));
	if (i < max)
		img = my_mlx_pixel_put(img, x, y, color);
	return (img);
}
