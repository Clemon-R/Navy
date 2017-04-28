/*
** main.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:01:44 2016 Raphaël Goulmot
** Last update Sun Jan 22 18:32:31 2017 Raphaël Goulmot
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "utils.h"
#include "get_next_line.h"

int	count_line(char *str, char *find, int start)
{
  int	i;

  i = start;
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  *find = 1;
	  return (i);
	}
      i++;
    }
  return (i);
}

char	*remalloc(char *str, int len)
{
  char	*new;
  int	i;

  new = malloc(sizeof(char) * (len + my_strlen(str) + 1));
  i = 0;
  while (str[i++])
    new[i - 1] = str[i - 1];
  new[i] = '\0';
  free(str);
  str = new;
  return (new);
}

char	refresh_buffer(int *len, t_save *save, int fid)
{
  if (!save->save_buff)
    free(save->save_buff);
  save->save_buff = malloc(sizeof(char) * (READ_SIZE + 1));
  *len = read(fid, (*save).save_buff, READ_SIZE);
  if (*len <= 0 || save->save_buff[0] == '\n')
    return (1);
  (*save).save_buff[*len] = '\0';
  (*save).old_fid = fid;
  (*save).start_pos = 0;
  *len = 0;
  return (0);
}

char	*get_next_line(const int fid)
{
  char	*new;
  static t_save	save;
  int	len;
  int	i1;
  int	i2;

  if (fid < 0 || READ_SIZE <= 0)
    return (0);
  save.start_pos = save.old_fid != fid ? 0 : save.start_pos;
  save.find = 0;
  i2 = 0;
  while (!save.find || !i2)
    {
      if ((save.old_fid != fid || !save.save_buff
||save.start_pos>=my_strlen(save.save_buff))&&refresh_buffer(&len, &save, fid))
	  return (!i2 ? 0 : new);
      i1 = save.start_pos;
      len = count_line(save.save_buff, &save.find, i1) - i1;
      new = i2 ? remalloc(new, len) : malloc(sizeof(char) * (len + 1));
      while (i1 < (save.start_pos + len))
	new[i2++] = save.save_buff[i1++];
      new[i2] = '\0';
      save.start_pos = i1 + 1;
    }
  return (new);
}
