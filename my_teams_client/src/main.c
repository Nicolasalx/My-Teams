/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** main
*/

#include "myteams_client.h"

int main(int argc, char const *argv[])
{
    client_t client = {0};

    check_arg_validity(argc, argv, &client);
    create_client(&client);
    lauch_client(&client);
    delete_client(&client);
    free_all_alloc();
    return 0;
}
