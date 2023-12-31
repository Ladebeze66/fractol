/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:37:30 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/02/20 16:07:19 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
}
