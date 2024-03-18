##
## EPITECH PROJECT, 2024
## B-NWP-400-PAR-4-1-myteams-thibaud.cathala
## File description:
## Makefile
##

SERVER_PATH		=	./my_teams_server/

CLIENT_PATH		=	./my_teams_client/

all:
	cd $(CLIENT_PATH) && $(MAKE)
	cd $(SERVER_PATH) && $(MAKE)

clean:
	cd $(CLIENT_PATH) && $(MAKE) clean
	cd $(SERVER_PATH) && $(MAKE) clean

fclean:
	cd $(CLIENT_PATH) && $(MAKE) fclean
	cd $(SERVER_PATH) && $(MAKE) fclean

re:
	cd $(CLIENT_PATH) && $(MAKE) re
	cd $(SERVER_PATH) && $(MAKE) re

unit_tests:
	cd $(CLIENT_PATH) && $(MAKE) unit_tests
	cd $(SERVER_PATH) && $(MAKE) unit_tests

tests_run:
	cd $(CLIENT_PATH) && $(MAKE) tests_run
	cd $(SERVER_PATH) && $(MAKE) tests_run

code_analyse:
	cd $(CLIENT_PATH) && $(MAKE) code_analyse
	cd $(SERVER_PATH) && $(MAKE) code_analyse

.PHONY: all clean fclean re unit_tests tests_run code_analyse
