/*
** my_getnbr.c for default in /home/raphael.goulmot/default_struct
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Dec 16 15:20:37 2016 Raphaël Goulmot
** Last update Fri Dec 16 15:25:37 2016 Raphaël Goulmot
*/

#include "utils.h"

int	my_getnbr(char *str)
{
  int	i;
  char	neg;
  int	value;

  i = 0;
  while (str[i] && !(str[i] >= '0' && str[i] <= '9') && ++i);
  neg = str[i - 1] == '-';
  value = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9' && ++i)
    value = value * 10 + (str[i - 1] - 48);
  return (value * (neg ? -1 : 1));
}
