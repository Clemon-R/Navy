/*
** file.h for default in /home/raphael.goulmot/rendu/CPE_2016_getnextline
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed Jan  4 16:12:53 2017 Raphaël Goulmot
** Last update Fri Jan 13 18:09:56 2017 Raphaël Goulmot
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
# define	READ_SIZE 1
# endif

typedef struct	s_save
{
  char	*save_buff;
  int	start_pos;
  int	old_fid;
  char	find;
}		t_save;

int	my_strlen(char *);
int	count_line(char *, char *, int);
char	*remalloc(char *, int);
char	refresh_buffer(int *, t_save *, int);
char	*get_next_line(const int);

#endif /* !END_H_ */
