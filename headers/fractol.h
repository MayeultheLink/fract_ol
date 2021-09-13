/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:11:06 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/13 17:04:05 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}				t_data;

t_data	my_mlx_pixel_put(t_data img, int x, int y, int color);
int		handle_input(int keysym, t_data *img);
int		handle_no_event();
t_data	create_img(t_data img);
t_data	draw_img(int x, int y, t_data img);

#endif
