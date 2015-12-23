/*
** main.c for main in /home/wery_p/rendu/Bazar/wind/my_fonctions_liblapin/test_sphere
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Dec 12 03:12:30 2015 paul wery
** Last update Wed Dec 23 14:01:08 2015 paul wery
*/

#include <unistd.h>
#include <lapin.h>
#include <math.h>
#include "struct_ini.h"
#include "my_functions.h"

void	change_pos(t_ini *i, t_bunny_event_state state, t_bunny_keysym key)
{
  float	a;

  a = M_PI * i->start_angle / 180;
  if (state == GO_DOWN && key == BKS_UP)
    {
      i->start_pos_x += 0.10 * cos(-a);
      i->start_pos_y += 0.10 * sin(-a);
    }
  if (state == GO_DOWN && key == BKS_DOWN)
    {
      i->start_pos_x += -0.10 * cos(-a);
      i->start_pos_y += -0.10 * sin(-a);
    }
  if (state == GO_DOWN && key == BKS_LEFT)
    i->start_angle -= 5;
  if (state == GO_DOWN && key == BKS_RIGHT)
    i->start_angle += 5;
}

t_bunny_response	escp(t_bunny_event_state state,
			     t_bunny_keysym key, void *your_data)
{
  t_ini	*i;

  i = (t_ini *)your_data;
  bunny_display(i->win);
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  change_pos(i, state, key);
  return (GO_ON);
}

t_bunny_response	loop(void *data)
{
  t_ini	*i;

  i = (t_ini *)data;
  win_initialize(i->pix);
  aff_sky(i);
  aff_earth(i);
  start_loading(i->ini, i);
  bunny_blit(&i->win->buffer, &i->pix->clipable, NULL);
  bunny_display(i->win);
  return (GO_ON);
}

void		start_pos(t_ini *i)
{
  const char	*object;

  object = bunny_ini_get_field(i->ini, "level1", "start_position", 0);
  i->start_pos_x = get_nb(object);
  object = bunny_ini_get_field(i->ini, "level1", "start_position", 1);
  i->start_pos_y = get_nb(object);
  object = bunny_ini_get_field(i->ini, "level1", "start_position", 2);
  i->start_angle = get_nb(object);
}

int			main(int ac, char **av)
{
  t_ini			i;

  if (ac == 2)
    {
      i.win = bunny_start(SIZE_WINL, SIZE_WINH, false, "Wolf_3D");
      i.pix = bunny_new_pixelarray(SIZE_WINL, SIZE_WINH);
      if ((i.ini = bunny_load_ini(av[1])) == NULL)
        return (-1);
      start_pos(&i);
      bunny_set_loop_main_function(loop);
      bunny_set_key_response(escp);
      bunny_loop(i.win, 0, &i);
      bunny_stop(i.win);
      bunny_delete_clipable(&i.pix->clipable);
      bunny_delete_ini(i.ini);
    }
  return (0);
}
