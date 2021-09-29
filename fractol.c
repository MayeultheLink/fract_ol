/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:17:04 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/27 11:06:18 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	img;

	if (ac == 1 || ((av[1][0] != 'J' && av[1][0] != 'B' && av[1][0] != 'M'
					&& av[1][0] != 'S' && av[1][0] != 'C') || av[1][1]))
	{
		print_help();
		return (0);
	}
	init_img(av[1][0], &img);
	if (img.set == 'C')
	{
		print_commands();
		return (0);
	}
	if (!init_ptr(&img))
	{
		print_error_ptr();
		return (0);
	}
	create_img(&img);
	init_hooks(&img);
	mlx_loop(img.mlx);
	ft_end_all(&img);
	return (0);
}

void	init_img(char set, t_data *img)
{
	img->width = 900;
	img->height = 900;
	img->max = 50;
	if (set == 'J')
	{
		img->reel = -0.4;
		img->imag = 0.6;
		img->width = 300;
		img->height = 300;
	}
	if (set == 'M')
	{
		img->reel = 0;
		img->imag = 0;
	}
	img->x = 0;
	img->y = 0;
	img->refx = img->width / 2;
	img->refy = img->height / 2;
	img->zoom = 1;
	img->set = set;
	img->color = 0;
	img->motion = 0;
}

int	init_ptr(t_data *img)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		return (0);
	img->win = mlx_new_window(img->mlx, img->width, img->height, "new");
	if (!img->win)
	{
		free(img->mlx);
		return (0);
	}
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	if (!img->img)
	{
		ft_close(img);
		free(img->mlx);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
	if (!img->addr)
	{
		ft_close(img);
		mlx_destroy_image(img->mlx, img->img);
		free(img->mlx);
		return (0);
	}
	return (1);
}

void	init_hooks(t_data *img)
{
	mlx_loop_hook(img->mlx, &handle_no_event, img);
	mlx_key_hook(img->win, &handle_input, img);
	mlx_mouse_hook(img->win, &handle_input_mouse, img);
	mlx_hook(img->win, 33, 1L << 17, &ft_close, img);
	if (img->set == 'J')
		mlx_hook(img->win, 6, 1L << 6, &ft_motionnotify, img);
}
