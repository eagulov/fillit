/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:45:20 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/06 17:11:58 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	opener(char *source, char *buf, t_tetr *list, char **map)
{
	int		fd;
	int		rest;
	t_tetr	*tmp;
	int		cnt;
	char c;

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
	close(fd);
 }



int			main(int argc, char **argv)
{
	char	buf[22];
	char	**map;
	t_tetr	*list;
	opener(argv[1], buf, list, map);

	return (argc);
}

	// tmp = list;
	// while(tmp)
	// {
	// 	printf("letter: %c, [0]: x: %d y: %d, [1]: x: %d y: %d, [2]: x: %d y: %d, [3]: x: %d y: %d",tmp->letter, tmp->massiv[0].x, tmp->massiv[0].y, tmp->massiv[1].x, tmp->massiv[1].y, tmp->massiv[2].x, tmp->massiv[2].y, tmp->massiv[3].x, tmp->massiv[3].y);
	// 	printf("\n");
	// 	tmp = tmp->next;
	// }
