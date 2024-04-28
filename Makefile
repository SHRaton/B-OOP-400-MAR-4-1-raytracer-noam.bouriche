##
## EPITECH PROJECT, 2024
## B-OOP-400-MAR-4-1-raytracer-noam.bouriche
## File description:
## Makefile
##

NAME	=	raytracer

all:	$(NAME)

$(NAME):	$(SRC)
	@g++ -o $(NAME) src/*.cpp src/Math/*.cpp -g3 -lconfig++

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all