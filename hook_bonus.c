/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:29:12 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/09/08 15:39:58 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	direction(int keycode, t_fractol *fractol)
{
	float	dx;
	float	dy;

	if (keycode == 65361 || keycode == 65363)
	{
		dx = (fractol->x_max - fractol->x_min);
		if (keycode == 65361)
			dx *= -1;
		fractol->x_min += dx / 3.0;
		fractol->x_max += dx / 3.0;
	}
	if (keycode == 65362 || keycode == 65364)
	{
		dy = (fractol->y_max - fractol->y_min);
		if (keycode == 65364)
			dy *= -1;
		fractol->y_min += dy / 3.0;
		fractol->y_max += dy / 3.0;
	}
}

int	close_program(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free (fractol->mlx);
	free(fractol->name);
	free(fractol);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
		close_program(fractol);
	direction (keycode, fractol);
	change_color(keycode, fractol);
	choose(fractol);
	return (0);
}

int	zoom(int keycode, int x, int y, t_fractol *fractol)
{
	float	dx;
	float	dy;

	dx = (fractol->x_max - fractol->x_min) / 3;
	dy = (fractol->y_max - fractol->y_min) / 3;
	if (keycode == 4)
	{
		fractol->x_min = (fractol->x_min + dx);
		fractol->x_max = (fractol->x_max - dx);
		fractol->y_min = (fractol->y_min + dy);
		fractol->y_max = (fractol->y_max - dy);
	}
	if (keycode == 5)
	{
		fractol->x_min = (fractol->x_min - dx);
		fractol->x_max = (fractol->x_max + dx);
		fractol->y_min = (fractol->y_min - dy);
		fractol->y_max = (fractol->y_max + dy);
	}
	dx = x;
	dy = y;
	choose(fractol);
	return (0);
}

int	zoom_mouse(int keycode, int x, int y, t_fractol *fractol)
{
	double	mousex;
	double	mousey;

	mousex = fractol->x_min + (x * ((fractol->x_max - fractol->x_min) / IMG_X));
	mousey = fractol->y_max - (y * ((fractol->y_max - fractol->y_min) / IMG_Y));
	if (keycode == 4)
	{
		fractol->x_min = mousex - (mousex - fractol->x_min) * (2.0 / 3.0);
		fractol->x_max = mousex + (fractol->x_max - mousex) * (2.0 / 3.0);
		fractol->y_min = mousey - (mousey - fractol->y_min) * (2.0 / 3.0);
		fractol->y_max = mousey + (fractol->y_max - mousey) * (2.0 / 3.0);
	}
	else if (keycode == 5)
	{
		fractol->x_min = mousex - (mousex - fractol->x_min) * 1.5;
		fractol->x_max = mousex + (fractol->x_max - mousex) * 1.5;
		fractol->y_min = mousey - (mousey - fractol->y_min) * 1.5;
		fractol->y_max = mousey + (fractol->y_max - mousey) * 1.5;
	}
	choose(fractol);
	return (0);
}
