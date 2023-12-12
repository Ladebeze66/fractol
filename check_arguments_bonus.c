/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:43:42 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/09/08 17:06:52 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	message(void)
{
	ft_putstr_fd(RED "THE ARGUMENTS ARE WRONG!!!\n", 1);
	ft_putstr_fd(BLUE "\nFor execute the bonus version:", 1);
	ft_putstr_fd(ORANGE "\nPlease type : ./fractol mandelbrot", 1);
	ft_putstr_fd("\nOr : ./fractol julia x.xxx  x.xxx\n", 1);
	ft_putstr_fd(GREEN "\nWhere x represents digit", 1);
	ft_putstr_fd("\nExample: ./fractol julia -0.4  0.6\n", 1);
	ft_putstr_fd(ORANGE "\nBurning for display the bonus Burning Ship\n", 1);
	ft_putstr_fd(YELLOW "\nZOOM MOUSE WHELL(follow mouse)\n" DEF_COLOR, 1);
	ft_putstr_fd(YELLOW "\nYou can change color with 'A' 'S' 'D'\n", 1);
	ft_putstr_fd(YELLOW "\nMove the picture with keyboard arrows!!\n", 1);
	ft_putstr_fd(CYAN "\nESC FOR QUIT THE PROGRAM!!\n" DEF_COLOR, 1);
}

static int	check_number(char *nbr)
{
	int	index;
	int	point;

	point = 0;
	index = 0;
	if (nbr[index] == '+' || nbr[index] == '-')
		index ++;
	if (nbr[index] == '.' || !nbr[index])
		return (0);
	while (nbr[index])
	{
		if (ft_isdigit(nbr[index]) == 0)
		{
			if (nbr[index] != '.' || point > 0 || !nbr[index +1])
				return (0);
			point ++;
		}
		index ++;
	}
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp ("mandelbrot", argv[1], ft_strlen ("mandelbrot")) == 0)
			return (1);
		if (ft_strncmp ("burning", argv[1], ft_strlen ("burning")) == 0)
			return (1);
		message ();
		return (0);
	}
	if (argc == 4)
	{
		if (ft_strncmp("julia", argv[1], ft_strlen ("julia")) == 0)
		{
			if (check_number (argv[2]) != 0 && check_number (argv[3]) != 0)
				return (1);
		}
		message ();
		return (0);
	}
	message ();
	return (0);
}
