/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:09:46 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/09 16:52:39 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	diagonale
	int		x = 1920 / 2;
	int		y = 1080 / 2;
	while (x < 1920 && y < 1080)
	{
		my_mlx_pixel_put(&img, x, y, 0xAAFFFFFF);
		x++;
		y++;
	}

//	courbe
	int	x = 0;
	int y = 0;
	while (y < 1080)
	{
		while (x < 1920)
		{
			if (sqrt((x * x) + (y * y)) >= 1000 && sqrt((x * x) + (y * y)) <= 1001)
				my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
		x = 0;
	}

//	cercle
	int x = 1920 / 2;
	int y = 1080 / 2;
	int i = -300;
	int j = -300;
	while (j < 1080 / 2)
	{
		while (i < 1920 / 2)
		{
			if (sqrt((i * i) + (j * j)) >= 300 && sqrt((i * i) + (j * j)) <= 301)
			{
				my_mlx_pixel_put(&img, x + i, y + j, 0x00FFFFFF);
				my_mlx_pixel_put(&img, x - i, y - j, 0x00FFFFFF);
			}
			i++;
		}
		j++;
		i = 0;
	}


//	rectangle
	int		x = 1920 / 3;
	int		y = 1080 / 3;
	while (y <= 1080 - (1080 / 3))
	{
		while (x <= 1920 - (1920 / 3))
			my_mlx_pixel_put(&img, x++, y, 0xAAFFFFFF);
		x = 1920 / 3;
		y++;
	}
