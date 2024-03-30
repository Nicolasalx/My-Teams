/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** logging_func
*/

#include "myteams_server.h"

server_logging_t server_logging_func[] = {
    [_server_event_team_created] = {"server_event_team_created", NULL},
    [_server_event_channel_created] = {"server_event_channel_created", NULL},
    [_server_event_thread_created] = {"server_event_thread_created", NULL},
    [_server_event_reply_created] = {"server_event_reply_created", NULL},
    [_server_event_user_subscribed] = {"server_event_user_subscribed", NULL},
    [_server_event_user_unsubscribed] = {"server_event_user_unsubscribed", NULL},
    [_server_event_user_created] = {"server_event_user_created", NULL},
    [_server_event_user_loaded] = {"server_event_user_loaded", NULL},
    [_server_event_user_logged_in] = {"server_event_user_logged_in", NULL},
    [_server_event_user_logged_out] = {"server_event_user_logged_out", NULL},
    [_server_event_private_message_sended] = {"server_event_private_message_sended", NULL},
};

int SERVER_EVENT_TEAM_CREATED(const char *team_uuid, const char *team_name, const char *user_uuid)
{
    return ((int (*)(const char *, const char *, const char *))
        server_logging_func[_server_event_team_created].method)(team_uuid, team_name, user_uuid);
}

int SERVER_EVENT_CHANNEL_CREATED(const char *team_uuid, const char *channel_uuid, const char *channel_name)
{
    return ((int (*)(const char *, const char *, const char *))
        server_logging_func[_server_event_channel_created].method)(team_uuid, channel_uuid, channel_name);
}

int SERVER_EVENT_THREAD_CREATED(const char *channel_uuid, const char *thread_uuid,
    const char *user_uuid, const char *thread_title, const char *thread_body)
{
    return ((int (*)(const char *, const char *, const char *, const char *, const char *))
        server_logging_func[_server_event_thread_created].method)(channel_uuid, thread_uuid, user_uuid, thread_title, thread_body);
}

int SERVER_EVENT_REPLY_CREATED(const char *thread_uuid, const char *user_uuid, const char *reply_body)
{
    return ((int (*)(const char *, const char *, const char *))
        server_logging_func[_server_event_reply_created].method)(thread_uuid, user_uuid, reply_body);
}

int SERVER_EVENT_USER_SUBSCRIBED(const char *team_uuid, const char *user_uuid)
{
    return ((int (*)(const char *, const char *))
        server_logging_func[_server_event_user_subscribed].method)(team_uuid, user_uuid);
}

int SERVER_EVENT_USER_UNSUBSCRIBED(const char *team_uuid, const char *user_uuid)
{
    return ((int (*)(const char *, const char *))
        server_logging_func[_server_event_user_unsubscribed].method)(team_uuid, user_uuid);
}

int SERVER_EVENT_USER_CREATED(const char *user_uuid, const char *user_name)
{
    return ((int (*)(const char *, const char *))
        server_logging_func[_server_event_user_created].method)(user_uuid, user_name);
}

int SERVER_EVENT_USER_LOADED(const char *user_uuid, const char *user_name)
{
    return ((int (*)(const char *, const char *))
        server_logging_func[_server_event_user_loaded].method)(user_uuid, user_name);
}

int SERVER_EVENT_USER_LOGGED_IN(const char *user_uuid)
{
    return ((int (*)(const char *))
        server_logging_func[_server_event_user_logged_in].method)(user_uuid);
}

int SERVER_EVENT_USER_LOGGED_OUT(const char *user_uuid)
{
    return ((int (*)(const char *))
        server_logging_func[_server_event_user_logged_out].method)(user_uuid);
}

int SERVER_EVENT_PRIVATE_MESSAGE_SENDED(const char *sender_uuid, const char *receiver_uuid, const char *message_body)
{
    return ((int (*)(const char *, const char *, const char *))
        server_logging_func[_server_event_private_message_sended].method)(sender_uuid, receiver_uuid, message_body);
}
