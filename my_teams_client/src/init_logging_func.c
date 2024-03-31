/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** init_logging_func
*/

#include "myteams_client.h"
#include <dlfcn.h>

static void get_symbol(client_t *client, size_t i)
{
    cli_logging_func[i].method = dlsym(client->handle, cli_logging_func[i].name);
    if (!cli_logging_func[i].method) {
        printf(RED("%s")"\n", dlerror());
        if (client->handle) {
            dlclose(client->handle);
        }
        my_exit(84);
    }
}

void init_logging_func(client_t *client)
{
    client->handle = dlopen("./libs/myteams/libmyteams.so", RTLD_LAZY);
    if (!client->handle) {
        printf(RED("%s")"\n", dlerror());
        my_exit(84);
    }

    for (size_t i = 0; i < _nb_func_cli; ++i) {
        get_symbol(client, i);
    }
}
