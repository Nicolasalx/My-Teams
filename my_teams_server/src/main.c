/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** main
*/

#include "myteams_server.h"

int main(int argc, char const *argv[])
{
    server_t server = {0};

    check_arg_validity(argc, argv, &server);
    init_logging_func(&server);
    create_server(&server);
    load_database(&server.database);
    lauch_server(&server);
    save_database(&server.database);
    delete_server(&server);
    free_all_alloc();
    return 0;
}
