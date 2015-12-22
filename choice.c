/*
** choice.c for choice in /home/wery_p/rendu/gfx_wolf3d
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Dec 21 15:00:48 2015 paul wery
** Last update Wed Dec 23 00:40:23 2015 paul wery
*/

#include <lapin.h>
#include "struct_ini.h"
#include "struct_coord.h"

int	cal_y(t_co *co, t_ini *i)
{
  int	y;

  if (i->vy >= 0)
    {
      co[i->x].y += 0.000001;
      y = co[i->x].y;
      co[i->x].y -= 0.000001;
    }
  if (i->vy < 0)
    {
      co[i->x].y -= 0.000001;
      y = co[i->x].y;
      co[i->x].y += 0.000001;
    }
  return (y);
}

int	cal_x(t_co *co, t_ini *i)
{
  int	x;

  if (i->vx >= 0)
    {
      co[i->x].x += 0.000001;
      x = co[i->x].x;
      co[i->x].x -= 0.000001;
    }
  if (i->vx < 0)
    {
      co[i->x].x -= 0.000001;
      x = co[i->x].x;
      co[i->x].x += 0.000001;
    }
  return (x);
}

float	cal_k2(t_co *co, float vy, t_ini *i)
{
  float	k2;

  k2 = 1;
  if (vy != 0 && vy > 0)
    {
      k2 = (float)((int)(co[i->x].y + P) - co[i->x].y);
      k2 = k2 / vy;
      if (k2 < 0)
        k2 = k2 * (float)(-1);
    }
  if (vy != 0 && vy < 0)
    {
      k2 = (float)((int)co[i->x].y - co[i->x].y);
      if (k2 == 0)
	k2 = 1;
      k2 = k2 / vy;
      if (k2 < 0)
        k2 = k2 * (float)(-1);
    }
  return (k2);
}

float	cal_k1(t_co *co, float vx, t_ini *i)
{
  float	k1;

  k1 = 1;
  if (vx != 0 && vx > 0)
    {
      k1 = (float)((int)(co[i->x].x + P) - co[i->x].x);
      k1 = k1 / vx;
      if (k1 < 0)
        k1 = k1 * -1;
    }
  if (vx != 0 && vx < 0)
    {
      k1 = (float)((int)co[i->x].x - co[i->x].x);
      if (k1 == 0)
	k1 = 1;
      k1 = k1 / vx;
      if (k1 < 0)
        k1 = k1 * -1;
    }
  return (k1);
}

float	cal_k(t_co *co, t_ini *i, float vx, float vy)
{
  float	k;

  if (vx != 0)
    k = (co[i->x].x - i->save1) / vx;
  else
    k = (co[i->x].y - i->save2) / vy;
  if (k < 0)
    k = k * -1;
  return (k);
}
