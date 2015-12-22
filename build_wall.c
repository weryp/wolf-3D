/*
** build_wall.c for build_wall in /home/wery_p/rendu/gfx_wolf3d
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Dec 20 20:04:44 2015 paul wery
** Last update Wed Dec 23 00:31:23 2015 paul wery
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
      color->full = 0xFF003366;
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

void			build_wall(t_ini *i, float k)
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
  color.full = 0xFF666666;
  while (pos_start <= pos_end)
    {
      pos.x = i->x;
      pos.y = pos_start;
      tekpixel(i->pix, &pos, &color);
      pos_start += 1;
    }
}
