/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** latency
*/

#include "myteams_client.h"
#include "command_list.h"
#include <sys/time.h>

command_type_t init_latency(char **, int nb_arg,
    cmd_data_t *cmd_data, command_t command)
{
    struct timeval current_time = {0};
    size_t c_time = 0;

    if (user_is_login() == NOT_LOGGED) {
        return COMMAND_FAILED;
    }
    if (nb_arg - 1 != command_list[command].nb_arg) {
        printf("Invalid arg in latency\n");
        return COMMAND_FAILED;
    }
    cmd_data->type = LATENCY;
    gettimeofday(&current_time, NULL);
    c_time = 1000000 * current_time.tv_sec + current_time.tv_usec;
    memcpy(&cmd_data->arg1, &c_time, sizeof(size_t));
    return COMMAND_SUCCEED;
}
