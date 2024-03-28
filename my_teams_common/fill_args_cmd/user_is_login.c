/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** user_is_login
*/

#include "myteams_client.h"

is_login_e user_is_login(void)
{
    if (isLogin == NOT_LOGGED) {
        printf("User is not logged in\n");
    }
    return isLogin;
}
