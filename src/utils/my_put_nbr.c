/*
** my_put_nbr.c for minishell in /home/raphael.goulmot/rendu/Bootstrap_Minishell
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed Jan  4 09:40:53 2017 Raphaël Goulmot
** Last update Wed Jan  4 11:08:01 2017 Raphaël Goulmot
*/

#include "utils.h"

void	my_put_nbr(int nbr)
{
  int	value;

  value = 1;
  if (nbr == 0)
    {
      my_putchar('0');
      return;
    }
  else if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  while (value <= nbr)
    value *= 10;
  value /= 10;
  while (value > 0)
    {
      my_putchar(48 + (nbr / value) % 10);
      value /= 10;
    }
}
