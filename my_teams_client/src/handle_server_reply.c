/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** handle_server_reply
*/

#include "myteams_client.h"
#include "reply_list.h"

void handle_server_reply(reply_data_t *reply_data)
{
    for (size_t i = 0; i < NUMBER_REPLY; ++i) {
        if (reply_data->type == i && reply_handler[i]) {
            reply_handler[i](reply_data);
            break;
        }
    }
}
