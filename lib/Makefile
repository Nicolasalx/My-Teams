##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## lib_Makefile
##

SRC				=	$(shell find ./ -name "*.c")

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I../include/lib

LIBFLAG		=

NAME		=	my_lib.a

%.o : %.c
	@ gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@ && \
	printf "[\e[92mOK\e[0m] gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@\n" || \
	printf "[\e[1;91mKO\e[0m] gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@\n"

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ) && \
	printf "[\e[92mLINKING OK\e[0m] ar rc $(NAME) $(OBJ)\n" || \
	printf "[\e[1;91mLINKING KO\e[0m] ar rc $(NAME) $(OBJ)\n"

all: $(NAME)

clean:
	@rm -f $(shell find ./ -name "*.o")
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
