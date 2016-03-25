/*
** tekpixel.c for tekpixel in /home/wery_p/rendu/iconofsin_2020
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Nov 16 14:27:51 2015 paul wery
** Last update Thu Jan  7 23:07:30 2016 paul wery
*/

#include <lapin.h>
#include "struct_ini.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  t_color	*pixel;
  unsigned long	ad;
  int		i;

  if (pos->x >= 0 && pos->x < SIZE_WINL)
    if (pos->y >= 0 && pos->y < SIZE_WINH)
      {
	i = pos->x + (pos->y * pix->clipable.clip_width);
	ad = (unsigned long)pix->pixels;
	pixel = (t_color*)ad;
	pixel = pixel + i;
	pixel->full = color->full;
      }
}
