/*
** first_part.c for first_part in /home/wery_p/rendu/gfx_wolf3d
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Dec 19 18:18:35 2015 paul wery
** Last update Wed Dec 23 00:56:48 2015 paul wery
*/

#include <lapin.h>
#include <math.h>
#include "struct_ini.h"
#include "struct_coord.h"
#include "my_functions.h"

float 	best_choice(t_co *co,
		    float vx, float vy, t_ini *i)
{
  float	k1;
  float	k2;
  float	a;
  int	check;

  check = 0;
  if (vx == 0)
    check = 1;
  if (vy == 0)
    check = 2;
  k1 = cal_k1(co, vx, i);
  k2 = cal_k2(co, vy, i);
  a = (k1 <= k2 ? k1 : k2);
  if (check == 1)
    a = k2;
  if (check == 2)
    a = k1;
  return (a);
}

int	check_end(int *map, t_co *co, t_ini *i)
{

  int	x;
  int	y;
  int	nb;

  x = cal_x(co, i);
  y = cal_y(co, i);
  nb = x + (i->height - (y + 1)) * i->width;
  if (map[nb] == 1)
    return (1);
  else
    return (0);
}

void	find_wall(int *map, t_co *co, t_ini *i)
{
  float	k;

  i->x = 0;
  while (i->x <= SIZE_WINL)
    {
      i->vx = co[i->x].x - i->start_pos_x;
      i->vy = co[i->x].y - i->start_pos_y;
      i->save1 = co[i->x].x;
      i->save2 = co[i->x].y;
      while (check_end(map, co, i) == 0)
      	{
	  k = best_choice(co, i->vx, i->vy, i);
	  co[i->x].x = co[i->x].x + (k * i->vx);
	  co[i->x].y = co[i->x].y + (k * i->vy);
	}
      k = cal_k(co, i, i->vx, i->vy);
      if (k == 0)
	k = 1;
      build_wall(i, k);
      i->x += 1;
    }
}

void		get_pos(t_co *co, t_ini *i)
{
  int		x;
  float		temp;
  double	a;

  x = 0;
  a = i->start_angle * (M_PI / 180);
  while (x <= SIZE_WINL)
    {
      co[x].x = (float)D;
      co[x].y = ((float)P * (float)((SIZE_WINL / 2) - x)) / (float)SIZE_WINL;
      temp = co[x].x;
      co[x].x = co[x].x * cos(-a) - co[x].y * sin(-a);
      co[x].y = temp * sin(-a) + co[x].y * cos(-a);
      co[x].x = co[x].x + i->start_pos_x;
      co[x].y = co[x].y + i->start_pos_y;
      x = x + 1;
    }
}

void	first_part(int *map, t_ini *i)
{
  t_co	*co;

  co = bunny_malloc(sizeof(t_co *) * (SIZE_WINL + 1));
  get_pos(co, i);
  find_wall(map, co, i);
  bunny_free(co);
}
