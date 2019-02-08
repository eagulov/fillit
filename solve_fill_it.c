/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:39:22 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/07 17:05:55 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		++i;
	}
}

char		**create_map(int storona)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)ft_memalloc(sizeof(char *) * storona + 1);
	i = 0;
	while (i < storona)
	{
		map[i] = ft_strnew(storona + 1);
		j = 0;
		while (j < storona)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void		free_map(char **map, int storona)
{
	int i;

	i = 0;
	while (i < storona)
	{
		ft_memdel((void **)&(map[i]));
		i++;
	}
	ft_memdel((void **)&(map));
	ft_memdel((void **)&map);
}

static int	solve(t_tetr *tetr, char **map, int storona)
{
	int x;
	int y;

	if (tetr == NULL)
		return (1);
	y = 0;
	while (y < storona)
	{
		x = 0;
		while (x < storona)
		{
			if (load_tetrimino(tetr, map, x, y, storona))
			{
				if (solve(tetr->next, map, storona))
					return (1);
				else
					remove_tetrimino(tetr, map, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

void		fill_it(t_tetr *tetr, int cnt)
{
	char	**map;
	int		storona;
	t_tetr	*tmp;

	tmp = tetr;
	storona = my_sqrt(cnt * 4);
	map = create_map(storona);
	while (!solve(tetr, map, storona))
	{
		free_map(map, storona);
		++storona;
		map = create_map(storona);
	}
	print_array(map);
	free_map(map, storona);
}
