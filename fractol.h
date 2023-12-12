/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:46:34 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/09/08 15:10:15 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITER 100
# define MIN_X -2
# define MAX_X 2
# define MIN_Y -2
# define MAX_Y 2
# define IMG_X 1240
# define IMG_Y 1240

# define DEF_COLOR "\033[0m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"
# define ORANGE "\033[38;5;214m"

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	char	*name;
	int		color;
	int		img_bits_per_pixel;
	int		img_line_length;
	int		img_endian;
	double	x;
	double	y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	julia_x;
	double	julia_y;
}	t_fractol;

int		zoom(int keycode, int x, int y, t_fractol *s_fractol);
int		key_hook(int keycode, t_fractol *fractol);
int		check_arguments(int argc, char **argv);
int		close_program(t_fractol *fractol);
int		color(int i, t_fractol *fractol);
double	atf( char *str);
void	my_img_pixel_put(t_fractol *fractol, int x, int y, int color);
void	mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol);
void	choose(t_fractol *fractol);

#endif
