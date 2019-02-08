/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:56:15 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/07 17:06:26 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_map
{
	char			**array;
	int				xmax;
	int				ymax;
}					t_map;

typedef struct		s_tetr
{
	char			letter;
	t_coord			*massiv;
	struct s_tetr	*next;
}					t_tetr;

void				all_process(char *source, char *buf, t_tetr *list,
																char **map);
int					checker(char *buf);
int					cnt_symbols(char *buf);
int					check_symbols(char *buf);
int					check_hash(char *buf);
t_tetr				*add_list(t_tetr *list, char *buf, char c);
void				cut_tetrimino(t_tetr *list, char *buf);
void				fill_it(t_tetr *tetr, int cnt);
char				**create_map(int size);
static int			solve(t_tetr *tetr, char **map, int storona);
int					load_tetrimino(t_tetr *t, char **map, int x, int y,
																int storona);
static int			is_legal(t_tetr *t, char **map, int x, int y, int storona);
static int			is_empty(t_tetr *t, char **map, int x, int y);
void				remove_tetrimino(t_tetr *t, char **map, int x, int y);
void				print_array(char **array);
void				free_map(char **map, int sz);

#endif
