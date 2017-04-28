/*
** map.c for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Thu Feb  2 00:00:40 2017 Raphaël Goulmot
** Last update Sun Feb 19 17:04:14 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "map.h"
#include "get_next_line.h"
#include "navy.h"
#include <fcntl.h>

void	refresh_display()
{
  my_putchar('\n');
  my_putstr("my positions:\n");
  display_map(packet.my_map);
  my_putstr("enemy's positions:\n");
  display_map(packet.enemy_map);
}

char    place_ship(char *arg)
{
  int   id;
  int   pos_from[2];
  int   pos_to[2];
  int   value[2];

  if (check_line(arg) == 84)
    return (84);
  id = my_getnbr(arg);
  value[1] = 0;
  while (arg[value[1]] && arg[value[1]] != ':' && ++value[1]);
  pos_from[0] = arg[value[1] + 1] - 'A';
  pos_from[1] = arg[value[1] + 2] - '1';
  pos_to[0] = arg[value[1] + 4] - 'A';
  pos_to[1] = arg[value[1] + 5] - '1';
  value[1] = pos_from[1];
  if (!(pos_from[0] >= 0 && pos_from[0] < 8)
      || !(pos_from[1] >= 0 && pos_from[1] < 8) || !(pos_to[0] >= 0
     && pos_to[0] < 8) || !(pos_to[1] >= 0 && pos_to[1] < 8))
    return (84);
  while (value[1]++ <= pos_to[1] && (value[0] = pos_from[0]) >= 0)
    while (value[0]++ <= pos_to[0])
      packet.my_map[value[1] - 1][value[0] - 1] = '0' + id;
  return (0);
}

void    display_map(char **map)
{
  int   y;
  int   x;

  my_putstr(" |A B C D E F G H\n");
  my_putstr("-+---------------\n");
  y = 0;
  while (y++ < 8)
    {
      x = 0;
      my_put_nbr(y);
      my_putchar('|');
      while (x++ < 8)
	{
	  my_putchar(map[y - 1][x - 1]);
	  my_putchar(' ');
	}
      my_putchar('\n');
    }
  my_putchar('\n');
}

char    load_map(char *path)
{
  int   y;
  int   fid;
  char  *ship;
  int	start;
  int	total;

  total = 0;
  start = 1;
  fid = open(path, O_RDONLY);
  if (fid < 0)
    return (84);
  packet.enemy_map = init_map(packet.enemy_map);
  packet.my_map = init_map(packet.my_map);
  y = 0;
  while ((ship = get_next_line(fid)) != 0 && ++start)
    {
      if (my_getnbr(ship) != start || place_ship(ship) != 0)
	return (84);
      total += start;
    }
  return (total != 14 ? 84 : 0);
}

char    **init_map(char **arg)
{
  int   y;
  int   x;

  y = 0;
  arg = malloc(sizeof(char *) * 9);
  while (y++ < 8)
    {
      x = 0;
      arg[y - 1] = malloc(sizeof(char) * 9);
      while (x++ < 8)
	arg[y - 1][x - 1] = '.';
      arg[y - 1][x - 1] = 0;
    }
  arg[y - 1] = 0;
  return (arg);
}
