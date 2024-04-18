##
## EPITECH PROJECT, 2024
## B-OOP-400-MAR-4-1-raytracer-noam.bouriche
## File description:
## Makefile
##

SRC	=	./src/main.cpp\

NAME	=	raytracer

all:	$(NAME)

$(NAME):	$(SRC)
	g++ -o $(NAME) $(SRC) -g3

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)
	make clean

re: fclean all