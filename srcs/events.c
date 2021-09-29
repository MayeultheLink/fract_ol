/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:00:00 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/25 15:54:37 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_win(t_data *img, int keysym)
{
	if (keysym == SPACE_BAR)
		init_img(img->set, img);
	if (keysym == ARROW_DOWN)
		img->refy -= 50;
	if (keysym == ARROW_UP)
		img->refy += 50;
	if (keysym == ARROW_LEFT)
		img->refx += 50;
	if (keysym == ARROW_RIGHT)
		img->refx -= 50;
	create_img(img);
}

void	zoom_key(t_data *img, int keysym)
{
	if (keysym == KEY_R && img->max > 50)
		img->max -= 50;
	if (keysym == KEY_T)
		img->max += 50;
	if (keysym == KEY_O)
	{
		if (img->set == 'S')
			img->zoom *= 1.1;
		else
			img->zoom *= 2;
		img->refx += (img->width / 2 - img->refx) / 2;
		img->refy += (img->height / 2 - img->refy) / 2;
	}
	if (keysym == KEY_P)
	{
		if (img->set == 'S')
			img->zoom /= 1.1;
		else
			img->zoom /= 2;
		img->refx -= img->width / 2 - img->refx;
		img->refy -= img->height / 2 - img->refy;
	}
	create_img(img);
}

void	zoom_scroll(t_data *img, int keysym)
{
	if (keysym == SCROLL_DOWN)
	{
		if (img->set == 'S')
			img->zoom *= 1.1;
		else
			img->zoom *= 2;
		img->refx += ((img->width / 2 - img->refx)
				+ (img->x - img->width / 2)) / 2;
		img->refy += ((img->height / 2 - img->refy)
				+ (img->y - img->height / 2)) / 2;
	}
	if (keysym == SCROLL_UP)
	{
		if (img->set == 'S')
			img->zoom /= 1.1;
		else
			img->zoom /= 2;
		img->refx -= (img->width / 2 - img->refx) + (img->x - img->width / 2);
		img->refy -= (img->height / 2 - img->refy) + (img->y - img->height / 2);
	}
	create_img(img);
}

void	color_change(t_data *img, int keysym)
{
	if (keysym == KEY_0)
		img->color = 0;
	if (keysym == KEY_1)
		img->color = 1;
	if (keysym == KEY_2)
		img->color = 2;
	if (keysym == KEY_3)
		img->color = 3;
	create_img(img);
}
