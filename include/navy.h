/*
** navy.h for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Jan 31 18:55:17 2017 Raphaël Goulmot
** Last update Thu Feb  2 02:13:50 2017 Raphaël Goulmot
*/

#ifndef NAVY_H_
# define NAVY_H_

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_world
{
  int	pid;
  int	nbr;
  int	action;
  int	current_pos;
  char	end;
  char	pos[2];
  char	**my_map;
  char	**enemy_map;
}		t_world;

t_world	packet;

char	action(int, int, char *);
char	get_action();
char	get_action_ext();
char	get_attack();
void	receive(int, siginfo_t *, void *);
void	new_packet(char);
char	user1(int, char *);
char	user2(int, char *);
char	navy(int, char **);

#endif
