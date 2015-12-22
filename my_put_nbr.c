/*
** my_put_nbr.c for my_put_nbr.c in /home/wery_p/rendu/test
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Oct 23 11:27:40 2015 paul wery
** Last update Sun Nov 29 18:16:50 2015 paul wery
*/

void	my_put_nbr(int nb)
{
  int	val_aff;

  val_aff = 0;
  if (nb < 0)
    {
      nb = - nb;
      my_putchar('-');
    }
  if (nb >= 10)
    {
      val_aff = nb % 10;
      my_put_nbr(nb / 10);
    }
  if (nb < 10 && nb >= 0)
    {
      val_aff = nb;
    }
  my_putchar(val_aff + 48);
}
