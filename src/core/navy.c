/*
** navy.c for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Jan 31 18:55:07 2017 Raphaël Goulmot
** Last update Sun Feb 19 17:15:21 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "navy.h"
#include "pos.h"
#include "get_next_line.h"
#include "map.h"
#include <fcntl.h>

char	get_attack()
{
  char	*check;

  my_putstr("waiting for enemy's attack...\n");
  get_action();
  check = &packet.my_map[(my_char_isnumeric(packet.pos[1]) ? packet.pos[1]
	   : packet.pos[0]) - '1'][(my_char_isnumeric(packet.pos[0])
	? packet.pos[1] : packet.pos[0]) - 'A'];
  action(3, my_char_isnumeric(*check) ? 1 : 0, 0);
  my_putchar(packet.pos[0]);
  my_putchar(packet.pos[1]);
  if (my_char_isnumeric(*check))
    my_putstr(": hit\n");
  else
    my_putstr(": missed\n");
  if (my_char_isnumeric(*check))
    *check = 'x';
  else
    *check = 'o';
  return (0);
}

char	attack(char *pos)
{
  char	*check;

  check = &packet.enemy_map[(my_char_isnumeric(pos[1]) ? pos[1]
  : pos[0]) - '1'][(my_char_isnumeric(pos[0]) ? pos[1] : pos[0]) - 'A'];
  if (!((pos[0] >= 'A' && pos[0] <= 'H') || (pos[0] >= '1' && pos[0] <= '8'))
   || !((pos[1] >= 'A' && pos[1] <= 'H') || (pos[1] >= '1' && pos[1] <= '8'))
      || my_strlen(pos) > 2 || *check != '.')
    {
      my_putstr_err(*check != '.' ? "already targeted\n" : "wrong position\n");
      return (84);
    }
  action(0, -1, pos);
  get_action();
  my_putchar(pos[0]);
  my_putchar(pos[1]);
  if (packet.pos[0] != '0')
    my_putstr(": hit\n");
  else
    my_putstr(": missed\n");
  *check = packet.pos[0] != '0' ? 'x': 'o';
  return (0);
}

char    play_turn(int id)
{
  char  *pos;
  char  state;

  state = 0;
  while (1)
    {
      pos = 0;
      refresh_display();
      if (state != 0 || (state = end_game(id)) != 0)
	return (state == -1 ? 1 : state == 1 ? 0 : 84);
      else if (id == 2 && get_attack())
	return (1);
      else if (id == 2)
	my_putchar('\n');
      while (!pos)
	{
	  my_putstr("attack: ");
	  pos = get_next_line(0);
	  pos = pos && attack(pos) == 84 ? 0 : pos;
	}
      if (id == 1)
	my_putchar('\n');
      if (id == 1)
	state = get_attack();
    }
}

char	user2(int pid, char *args)
{
  char	*pos;
  char	state;

  packet.pid = pid;
  state = 0;
  if (action(1, -1, 0) != 0)
    {
      my_putstr_err("ERROR : Connexion impossible !\n");
      return (84);
    }
  return (play_turn(2));
}

char	user1(int pid, char *args)
{
  char	*pos;
  char	state;

  state = 0;
  my_putstr("waiting for enemy connexion...\n");
  get_action();
  return (play_turn(1));
}
