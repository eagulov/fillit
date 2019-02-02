/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:19:35 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/02 15:20:10 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*cut_square(t_tetr *list)
{
	int index;
	t_tetr *tmp;

	tmp = list;
	while (list->next)
	{
		list->min.x = 6;
		list->min.y = 6;
		list->max.x = -1;
		list->max.y = -1;
		index = 0;
		while (list->data[index])
		{
			if (list->data[index] == '#')
			{
				if (list->min.x > index%5)
					list->min.x = index%5;
				if (list->max.x < index%5)
					list->max.x = index%5;
				if (list->min.y > index/5)
					list->min.y = index/5;
				if (list->max.y < index/5)
					list->max.y = index/5;
			}
			index++;
		}
		list = list->next;
	}
	list = tmp;
	return (list);
}

t_tetr	*add_list(t_tetr *list, char *buf)
{
	t_tetr	*new;
	t_tetr	*tmp;

	if (list == NULL)
	{
		new = (t_tetr *)malloc(sizeof(t_tetr));
		new->data = ft_strdup(buf);
		new->next = NULL;
		new->letter = 'A';
		return (new);
	}
	tmp = list;
	new = (t_tetr *)malloc(sizeof(t_tetr));
	new->data = ft_strdup(buf);
	new->next = NULL;
	while (list->next)
		list = list->next;
	new->letter = list->letter + 1;
	list->next = new;
	return (tmp);
}

