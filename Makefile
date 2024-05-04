##
## EPITECH PROJECT, 2024
## B-OOP-400-MAR-4-1-raytracer-noam.bouriche
## File description:
## Makefile
##

NAME	=	raytracer

all:	$(NAME)

FLAGS = -g3 -lconfig++ -lsfml-graphics -lsfml-window -lsfml-system

$(NAME):	$(SRC)
	@g++ -o $(NAME) src/*.cpp src/Math/*.cpp $(FLAGS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all