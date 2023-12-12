/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:25:43 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/09/08 15:26:05 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_img_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*byte;

	byte = fractol->img_addr + ((y * fractol->img_line_length) \
		+ (x * fractol->img_bits_per_pixel / 8));
	*(unsigned int *)byte = color;
}

double	atf(char *str)
{
	double	atf;
	int		base;
	int		i;

	base = 1;
	i = 1;
	while (i < (int)ft_strlen(ft_strchr(str, '.')))
	{
		base *= 10;
		i ++;
	}
	atf = (float)ft_atoi(str);
	if (!ft_strchr(str, '.'))
		return (atf);
	if (str[0] != '-')
		atf += (float)ft_atoi(ft_strchr(str, '.') + 1) / base;
	else
		atf -= (float)ft_atoi(ft_strchr(str, '.') + 1) / base;
	return (atf);
}
