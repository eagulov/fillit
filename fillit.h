/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:56:15 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/07 14:07:40 by eagulov          ###   ########.fr       */
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
	int 			x;
	int 			y;
}  						t_coord;

typedef struct		s_map
{
	char			**array;
	int				xmax;
	int				ymax;
}						t_map;

typedef struct		s_tetr
{
	char			letter;
	t_coord			*massiv;
	struct s_tetr 	*next;
}						t_tetr;

void		opener(char *source, char *buf, t_tetr *list, char **map);
int			checker(char *buf);
int			check_cnt_symb(char *buf);
int			check_symbols(char *buf);
int			check_hash(char *buf);
t_tetr		*add_list(t_tetr *list, char *buf, char c);
void		cut_tetrimino(t_tetr *list, char *buf);
void		fill_it(t_tetr *tetr,int cnt);
int			ft_sqrt(int num);
char		**create_map(int size);
static int	solve(t_tetr *tetr, char **map, int storona);
int			ft_load_tetrimino(t_tetr *t, char **map, int x, int y, int storona);
static int	ft_is_legal(t_tetr *t, char **map, int x, int y, int storona);
static int	ft_is_empty(t_tetr *t, char **map, int x, int y);
void		ft_remove_tetrimino(t_tetr *t, char **map, int x, int y);
void	free_map(char **map, int sz);
# endif