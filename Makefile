##
## Makefile for wolf3d in /home/mael.drapier/wolf3d
##
## Made by mael drapier
## Login   <mael.drapier@epitech.net>
##
## Started on  Tue Nov  8 16:48:53 2016 mael drapier
## Last update Mon Jan 23 18:31:18 2017 mael drapier
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wextra -Wall -Werror
CFLAGS	+=	-I include/

LDFLAGS	=	-Wl,-rpath=./lib/ -L ./lib/ -lc_graph_prog -lm

NAME	=	wolf3d

SRCS	=	src/my_put_pixel.c \
		src/my_draw_line.c \
		src/move_forward.c \
		src/raycast.c \
		src/display.c \
		src/init.c \
		src/read_map.c \
		src/drawing.c\
		src/helper.c \
		src/features.c \
		src/features2.c \
		src/main.c

OBJS	=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
