/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_burning_ship.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:22:45 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/22 17:23:34 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img_bs(t_data *img)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < img->height)
	{
		while (x < img->width)
		{
			draw_img_bs(x, y, img);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	draw_img_bs(int x, int y, t_data *img)
{
	int	color;
	int	i;

	img->pr = (x - img->refx) / (0.5 * img->width) * img->zoom;
	img->pi = (y - img->refy) / (0.5 * img->height) * img->zoom;
	img->new_re = 0;
	img->new_im = 0;
	i = nmb_iter_bs(img);
	color = color_gen(i, img->max, img);
	if (i < img->max)
		my_mlx_pixel_put(img, x, y, color);
	else
		my_mlx_pixel_put(img, x, y, 0);
}

int	nmb_iter_bs(t_data *img)
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
		if (img->new_im < 0)
			img->new_im *= -1;
		if (img->new_re < 0)
			img->new_re *= -1;
		if ((img->new_re * img->new_re + img->new_im * img->new_im) > 4)
			break ;
		i++;
	}
	return (i);
}
