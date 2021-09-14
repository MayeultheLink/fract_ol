/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:28:30 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/13 17:04:14 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	handle_input(int keysym, t_data *img)
{
	if (keysym == 0xff1b)
		mlx_destroy_window(img->mlx, img->win);
	if (keysym == 0xff54 || keysym == 0xff52 || keysym == 0xff51 
		|| keysym == 0xff53)
		move_win(img, keysym);
	if (keysym == 0x6f || keysym == 0x70)
		zoom(img, keysym);
	return (0);
}

int	handle_no_event()
{
	return (0);
}
