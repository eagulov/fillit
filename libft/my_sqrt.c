/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:34:30 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/07 16:44:51 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		my_sqrt(int num)
{
	int	tmp;
	int	x;

	tmp = 1;
	x = 1;
	if (num < 0)
		num = -num;
	if (num == 1)
		return (1);
	while (tmp >= x)
	{
		tmp = num / x;
		if (tmp == x)
			return (x);
		x++;
	}
	return (x);
}
