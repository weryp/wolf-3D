/*
** ini_struct.h for ini_struct in /home/wery_p/rendu/Bazar/wind/my_fonctions_liblapin/test_sphere
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Dec 12 03:06:29 2015 paul wery
** Last update Wed Dec 23 00:06:49 2015 paul wery
*/

#include <lapin.h>
#ifndef MY_INI
#define MY_INI
#define SIZE_WINL 640
#define SIZE_WINH 640
#define D 0.5
#define P 1.0

typedef struct s_ini t_ini;
struct s_ini
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  int			width;
  int			height;
  float			start_pos_x;
  float			start_pos_y;
  double	       	start_angle;
  int			x;
  float			save1;
  float			save2;
  t_bunny_ini		*ini;
  float			vx;
  float			vy;
};

#endif /* MY_INI  */
