/*
** loading_file.c for loading_file in /home/wery_p/rendu/gfx_fdf2
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Dec 10 18:29:11 2015 paul wery
** Last update Mon Dec 21 01:06:59 2015 paul wery
*/

#include <stdlib.h>
#include <unistd.h>
#include <lapin.h>
#include "struct_ini.h"
#include "my_functions.h"

void	clear_map(int *map, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      map[i] = '\0';
      i = i + 1;
    }
}

void		start_loading(t_ini *ini, t_ini *i)
{
  int		n;
  int		*map;
  const char	*object;

  object = bunny_ini_get_field(ini, "level1", "width", 0);
  i->width = get_nb(object);
  object = bunny_ini_get_field(ini, "level1", "height", 0);
  i->height = get_nb(object);
  map = bunny_malloc((i->width * i->height) * 4);
  clear_map(map, i->width * i->height);
  n = 0;
  while ((object = bunny_ini_get_field(ini, "level1", "data", n)) != NULL)
    {
      map[n] = get_nb(object);
      n = n + 1;
    }
  first_part(map, i);
  bunny_free(map);
}
