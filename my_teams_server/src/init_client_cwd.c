/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** init_client_cwd
*/

#include "myteams_server.h"

void init_client_cwd(client_t *client)
{
    if (client->cwd == NULL) {
        client->cwd = my_malloc(sizeof(char) * (CWD_SIZE + 1));
        getcwd(client->cwd, CWD_SIZE);
    }
}
