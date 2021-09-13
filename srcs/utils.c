/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:28:30 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/13 16:30:57 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	my_mlx_pixel_put(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return (img);
}

int	handle_input(int keysym, t_data *img)
{
	if (keysym == 0x35)
		mlx_destroy_window(img->mlx, img->win);
	return (0);
}

int	handle_no_event(void *data)
{
	return (0);
}
