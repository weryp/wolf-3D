/*
** win_initialize.c for win_initialize in /home/wery_p/rendu/Bazar/wind/my_fonctions_liblapin
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Nov  4 01:08:26 2015 paul wery
** Last update Thu Jan  7 23:12:11 2016 paul wery
*/

#include <lapin.h>

void		win_initialize(t_bunny_pixelarray *pix)
{
  t_color	*color;
  unsigned long	ad;
  int		i;

  i = pix->clipable.clip_width * pix->clipable.clip_height;
  while (i >= 0)
    {
      ad = (unsigned long)pix->pixels;
      color = (t_color*)ad;
      color = color + i;
      color->full = 0xFF000000;
      i = i - 1;
    }
}
