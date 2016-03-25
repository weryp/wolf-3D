/*
** ini_val.c for ini_val in /home/wery_p/rendu/gfx_wolf3d
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Dec 25 16:35:36 2015 paul wery
** Last update Fri Dec 25 16:59:28 2015 paul wery
*/

#include "struct_ini.h"
#include "struct_coord.h"

void	ini_val(t_co *co, t_ini *i)
{
  i->vx = co[i->x].x - i->start_pos_x;
  i->vy = co[i->x].y - i->start_pos_y;
  i->save1 = co[i->x].x;
  i->save2 = co[i->x].y;
}
