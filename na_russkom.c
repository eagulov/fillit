#include "fillit.h"

static int		ft_is_legal(t_tetr *t, char **map, int x, int y, int storona)
{
	if (x + t->massiv[1].x < 0 || y + t->massiv[1].y < 0)
		return (1);
	if (x + t->massiv[2].x < 0 || y + t->massiv[2].y < 0)
		return (1);
	if (x +t->massiv[3].x < 0 || y + t->massiv[3].y < 0)
		return (1);
	if (x + t->massiv[1].x > (storona - 1) || y + t->massiv[1].y > (storona - 1))
		return (1);
	if (x + t->massiv[2].x > (storona - 1) || y + t->massiv[2].y > (storona - 1))
		return (1);
	if (x + t->massiv[3].x > (storona - 1) || y + t->massiv[3].y > (storona - 1))
		return (1);
	return (0);
}

static int		ft_is_empty(t_tetr *t, char **map, int x, int y)
{
	if (map[y][x] != '.')
		return (1);
	if (map[(y + t->massiv[1].y)][(x + t->massiv[1].x)] != '.')
		return (1);
	if (map[(y + t->massiv[2].y)][(x + t->massiv[2].x)] != '.')
		return (1);
	if (map[(y + t->massiv[3].y)][(x + t->massiv[3].x)] != '.')
		return (1);
	return (0);
}

int				ft_load_tetrimino(t_tetr *t, char **map, int x, int y, int storona)
{
	if (ft_is_legal(t, map, x, y, storona) == 1)
		return (0);
	else if (ft_is_empty(t, map, x, y) == 1)
		return (0);
	else
	{
		map[y][x] = t->letter;
		map[(y + t->massiv[1].y)][(x + t->massiv[1].x)] = t->letter;
		map[(y + t->massiv[2].y)][(x + t->massiv[2].x)] = t->letter;
		map[(y + t->massiv[3].y)][(x + t->massiv[3].x)] = t->letter;
	}
	return (1);
}

void			ft_remove_tetrimino(t_tetr *t, char **map, int x, int y)
{
	map[y][x] = '.';
	map[(y + t->massiv[1].y)][(x + t->massiv[1].x)] = '.';
	map[(y + t->massiv[2].y)][(x + t->massiv[2].x)] = '.';
	map[(y + t->massiv[3].y)][(x + t->massiv[3].x)] = '.';
}