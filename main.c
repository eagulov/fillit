/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:45:20 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/09 15:09:40 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_tetr *list)
{
	t_tetr *tmp;

	while (list)
	{
		tmp = list->next;
		free((void *)list->coords);
		free(list);
		list = tmp;
	}
}

void	check_and_write(int rest, char *buf, t_tetr **list, char c)
{
	if (rest == 20)
		buf[20] = '\n';
	buf[21] = '\0';/* be sure that the last symbol is '\0' in buf */
	if (checker(buf) == 1)/* check validity of tetriminos */
		*list = add_lists(*list, buf, c);/*              */
	else
		exit(write(1, "error\n", 6) ? 0 : 0);
}

void	all_process(int fd, char *buf, t_tetr *list)
{
	int		rest;
	int		old_rest;
	int		cnt;
	char	c;

	old_rest = 0;
	c = 'A';/* letter for each tetrimin, start from 'A' */
	cnt = 0;/* counter (how many tetriminos) */
	while ((rest = read(fd, buf, 21)))/* read file, return number of read */
	{
		check_and_write(rest, buf, &list, c);
		cnt++;
		c++;
		old_rest = rest;
	}
	close(fd);
	if (rest != 0 || old_rest != 20)
		exit(write(1, "error\n", 6) ? 0 : 0);
	fill_it(list, cnt);/* send tetriminos on lists */
	free_list(list);
}

int		main(int argc, char **argv)
{
	char	buf[22];
	int		fd;
	t_tetr	*list;/* create list, write all tetriminos on it from buf */

	list = NULL;
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		exit(write(1, "error\n", 6) ? 0 : 0);
	all_process(fd, buf, list);
	return (argc);
}
