##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## EPITECH Project Makefile for SOLO_STUMPER
##

SRC			=	src/main.c								\
				src/check_args.c							\
				src/file_gestion.c							\
				src/cesar.c

SRC_TEST	=	units_tests/test.c \
				src/check_args.c \
				src/file_gestion.c \
				src/cesar.c

NAME		=	chocolatine

NAME_TEST	=	unit_tests

OBJ 		= 	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I./include

FLAG_TEST   =  -lcriterion --coverage

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:			$(NAME)

debug:			$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS) -g3 $(LIB)

clean:
				rm -rf $(OBJ)

clean_tests:
				find . -name "*.gc*" -type f -delete
				rm -rf $(OBJ_TEST)

fclean:			clean clean_tests
				rm -rf $(NAME)
				rm -rf $(NAME_TEST)

tests_run: 		CFLAGS += --coverage

tests_run:		fclean
				gcc -o $(NAME_TEST) $(SRC_TEST) $(CFLAGS) $(FLAG_TEST)
				./$(NAME_TEST) --verbose

re:				fclean all

.PHONY: 		all debug clean fclean re test_run
