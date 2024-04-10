/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** user_is_login
*/

#include "myteams_client.h"

is_login_t user_is_login(void)
{
    if (isLogin == NOT_LOGGED) {
        client_error_unauthorized();
    }
    return isLogin;
}
