/*
** action.c for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed Feb  1 08:57:15 2017 Raphaël Goulmot
** Last update Wed Feb 15 18:02:29 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "navy.h"
#include "pos.h"

char	send(int sig)
{
  if (kill(packet.pid, sig) != 0)
    return (0);
  usleep(250);
  return (1);
}

char	action(int id, int arg_i, char *args)
{
  int	i;

  i = 0;
  while (i < id && ++i)
    {
      if (!send(SIGUSR1))
	return (84);
    }
  send(SIGUSR2);
  if (id == 1)
    my_putstr("successfully connected\n");
  else if (id == 3 || id == 2)
    {
      if (arg_i > 0 && !send(SIGUSR1))
	return (84);
    }
  else
    send_pos(packet.pid, args);
  return (send(SIGUSR2) ? 0 : 84);
}

void	new_packet(char end)
{
  if (!end)
    {
      packet.pos[0] = '0';
      packet.pos[1] = '0';
      packet.end = 0;
    }
  else
    {
      packet.end = 1;
      packet.current_pos = 0;
      packet.action = 0;
    }
}

char	get_action()
{
  struct sigaction	act;

  new_packet(0);
  act.sa_sigaction = &receive;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &act, 0);
  sigaction(SIGUSR2, &act, 0);
  while (!packet.end);
  if (packet.action == 2)
    return (1);
  return (0);
}

void	receive(int sig, siginfo_t *infos, void *context)
{
  if (sig == SIGUSR1)
    {
      if (packet.current_pos == 0)
	packet.action++;
      else
	{
	  if (packet.action == 3 || packet.action == 2)
	    packet.pos[0] = 1;
	  else
	    packet.pos[packet.current_pos - 1]++;
	}
      if (packet.action == 1 && packet.pid == -1)
	{
	  packet.pid = infos->si_pid;
	  my_putstr("enemy connected\n");
	}
    }
  else if (sig == SIGUSR2)
    packet.current_pos++;
  if ((packet.action == 0 && packet.current_pos >= 3)
      || (packet.action != 0 && packet.current_pos >= 2))
    new_packet(1);
}
