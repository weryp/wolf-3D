/*
** vecnorm.c for vecnorm in /home/wery_p/rendu/gfx_wolf3d/tcore
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Dec 21 14:14:20 2015 paul wery
** Last update Mon Dec 21 14:40:01 2015 paul wery
*/

#include <lapin.h>
#include <math.h>

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	norm;
  int		x;
  int		y;

  x = coord1->x - coord0->x;
  if (x < 0)
    x = x * -1;
  y = coord1->y - coord0->y;
  if (y < 0)
    y = y * -1;
  norm = (sqrt(((double)x * (double)x) + ((double)y * (double)y)));
  return (norm);
}
