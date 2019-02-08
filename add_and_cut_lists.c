/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:00 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/07 16:01:17 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_coords(t_coord *first_hash, t_coord *massiv, int *j, int i)
{
	if (first_hash->x == 6 && first_hash->y == 6)
	{
		first_hash->x = i % 5;
		first_hash->y = i / 5;
		massiv[*j].x = 0;
		massiv[*j].y = 0;
	}
	else
	{
		massiv[*j].x = (i % 5) - first_hash->x;
		massiv[*j].y = (i / 5) - first_hash->y;
	}
	(*j)++;
}

void	cut_tetrimino(t_tetr *list, char *buf)
{
	int		i;
	int		j;
	t_coord	*first_hash;
	t_coord	*massiv;

	i = 0;
	j = 0;
	first_hash = (t_coord *)malloc(sizeof(t_coord));
	massiv = (t_coord *)malloc(sizeof(t_coord) * 4);
	first_hash->x = 6;
	first_hash->y = 6;
	while (buf[i])
	{
		if (buf[i] == '#')
			get_coords(first_hash, massiv, &j, i);
		++i;
	}
	list->massiv = massiv;
	free(first_hash);
}

t_tetr	*add_list(t_tetr *list, char *buf, char c)
{
	t_tetr	*new;
	t_tetr	*tmp;

	if (list == NULL)
	{
		new = (t_tetr *)malloc(sizeof(t_tetr));
		cut_tetrimino(new, buf);
		new->next = NULL;
		new->letter = c;
		return (new);
	}
	tmp = list;
	new = (t_tetr *)malloc(sizeof(t_tetr));
	cut_tetrimino(new, buf);
	new->next = NULL;
	while (list->next)
		list = list->next;
	new->letter = c;
	list->next = new;
	return (tmp);
}
