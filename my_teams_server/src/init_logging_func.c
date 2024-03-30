/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** init_logging_func
*/

#include "myteams_server.h"
#include <dlfcn.h>

void init_logging_func(server_t *server)
{
    server->handle = dlopen("./libs/myteams/libmyteams.so", RTLD_LAZY);
    if (!server->handle) {
        printf(RED("%s")"\n", dlerror());
        my_exit(84);
    }

    for (size_t i = 0; i < _nb_func; ++i) {
        server_logging_func[i].method = dlsym(server->handle, server_logging_func[i].name);
        if (!server_logging_func[i].method) {
            printf(RED("%s")"\n", dlerror());
            dlclose(server->handle);
            my_exit(84);
        }
    }
}
