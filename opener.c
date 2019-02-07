/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:45:20 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/07 14:12:46 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void free_list(t_tetr *list)
{
	t_tetr *tmp;

	while(list)
	{
		tmp = list->next;
		free((void *)list->massiv);
		free(list);
		list = tmp;
	}
}

void	opener(char *source, char *buf, t_tetr *list, char **map)
{
	int		fd;
	int		rest;
	t_tetr	*tmp;
	int		cnt;
	char 	c;

	c = 'A';
	cnt = 0;
	fd = open(source, O_RDONLY);
	list = NULL;
	while ((rest = read(fd, buf, 21)) > 0)
	{
		buf[22] = '\0';
		if (checker(buf) == 1)
			list = add_list(list, buf, c);
		cnt++;
		c++;
 	}
	fill_it(list, cnt);
	free_list(list);
	close(fd);
 }

int			main(int argc, char **argv)
{
	char	buf[22];
	char	**map;
	t_tetr	*list;
	opener(argv[1], buf, list, map);
	// while (1)
	// {
		
	// }
	return (argc);
}
