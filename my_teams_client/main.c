/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "myteams_server"

int main(int argc, const char *argv[])
{
    server_t server = {0};

    check_arg_validity(argc, argv, &server);
    create_server(&server);
    lauch_server(&server);
    delete_server(&server);
    return 0;
}
