/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:45:20 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/02 15:35:23 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	opener(char *source, char *buf)
{
	int		fd;
	int		rest;
	t_tetr	*list;
	t_tetr	*tmp;

	fd = open(source, O_RDONLY);
	list = NULL;
	while ((rest = read(fd, buf, 21)) > 0)
	{
		buf[22] = '\0';
		if (checker(buf) == 1)
			list = add_list(list, buf);
 	}
	list = cut_square(list);
	tmp = list;
	// while (tmp)
	// {
	// 	printf("%s", tmp->data);
	// 	printf("\n");
	// 	tmp = tmp->next;
	// }
	close(fd);
	//return (str);
 }

int			main(int argc, char **argv)
{
	char	buf[22];
	opener(argv[1], buf);
	return (argc);
}
