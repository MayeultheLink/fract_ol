/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_sponge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:32:45 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/25 14:38:30 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img_sponge(t_data *img)
{
	t_sponge	sp;
	int			x;
	int			i;

	color_all(img);
	sp.w = 1;
	i = 1;
	while (i++ <= img->max / 50)
	{
		x = 0;
		sp.divx = 1;
		sp.divy = 1;
		while (sp.w * (sp.divy + 1) < 3)
		{
			while (sp.w * (sp.divx + 1) < 3)
			{
				draw_square_1(img, &sp, x);
				sp.divx += 3;
			}
			sp.divx = 1;
			sp.divy += 3;
		}
		sp.w /= 3;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	draw_square_1(t_data *img, t_sponge *sp, int x)
{
	while (x < img->width)
	{
		sp->x = (x / ((double)img->width / 3)) * img->zoom;
		if (sp->x >= sp->w * sp->divx && sp->x < sp->w * (sp->divx + 1))
			draw_square_2(img, sp, x);
		x++;
	}
}

void	draw_square_2(t_data *img, t_sponge *sp, int x)
{
	int		y;
	int		color;

	color = color_gen(img->max, img->max, img);
	y = 0;
	while (y < img->height)
	{
		sp->y = (y / ((double)img->height / 3)) * img->zoom;
		if (sp->y >= sp->w * sp->divy && sp->y < sp->w * (sp->divy + 1))
			my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

void	color_all(t_data *img)
{
	int	x;
	int	y;
	int	color;

	color = color_gen(img->max / 3, img->max, img);
	x = 0;
	y = 0;
	while (x < img->width)
	{
		while (y < img->height)
		{
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}
