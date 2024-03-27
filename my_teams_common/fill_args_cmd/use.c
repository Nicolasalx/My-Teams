/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** use
*/

#include "myteams_client.h"
#include "command_list.h"
    
void init_use(char **array, int nb_arg, cmd_data_t *cmd_data, command_e)
{
    if (!(nb_arg >= 1 && nb_arg <= 4)) {
        printf("Invalid arg in the use\n");
        return;
    }
    for (int i = 1; i <= nb_arg; i++) {
        if (strlen(array[i]) != UUID_LENGTH) {
            printf("Bad length of the uuid for argument %d\n", i);
            return;
        }
        switch (i) {
            case 1:
                strcpy(cmd_data->arg1.team_uuid, array[1]);
                context = IN_TEAM;
                break;
            case 2:
                strcpy(cmd_data->arg2.channel_uuid, array[2]);
                context = IN_CHANNEL;
                break;
            case 3:
                strcpy(cmd_data->arg3.thread_uuid, array[3]);
                context = IN_THREAD;
                break;
        }
    }
    cmd_data->type = USE;
}
