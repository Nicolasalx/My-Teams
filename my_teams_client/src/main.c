/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** main
*/

#include "myteams_client.h"

int main(int argc, char const *argv[])
{
    client_t client;

    check_arg_validity(argc, argv, &client);
    return 0;
}
