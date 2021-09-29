/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_mandelbrot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:30:45 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/22 12:13:52 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img_mandelbrot(t_data *img)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < img->height)
	{
		while (x < img->width)
		{
			draw_img_mandelbrot(x, y, img);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	draw_img_mandelbrot(int x, int y, t_data *img)
{
	int	color;
	int	i;

	img->pr = (x - img->refx) / (0.5 * img->width) * img->zoom;
	img->pi = (y - img->refy) / (0.5 * img->height) * img->zoom;
	img->new_re = 0;
	img->new_im = 0;
	i = nmb_iter_mandelbrot(img);
	color = color_gen(i, img->max, img);
	if (i < img->max)
		my_mlx_pixel_put(img, x, y, color);
	else
		my_mlx_pixel_put(img, x, y, 0x00000000);
}

int	nmb_iter_mandelbrot(t_data *img)
{
	int	i;

	i = 0;
	while (i < img->max)
	{
		img->old_re = img->new_re;
		img->old_im = img->new_im;
		img->new_re = img->old_re * img->old_re - img->old_im
			* img->old_im + img->pr;
		img->new_im = 2 * img->old_re * img->old_im + img->pi;
		if ((img->new_re * img->new_re + img->new_im * img->new_im) > 4)
			break ;
		i++;
	}
	return (i);
}
