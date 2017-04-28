/*
** navy_extend.c for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sun Feb 19 16:55:59 2017 Raphaël Goulmot
** Last update Sun Feb 19 17:15:24 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "navy.h"
#include "pos.h"
#include "map.h"

char    navy(int argc, char **argv)
{
  char  user;

  user = argc > 2 ? 2 : 1;
  if ((user == 2 && !my_str_isnumeric(argv[1])) || load_map(argv[user]) != 0)
    {
      my_putstr_err("ERROR : Map loading or PID incorrect !\n");
      return (84);
    }
  packet.pid = -1;
  if (user == 2)
    return (user2(my_getnbr(argv[1]), argv[2]));
  else
    {
      if (my_str_isnumeric(argv[1]))
	{
	  my_putstr_err("ERROR : Error parameters !\n");
	  return (84);
	}
      return (user1(packet.pid, argv[1]));
    }
  return (84);
}

char    end_game(int id)
{
  int   y;
  int   x;
  char  state;

  y = 0;
  state = -1;
  while (y++ < 8 && !(x = 0))
    while (x++ < 8)
      if (my_char_isnumeric(packet.my_map[y - 1][x - 1]))
	state = 0;
  if (id == 1)
    get_action();
  else
    action(2, (int)(state == -1 ? 1 : 0), 0);
  usleep(id == 1 ? 1000 : 1);
  if (id == 1)
    action(2, (int)(state == -1 ? 1 : 0), 0);
  else
    get_action();
  state = packet.pos[0] == 1 ? 1 : state;
  if (state == -1)
    my_putstr("Enemy won\n");
  else if (packet.pos[0] == 1)
    my_putstr("I won\n");
  return (state);
}
