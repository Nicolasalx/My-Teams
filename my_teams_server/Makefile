##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC				:=	$(shell find src/ -name "*.c")

CFLAGS			=	-Wall -Wextra \
					-I../include/ -I../include/lib/ -I../libs/myteams/ \
					-luuid -ldl \
					$(ADDITIONAL_FLAGS) \

LDLIBS			=	-lmyteams

LDFLAGS			=	-L../libs/myteams/

NAME			=	../myteams_server

LIB_PATH		=	../lib/

LIB_NAME		=	../lib/my_lib.a

SRC_TESTS		:=	$(shell find ../tests/ -name "*.c")

RUN_TEST		=	--coverage -lcriterion

NAME_TESTS		=	unit_tests

OBJ				=	$(SRC:.c=.o)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ && \
	printf "[\e[92mOK\e[0m] gcc $(CFLAGS) -c $< -o $@\n" || \
	printf "[\e[1;91mKO\e[0m] gcc $(CFLAGS) -c $< -o $@\n"

$(NAME): $(OBJ)
	@cd $(LIB_PATH) && $(MAKE) ADDITIONAL_FLAGS="$(ADDITIONAL_FLAGS)"
	@export LD_LIBRARY_PATH=$(realpath ../libs/myteams/):$LD_LIBRARY_PATH
	@if gcc -o $(NAME) $(OBJ) $(LIB_NAME) $(CFLAGS) $(LDFLAGS) $(LDLIBS); then \
		printf "[\e[92mCOMPILATION OK\e[0m] "; \
		printf "gcc -o $(NAME) $(OBJ) $(LIB_NAME) $(CFLAGS)\n"; \
	else \
		printf "[\e[1;91mCOMPILATION KO\e[0m] "; \
		printf "gcc -o $(NAME) $(OBJ) $(LIB_NAME) $(CFLAGS)\n"; \
		exit 1; \
	fi

all: $(NAME)

clean:
	rm -f $(OBJ) $(shell find src/ -name "*.o")
	rm -f $(shell find src/ -name "*.gcno")
	rm -f $(shell find src/ -name "*.gcda")
	rm -f *.gcno *.gcda gmon.out compile_commands.json

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)
	@cd $(LIB_PATH) && $(MAKE) fclean

re: fclean all

unit_tests: SRC := $(patsubst src/main.c%,%,$(SRC))
unit_tests: clean
	@cd $(LIB_PATH) && $(MAKE)
	@if gcc -o $(NAME_TESTS) $(SRC_TESTS) $(SRC) \
		$(LIB_NAME) $(CFLAGS) $(RUN_TEST); then \
		printf "[\e[92mCOMPILATION OK\e[0m] "; \
		printf "gcc -o -o $(NAME_TESTS) $(SRC_TESTS) $(SRC)"; \
		printf "$(LIB_NAME) $(CFLAGS) $(RUN_TEST)\n"; \
	else \
		printf "[\e[1;91mCOMPILATION KO\e[0m] "; \
		printf "gcc -o -o $(NAME_TESTS) $(SRC_TESTS) $(SRC)"; \
		printf "$(LIB_NAME) $(CFLAGS) $(RUN_TEST)\n"; \
		exit 1; \
	fi

tests_run: unit_tests
	./$(NAME_TESTS)

gcovr:
	@gcovr --sort-percentage --exclude tests/
	@gcovr --sort-percentage --exclude tests/ --branches

debug: CFLAGS += -g3
debug: clean all
	gdb -ex "run $(arg)" -ex "bt full" -ex "detach" -ex "quit" $(NAME)

profiling: CFLAGS += -pg
profiling: clean all
	@printf "\e[0m------------------------------\e[0m\n"
	./$(NAME) $(arg)
	@printf "\e[0m------------------------------\e[0m\n"
	gprof $(NAME) gmon.out

compilation_database: clean
	bear -- make

code_analyse: compilation_database
	clang-tidy -header-filter=.* --use-color $(SRC)

.PHONY: all clean fclean re unit_tests tests_run gcovr \
	debug profiling compilation_database code_analyse
