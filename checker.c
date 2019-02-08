/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:22:21 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/07 16:18:45 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_hash(char *buf)
{
	int index;
	int cnt;

	index = 0;
	cnt = 0;
	while (index < 21)
	{
		if (buf[index] == '#')
		{
			if (buf[index + 1] == '#')
				cnt++;
			if (buf[index - 1] == '#')
				cnt++;
			if (buf[index + 5] == '#')
				cnt++;
			if (buf[index - 5] == '#')
				cnt++;
		}
		index++;
	}
	if (cnt == 6 || cnt == 8)
		return (1);
	return (-1);
}

int	check_symbols(char *buf)
{
	int i;

	i = 0;
	while (buf != '\0')
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (-1);
		i++;
	}
	return (1);
}

int	cnt_symbols(char *buf)
{
	int i;
	int cnt_hash;
	int cnt_dot;

	i = 0;
	cnt_hash = 0;
	cnt_dot = 0;
	if (buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n'
					&& buf[19] == '\n' && buf[20] == '\n')
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '#')
				cnt_hash++;
			else if (buf[i] == '.')
				cnt_dot++;
			i++;
		}
		if (cnt_hash == 4 && cnt_dot == 12)
			return (1);
	}
	return (-1);
}

int	checker(char *buf)
{
	if (cnt_symbols(buf) && check_symbols(buf) && check_hash(buf))
		return (1);
	return (-1);
}
