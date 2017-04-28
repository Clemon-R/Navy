##
## Makefile for 102cipher in /home/raphael.goulmot/rendu/102cipher
## 
## Made by Raphaël Goulmot
## Login   <raphael.goulmot@epitech.net>
## 
## Started on  Tue Nov 29 15:57:16 2016 Raphaël Goulmot
## Last update Sun Feb 19 16:41:55 2017 Raphaël Goulmot
##

SRC	=	src/utils/my_putstr_err.c	\
		src/utils/my_putchar.c		\
		src/utils/my_putstr.c		\
		src/utils/my_strlen.c		\
		src/utils/my_getnbr.c		\
		src/utils/my_put_nbr.c		\
		src/utils/get_next_line.c	\
		src/utils/my_is.c		\
		src/core/navy.c			\
		src/core/navy_extend.c		\
		src/core/map.c			\
		src/core/map_extend.c		\
		src/core/pos.c			\
		src/core/action.c		\
		src/core/main.c			\
		include/get_next_line.h		\
		include/navy.h			\
		include/pos.h			\
		include/map.h			\
		include/utils.h

OBJ	=	$(SRC:.c=.o)

TMP	=	$(OBJ:.h=.h~)

CFLAGS	=	-W -Wextra -Werror -Iinclude

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(TMP)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
