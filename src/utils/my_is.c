/*
** my_is.c for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed Feb  1 23:58:45 2017 Raphaël Goulmot
** Last update Wed Feb  1 23:59:08 2017 Raphaël Goulmot
*/

#include "utils.h"

char    my_str_isnumeric(char *str)
{
  int   i;

  i = 0;
  while (str[i++])
    if (!((str[i - 1] >= '0' && str[i - 1] <= '9') || str[i - 1] == '-'))
      return (0);
  return (1);
}

char    my_char_isnumeric(char c)
{
  return (c >= '0' && c <= '9');
}
