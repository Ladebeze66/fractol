/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:48:10 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/09/08 15:48:36 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	color(int i, t_fractol *fractol)
{
	if (fractol->color == 1)
		return (i * 0x00ABCDEF);
	if (fractol->color == 2)
		return (i * 0x00FEDCBA);
	if (fractol->color == 3)
		return (i * 0x00ABCABC);
	return (0);
}

void	change_color(int keycode, t_fractol *fractol)
{
	if (keycode == 97)
		fractol->color = 1;
	else if (keycode == 115)
		fractol->color = 2;
	else if (keycode == 100)
		fractol->color = 3;
	choose(fractol);
}
