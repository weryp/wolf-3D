/*
** my_functions.h for my_functions.h in /home/wery_p/rendu/gfx_wolf3d
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Dec 19 17:44:28 2015 paul wery
** Last update Wed Dec 23 00:40:09 2015 paul wery
*/

#include <lapin.h>
#include "struct_ini.h"
#include "struct_coord.h"

#ifndef MY_FONC
#define MY_FONC

void            aff_sky(t_ini *i);
void            aff_earth(t_ini *i);
void            win_initialize(t_bunny_pixelarray *pix);
void            start_loading(t_ini *ini, t_ini *i);
int		get_nb(const char *buffer);
void            first_part(int *map, t_ini *i);
void		build_wall(t_ini *i, float add);
void            tekpixel(t_bunny_pixelarray *pix,
                         t_bunny_position *pos,
                         t_color *color);
float		cal_k1(t_co *co, float vx, t_ini *i);
float		cal_k2(t_co *co, float vy, t_ini *i);
float		cal_k(t_co *co, t_ini *i, float vx, float vy);
int		cal_x(t_co *co, t_ini *i);
int		cal_y(t_co *co, t_ini *i);
#endif /* MY_FONC */
