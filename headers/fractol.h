/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:11:06 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/27 11:06:35 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

# define CLICK 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define SPACE_BAR 32
# define KEY_C 99
# define KEY_O 111
# define KEY_P 112
# define KEY_R 114
# define KEY_T 116
# define KEY_ESC 65307
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define KEY_0 49
# define KEY_1 50
# define KEY_2 51
# define KEY_3 52

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		max;
	double	x;
	double	y;
	int		refx;
	int		refy;
	int		color;
	double	zoom;
	double	reel;
	double	imag;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	pr;
	double	pi;
	char	set;
	int		motion;
}				t_data;

typedef struct s_sponge {
	double	x;
	double	y;
	int		divx;
	int		divy;
	double	w;
	double	h;
}				t_sponge;

void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		handle_input(int keysym, t_data *img);
int		ft_close(t_data *img);
void	ft_end_all(t_data *img);
int		ft_motionnotify(int x, int y, t_data *img);
int		handle_input_mouse(int keysym, int x, int y, t_data *img);
int		handle_no_event(void);
void	print_help(void);
void	print_commands(void);
void	print_commands2(void);
void	print_error_ptr(void);
void	create_img(t_data *img);
void	create_img_julia(t_data *img);
void	draw_img_julia(int x, int y, t_data *img);
int		nmb_iter_julia(t_data *img);
void	create_img_mandelbrot(t_data *img);
void	draw_img_mandelbrot(int x, int y, t_data *img);
int		nmb_iter_mandelbrot(t_data *img);
void	create_img_sponge(t_data *img);
void	draw_square_1(t_data *img, t_sponge *sp, int x);
void	draw_square_2(t_data *img, t_sponge *sp, int x);
void	create_img_bs(t_data *img);
void	draw_img_bs(int x, int y, t_data *img);
int		nmb_iter_bs(t_data *img);
int		color_gen(int i, int max, t_data *img);
int		color_gen_0(int i, int max);
int		color_gen_1(int i, int max);
int		color_gen_2(int i, int max);
int		color_gen_3(int i, int max);
void	color_all(t_data *img);
void	move_win(t_data *img, int keysym);
void	color_change(t_data *img, int keysym);
void	zoom_key(t_data *img, int keysym);
void	zoom_scroll(t_data *img, int keysym);
void	init_img(char set, t_data *img);
int		init_ptr(t_data *img);
void	init_hooks(t_data *img);

#endif
