#include "fillit.h"

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

void    get_coords(t_coord *first_hash, t_coord *massiv, int *j, int i)
{
    if (first_hash->x == 6 && first_hash->y == 6)//заходит сюда только первый раз, остальные разы идет в else
    {
        first_hash->x = i % 5;//перезаписывает координату найденного # по х
        first_hash->y = i / 5;//перезаписывает координату найденного # по у
        massiv[*j].x = 0;//устанавливает новую позицию по х для нашего первого #(новая карта с #) ; x(#-№1): 0 y(#-№1): 0
        massiv[*j].y = 0;//.х мы используем только тогда когда мы работаем с адресом(смт. подсказку№1)
    }
    else
    {
        massiv[*j].x = (i % 5) - first_hash->x;//алгоритм для установления новых координат нашим # в massiv[j]
        massiv[*j].y = (i / 5) - first_hash->y;
    }
    (*j)++;
}


void    cut_tetrimino(t_tetr *list, char *buf)
{
    int        i;//переменная для итерации по нашей карте(тетрамино)
    int        j;// -|- по нашему massiv в котором будут находиться наши #
    t_coord    *first_hash;//локальная структура
    t_coord *massiv;// структура куда будут записаны наши найденные #(маленькая карта)

    i = 0;
    j = 0;
    first_hash = (t_coord *)malloc(sizeof(t_coord));
    massiv = (t_coord *)malloc(sizeof(t_coord)* 4);//выделяем память только под наши 4 #, которые найдем
    first_hash->x = 6;
    first_hash->y = 6;
    while (buf[i])//поэлементная итерация нашего листа(list->data, потому что мы записываем наши листы в фу-ии add_list)
    {
	    if (buf[i] == '#')
            get_coords(first_hash, massiv, &j, i);
		++i;
	}
	list->massiv = massiv;
}
