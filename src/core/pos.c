/*
** pos.c for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Jan 31 20:02:55 2017 Raphaël Goulmot
** Last update Wed Feb 15 18:02:46 2017 Raphaël Goulmot
*/

#include "navy.h"
#include "pos.h"
#include "utils.h"

void	send_pos(int pid, char *pos)
{
  char	i;

  i = '0';
  while (i++ < pos[0])
    {
      kill(pid, SIGUSR1);
      usleep(250);
    }
  kill(pid, SIGUSR2);
  usleep(250);
  i = '0';
  while (i++ < pos[1])
    {
      kill(pid, SIGUSR1);
      usleep(250);
    }
}
