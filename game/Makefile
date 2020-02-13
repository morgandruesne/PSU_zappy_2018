CXX			= 		g++

RM			=		rm -f

CXXFLAGS	=	-W -Wall -Wextra -lpthread -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -L/usr/local/lib -I./include/ -g

SRC			=		src/main.cpp							\
					src/interface.cpp						\
					src/event/eventManager.cpp				\
					src/player/player.cpp					\
					src/player/playerAnimation.cpp			\
					src/player/playerWalk.cpp				\
					src/player/playerInteractions.cpp		\
					src/socket.cpp							\
					src/command_manager/exec_action.cpp		\
					src/command_manager/command_pnw.cpp		\
					src/command_manager/command_msz.cpp		\
					src/command_manager/command_ppo.cpp		\
					src/command_manager/command_pie.cpp		\
					src/command_manager/command_pex.cpp		\
					src/command_manager/command_pdi.cpp		\
					src/command_manager/command_bct.cpp		\
					src/command_manager/command_pgt.cpp		\
					src/map/map.cpp							\

OBJ			=		$(SRC:.cpp=.o)

NAME		=		zappy_interface

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all