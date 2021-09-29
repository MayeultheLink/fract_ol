/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:30:45 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/23 16:55:47 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img_julia(t_data *img)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < img->height)
	{
		while (x < img->width)
		{
			draw_img_julia(x, y, img);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	draw_img_julia(int x, int y, t_data *img)
{
	int	color;
	int	i;

	img->new_re = (x - img->refx) / (0.5 * img->width) * img->zoom;
	img->new_im = (y - img->refy) / (0.5 * img->height) * img->zoom;
	i = nmb_iter_julia(img);
	color = color_gen(i, img->max, img);
	if (i < img->max)
		my_mlx_pixel_put(img, x, y, color);
	else
		my_mlx_pixel_put(img, x, y, 0);
}

int	nmb_iter_julia(t_data *img)
{
	int	i;

	i = 0;
	while (i < img->max)
	{
		img->old_re = img->new_re;
		img->old_im = img->new_im;
		img->new_re = img->old_re * img->old_re - img->old_im
			* img->old_im + img->reel;
		img->new_im = 2 * img->old_re * img->old_im + img->imag;
		if ((img->new_re * img->new_re + img->new_im * img->new_im) > 4)
			break ;
		i++;
	}
	return (i);
}
