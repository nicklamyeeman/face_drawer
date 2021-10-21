##
## STUDIO MIXX, 2020
## Face Drawer
## File description:
## Makefile
##

SRC			=	./src/window/Window.cpp 			\
				./src/window/Event.cpp	 			\
				./src/image/UploadSprite.cpp		\
				./src/image/AnalyzeImage.cpp		\
				./src/main.cpp

OBJ			=	$(SRC:.cpp=.o)

INC			=	-Iinclude/window -Iinclude/image

CXXFLAGS	=	-W -Wall -Wextra -Werror $(INC)

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

NAME		=	face_drawer

all:	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(SFMLFLAGS)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re