/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:39:22 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/06 14:55:25 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_array(char **array)
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

char	**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)ft_memalloc(sizeof(char *) * size + 1);
	i = 0;
	while (i < size)
	{
		map[i] = ft_strnew(size + 1);
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(char **map, int sz)
{
	int i;
	
	i = 0;
	while (i < sz)
	{
		ft_memdel((void **)&(map[i]));
		i++;
	}
	ft_memdel((void **)&(map));
	ft_memdel((void **)&map);
}

int        ft_sqrt(int num)
{
    int    tmp;
    int    x;

    tmp = 0;
    x = 1;
    if (num < 0)
        num = -num;
    while (tmp != x)
    {
        tmp = num / x;
        if (tmp == x)
            return (x);
        x++;
    }
    return (x);
}



static int		solve(t_tetr *tetr, char **map, int storona)
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
			if (ft_load_tetrimino(tetr, map, x, y, storona))
			{
				if (solve(tetr->next, map, storona))
					return (1);
				else
					ft_remove_tetrimino(tetr, map, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

void	fill_it(t_tetr *tetr,int cnt)
{
	char	**map;
	int		x;
	t_tetr *tmp;

	tmp = tetr;
	x = ft_sqrt(cnt * 4);
	map = create_map(x);
	while (!solve(tetr, map, x))
	{
		free_map(map, x);
		++x;
		map = create_map(x);
	}
	ft_print_array(map);
} 