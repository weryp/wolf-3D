##
## Makefile for Makefile in /home/wery_p/rendu/gfx_fdf1
##
## Made by paul wery
## Login   <wery_p@epitech.net>
##
## Started on  Thu Nov 19 00:44:55 2015 paul wery
## Last update Wed Dec 23 00:39:23 2015 paul wery
##

NAME    =	wolf3d

RM      =	rm -f

CC	=	gcc -W -Wall -Werror -ansi -pedantic

OBJS    =	$(SRCS:.c=.o)

SRCS    =	main.c \
		loading_file.c \
		first_part.c \
		choice.c \
		build_wall.c \
		tekpixel.c \
		win_initialize.c \
		get_nb.c \

$(NAME) :	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) -I/home/${USER}/.froot/include -L/home/${USER}/.froot/lib/ -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

all     :	$(NAME)

clean   :
	$(RM) $(OBJS)

fclean  :	clean
	$(RM) $(NAME)

re      :	fclean all

.PHONY: all clean fclean re
