##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC	=	test.c		\
		my_getnbr.c	\
		my_strtowordarray.c

OBJ 	= 	$(SRC:.c = .o)

NAME	=	test_technique

$(FLAGS):	-W -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(FLAGS) $(NAME) $(OBJ) -g3
clean:
	rm -f \#*\#
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all