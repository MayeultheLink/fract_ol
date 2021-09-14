/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:00:00 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/13 17:04:14 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_win(t_data *img, int keysym)
{
	if (keysym == 0xff54)
		img->refy -= 50;
	if (keysym == 0xff52)
		img->refy += 50;
	if (keysym == 0xff51)
		img->refx += 50;
	if (keysym == 0xff53)
		img->refx -= 50;
	create_img(img);
}

void	zoom(t_data *img, int keysym)
{
	if (keysym == 0x6f)
	{
		img->zoom *= 2;
		create_img(img);
	}
	if (keysym == 0x70)
	{
		img->zoom /= 2;
		create_img(img);
	}
}
