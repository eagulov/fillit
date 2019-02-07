/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:56:15 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/06 15:00:15 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"
# define BUF_SIZE 21

typedef struct 		s_coord
{
	int x;
	int y;
}  					t_coord;

typedef struct	s_map {
	char		**array;
	int			xmax;
	int			ymax;
}				t_map;


typedef struct 	s_tetr
{
	char 	*data;
	char 	letter;
	t_coord *massiv;
	// t_coord	min;
	// t_coord max;
	struct s_tetr *next;
}	t_tetr;

void			ft_remove_tetrimino(t_tetr *t, char **map, int x, int y);
int				ft_load_tetrimino(t_tetr *t, char **map, int x, int y, int storona);
void	fill_it(t_tetr *tetr,int cnt);
int 	checker(char *buf);
int		check_cnt_symb(char *buf);
int		check_symbols(char *buf);
void	cut_tetrimino(t_tetr *list);
void	opener(char *source, char *buf);
t_tetr	*add_list(t_tetr *list, char *buf, char c);
// t_tetr	*cut_square(t_tetr *list);

# endif
