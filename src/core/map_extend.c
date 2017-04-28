/*
** map_extend.c for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sun Feb 19 16:42:09 2017 Raphaël Goulmot
** Last update Sun Feb 19 16:53:00 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "map.h"
#include "navy.h"

char	check_line(char *arg)
{
  if (arg[1] != ':' || arg[4] != ':')
    return (84);
  else if (!(my_char_isnumeric(arg[2]) && !my_char_isnumeric(arg[3]))
	   && !(!my_char_isnumeric(arg[2]) && my_char_isnumeric(arg[3])))
    return (84);
  else if (!(my_char_isnumeric(arg[5]) && !my_char_isnumeric(arg[6]))
	   && !(!my_char_isnumeric(arg[5]) && my_char_isnumeric(arg[6])))
    return (84);
  return (0);
}
