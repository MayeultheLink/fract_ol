/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:17:04 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/13 16:42:33 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int	main()
{
	t_data	img;

	img.width = 1920;
	img.height = 1080;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "new");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	img = create_img(img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop_hook(img.mlx, &handle_no_event, &img);
	mlx_key_hook(img.win, &handle_input, &img);
	mlx_loop(img.mlx);
//	mlx_destroy_display(img.mlx);
//	free(img.mlx);
	return (0);
}
