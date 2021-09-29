/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:28:30 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/25 16:04:38 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	handle_input(int keysym, t_data *img)
{
	if (keysym == KEY_C && img->set == 'J')
		img->motion++;
	if (keysym == KEY_ESC)
		mlx_destroy_window(img->mlx, img->win);
	if (keysym == ARROW_DOWN || keysym == ARROW_UP || keysym == ARROW_LEFT
		|| keysym == ARROW_RIGHT || keysym == SPACE_BAR)
		move_win(img, keysym);
	if (keysym == KEY_O || keysym == KEY_P)
		zoom_key(img, keysym);
	if (keysym == KEY_0 || keysym == KEY_1 || keysym == KEY_2
		|| keysym == KEY_3)
		color_change(img, keysym);
	if (keysym == KEY_R || keysym == KEY_T)
		zoom_key(img, keysym);
	return (0);
}

int	handle_input_mouse(int keysym, int x, int y, t_data *img)
{
	if (keysym == CLICK)
	{
		img->refx += (img->width / 2) - x;
		img->refy += (img->height / 2) - y;
		if (img->set == 'M')
			create_img_mandelbrot(img);
		if (img->set == 'B')
			create_img_bs(img);
		if (img->set == 'J')
			create_img_julia(img);
	}
	if (keysym == SCROLL_UP || keysym == SCROLL_DOWN)
	{
		img->x = (double)x;
		img->y = (double)y;
		zoom_scroll(img, keysym);
	}
	return (0);
}

int	handle_no_event(void)
{
	return (0);
}
