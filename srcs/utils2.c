/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:28:30 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/25 16:12:36 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_motionnotify(int x, int y, t_data *img)
{
	if (img->motion % 2 == 1)
	{
		img->reel = ((double)x - (img->width / 2)) / (img->width / 2);
		img->imag = ((double)y - (img->height / 2)) / (img->height / 2);
		create_img_julia(img);
	}
	return (0);
}

int	ft_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	return (0);
}

void	ft_end_all(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
}

void	create_img(t_data *img)
{
	if (img->set == 'M')
		create_img_mandelbrot(img);
	if (img->set == 'J')
		create_img_julia(img);
	if (img->set == 'S')
		create_img_sponge(img);
	if (img->set == 'B')
		create_img_bs(img);
}
