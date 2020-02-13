##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Basic Makfile
##

SRC	=	src/client.c		\
		src/read_write.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	client-interface

CFLAGS	=	-Wall -Wextra -W -I./include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
