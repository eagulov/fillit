/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_cut_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:00 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/09 12:18:00 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_coords(t_coord *first_hash, t_coord *coords, int *j, int index)/* get coordinates */
{
	if (first_hash->x == 6 && first_hash->y == 6)/* entrance for first '#' */
	{
		first_hash->x = index % 5;/* example: 12 % 5 = .2	 x[2] */
		first_hash->y = index / 5;/* example: 12 / 5 = 2.   y[2] */
		coords[*j].x = 0;/* first '#' = x[0] always */
		coords[*j].y = 0;/* first '#' = y[0] always */
	}
	else/* after first '#' */
	{
		coords[*j].x = (index % 5) - first_hash->x;/* coords of another '#' - coords of first '#' */
		coords[*j].y = (index / 5) - first_hash->y;/* regarding the coords of first '#' */
	}
	(*j)++;
}

void	get_tetrimino(t_tetr *new, char *buf)
{
	int		index;/* posicion */
	int		j;/* number of coordinates (0, 1, 2, or 3) */
	t_coord	*first_hash;/* x/y coordinates of first '#' */
	t_coord	*coords;/* to write 4 coordinates */

	index = 0;/* index of symbols */
	j = 0;/* number of coordinates of '#' (0, 1, 2 or 3) */
	first_hash = (t_coord *)malloc(sizeof(t_coord));/* memory for first '#' (x/y coordinates) */
	coords = (t_coord *)malloc(sizeof(t_coord) * 4);/* memory for 4-'#' (4 x/y coordinates) */
	first_hash->x = 6;/* for first loop */
	first_hash->y = 6;/* to enter in first loop */
	while (buf[index])/* loop, looking for '#' */
	{
		if (buf[index] == '#')
			get_coords(first_hash, coords, &j, index);/* get coordinates */
		++index;/* next index */
	}
	new->coords = coords;/* write coords all coords of tetriminos */
	free(first_hash);
}

t_tetr	*add_lists(t_tetr *list, char *buf, char c)
{
	t_tetr	*new;/* working with this structure and rewrite on list->next */
	t_tetr	*tmp;/* storing a pointer on the first structure */

	if (list == NULL)
	{
		new = (t_tetr *)malloc(sizeof(t_tetr));
		get_tetrimino(new, buf);/* find and rewrite coordinates from buf to new (coords of first '#' are x[0]y[0]) */
		new->next = NULL;/*    */
		new->letter = c;
		return (new);
	}
	tmp = list;
	new = (t_tetr *)malloc(sizeof(t_tetr));
	get_tetrimino(new, buf);
	new->next = NULL;
	while (list->next)
		list = list->next;
	new->letter = c;
	list->next = new;
	return (tmp);
}
