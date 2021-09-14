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

void	create_img(t_data *img)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < img->height)
	{
		while (x < img->width)
		{
			draw_img(x, y, img);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	draw_img(int x, int y, t_data *img)
{
	int color;
	int	i;

	img->newRe = 1.5 * (x - img->refx) / (0.5 * img->width) * img->zoom;
	img->newIm = (y - img->refy) / (0.5 * img->height) * img->zoom;
	i = nmb_iter(img);
	color = color_gen(i, img->max);
	if (i < img->max)
		my_mlx_pixel_put(img, x, y, color);
	else
		my_mlx_pixel_put(img, x, y, 0x000000);
}

int	nmb_iter(t_data *img)
{
	int	i;

	i = 0;
	while (i < img->max)
	{
		img->oldRe = img->newRe;
		img->oldIm = img->newIm;
		img->newRe = img->oldRe * img->oldRe - img->oldIm * img->oldIm + img->reel;
		img->newIm = 2 * img->oldRe * img->oldIm + img->imag;
		if ((img->newRe * img->newRe + img->newIm * img->newIm) > 4)
			break ;
		i++;
	}
	return (i);
}

int	color_gen(int i, int max)
{
	int	color;

	if (i < (max / 3))
	{
		color = 16777215 - (65536 * (i * 100 / (max / 3)));
		if (color < 10223615)
			color = 10223615 - (65793 * ((i - (max / 3)) * 100 / (max / 3)));
	}
	else if (i < ((max / 3) * 2))
		color = 12493687 - (65793 * ((i - (max / 3)) * 100 / (max / 3)));
	if (i < max && i > ((max / 3) * 2))
		color = 14408667 - (65793 * ((i - (max / 3)) * 100 / (max / 3)));
	return (color);
}
