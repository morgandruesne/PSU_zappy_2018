##
## EPITECH PROJECT, 2019
## Makefile my_ftp
## File description:
## description
##

CC		=	gcc

CFLAGS	=	-lm -W -Wall -Wextra -pedantic -g3

SRC		=	src/main.c								\
			librairy/my_strisnum.c					\
			librairy/my_returns.c					\
			librairy/get_next_line.c				\
			librairy/split.c						\
			librairy/mstrconcat.c					\
			src/error_handling/error_handling.c		\
			src/error_handling/help.c				\
			src/struct/create_current.c				\
			src/struct/delete_current.c				\
			src/struct/delete_team.c				\
			src/struct/create_map.c					\
			src/struct/create_ob.c					\
			src/struct/create_inv.c					\
			src/struct/delete_ob.c					\
			src/struct/create_tv.c					\
			src/struct/egg.c						\
			src/struct/lst.c						\
			src/struct/player.c						\
			src/struct/player_function.c			\
			src/server/create_server.c				\
			src/server/delete_client.c				\
			src/server/try_push_team.c				\
			src/server/server_cycle.c				\
			src/server/server_listen.c				\
			src/game/get_team.c						\
			src/game/look_tools.c					\
			src/game/check_end_game.c				\
			src/game/generate_item.c				\
			src/cmd/msz.c							\
			src/cmd/fork.c							\
			src/cmd/tna.c							\
			src/cmd/bct.c							\
			src/cmd/mct.c							\
			src/cmd/right.c							\
			src/cmd/left.c							\
			src/cmd/take.c							\
			src/cmd/pin.c							\
			src/cmd/plv.c							\
			src/cmd/ppo.c							\
			src/cmd/set.c							\
			src/cmd/broadcast.c						\
			src/cmd/death.c							\
			src/cmd/inventory.c						\
			src/cmd/nbrc.c							\
			src/cmd/forward.c						\
			src/cmd/look.c							\
			src/cmd/incantation.c					\
			src/cmd/incantation_up.c				\
			src/cmd/eject.c							\
			src/cmd/need/need1.c					\
			src/cmd/need/need2.c					\
			src/cmd/need/error_inc.c				\
			src/cmd/need/calc.c						\
			src/cmd/need/versions.c					\
			src/cmd/byegraphic.c					\
			src/send/pnw.c							\
			src/send/pgt.c							\
			src/send/pdr.c							\
			src/send/pbc.c							\
			src/send/pic.c							\
			src/send/pie.c							\
			src/send/seg.c							\
			src/send/enw.c							\
			src/send/eht.c							\
			src/send/graphic_connection_send.c		\


OBJ		=	$(SRC:.c=.o)

NAME	=	zappy_server

all		:	zappy_server zappy_ai

zappy_server	:	$(NAME)

zappy_ai	:
			cp zappy_ai.py zappy_ai

$(NAME)	:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS)


clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)
			rm -f zappy_ai

re		:	fclean all
