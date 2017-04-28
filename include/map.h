/*
** map.c for navy in /home/raphael.goulmot/rendu/PSU_2016_navy
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Thu Feb  2 00:03:50 2017 Raphaël Goulmot
** Last update Sun Feb 19 17:13:06 2017 Raphaël Goulmot
*/

#ifndef	MAP_H_
# define MAP_H_

void	refresh_display();
char	place_ship(char *);
void	display_map(char **);
char	load_map(char *);
char	**init_map(char **);
char	end_game(int );
char	check_line(char *);

#endif
