/*
** main.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:01:44 2016 Raphaël Goulmot
** Last update Sun Feb 19 16:37:44 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "navy.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
  if (argc != 2 && argc != 3)
    {
      my_putstr_err("ERROR : Parameters !\n");
      return (84);
    }
  else if (argv[1][0] == '-' && argv[1][1] == 'h')
    {
      my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n\n");
      my_putstr("DESCRIPTION\n\tfirst_player_pid\tonly for the 2nd player.");
      my_putstr(" pid of the first player.\n");
      my_putstr("\tnavy_positions\t\tfile representing the positions of the");
      my_putstr(" ships.\n");
    }
  else
    {
      my_putstr("my_pid: ");
      my_put_nbr(getpid());
      my_putchar('\n');
      return (navy(argc, argv));
    }
  return (0);
}
