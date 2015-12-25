/*
** build_wall.c for build_wall in /home/wery_p/rendu/gfx_wolf3d
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Dec 20 20:04:44 2015 paul wery
** Last update Fri Dec 25 15:38:00 2015 paul wery
*/

#include <lapin.h>
#include "struct_ini.h"
#include "my_functions.h"

void		aff_earth(t_ini *i)
{
  t_color	*color;
  unsigned long	ad;
  int		n;

  n = SIZE_WINL * SIZE_WINH;
  while (n >= (SIZE_WINL * (SIZE_WINH / 2)))
    {
      ad = (unsigned long)i->pix->pixels;
      color = (t_color*)ad;
      color = color + n;
      color->full = 0xFF000000;
      n = n - 1;
    }
}

void		aff_sky(t_ini *i)
{
  t_color	*color;
  unsigned long	ad;
  int		n;

  n = SIZE_WINL * (SIZE_WINH / 2);
  while (n >= 0)
    {
      ad = (unsigned long)i->pix->pixels;
      color = (t_color*)ad;
      color = color + n;
      color->full = 0xFF990000;
      n = n - 1;
    }
}

void	wall_color2(t_co *co, t_ini *i, t_color *color)
{
  int	check;
  int	n;

  check = 0;
  n = 0;
  if (co[i->x].x != (int)co[i->x].x)
    {
      while (n < co[i->x].y)
	{
	  check += 1;
	  if (check > 1)
	    check = 0;
	  n = n + 1;
	}
      if (check == 0)
	color->full = 0xFF666666;
      if (check == 1)
	color->full = 0xFF444444;
    }
}

void	wall_color(t_co *co, t_ini *i, t_color *color)
{
  int  	check;
  int	n;

  check = 0;
  n = 0;
  while (n < co[i->x].x)
    {
      check += 1;
      if (check > 1)
	check = 0;
      n = n + 1;
    }
  if (check == 0)
    color->full = 0xFF666666;
  if (check == 1)
    color->full = 0xFF444444;
  wall_color2(co, i, color);
}

void			build_wall(t_ini *i, float k, t_co *co)
{
  t_bunny_position	pos;
  t_color		color;
  int			height;
  int			pos_start;
  int			pos_end;

  height = (int)((float)SIZE_WINH / ((float)2 * k));
  height = height * 2;
  pos_start = (SIZE_WINH - height) / 2;
  pos_end = pos_start + height;
  wall_color(co, i, &color);
  while (pos_start <= pos_end)
    {
      pos.x = i->x;
      pos.y = pos_start;
      tekpixel(i->pix, &pos, &color);
      pos_start += 1;
    }
}
