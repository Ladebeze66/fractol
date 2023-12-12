/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:26:52 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/09/08 15:28:23 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
