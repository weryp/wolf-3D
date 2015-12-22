/*
** get_nb.c for get_nb in /home/wery_p/rendu/gfx_incendie/picture
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Dec  6 03:07:45 2015 paul wery
** Last update Sat Dec 19 16:17:43 2015 paul wery
*/

unsigned int	real_nb(char c)
{
  unsigned int	nb;

  nb = 0;
  if (c > 57)
    {
      if (c == 'A' || c == 'a')
	nb = 10;
      if (c == 'B' || c == 'b')
	nb = 11;
      if (c == 'C' || c == 'c')
	nb = 12;
      if (c == 'D' || c == 'd')
	nb = 13;
      if (c == 'E' || c == 'e')
	nb = 14;
      if (c == 'F' || c == 'f')
	nb = 15;
    }
  else
    nb = c - 48;
  return (nb);
}

unsigned int     get_nb2(const char *buffer)
{
  unsigned int 	val;
  int		i;

  val = 0;
  i = 0;
  if (buffer[i] == '0' && buffer[i + 1] == 'x')
    i = i + 2;
  while (buffer[i] != '\0')
    {
      val = (val << 4) + real_nb(buffer[i]);
      i = i + 1;
    }
  return (val);
}

int     get_nb(const char *buffer)
{
  int   val;
  int  	i;
  int  	pow;
  int  	sign;

  sign = 0;
  pow = 10;
  val = 0;
  i = 0;
  if (buffer[0] == '-')
    {
      i = i + 1;
      sign = 1;
    }
  while (buffer[i] != '\0')
    {
      val = (val * pow) + (buffer[i] - 48);
      i = i + 1;
    }
  if (sign == 1)
    val = val * -1;
  return (val);
}
