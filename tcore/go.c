/*
** go.c for go in /home/wery_p/rendu/gfx_wolf3d/tcore
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Dec 21 14:42:33 2015 paul wery
** Last update Mon Dec 21 14:54:30 2015 paul wery
*/

#include <lapin.h>
#include <math.h>

void	go(t_bunny_position *curpos,
	   double angle,
	   t_bunny_position *newpos,
	   int move)
{
  newpos->x = curpos->x + (move * cos(angle));
  newpos->y = curpos->y + (move * sin(angle));
}
