/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** logging_func
*/

#include "myteams_client.h"

cli_logging_t cli_logging_func[] = {
    [_client_event_logged_in] = {"client_event_logged_in", NULL},
    [_client_event_logged_out] = {"client_event_logged_out", NULL},
    [_client_event_private_message_received] = {"client_event_private_message_received", NULL},
    [_client_event_thread_reply_received] = {"client_event_thread_reply_received", NULL},
    [_client_event_team_created] = {"client_event_team_created", NULL},
    [_client_event_channel_created] = {"client_event_channel_created", NULL},
    [_client_event_thread_created] = {"client_event_thread_created", NULL},
    [_client_print_users] = {"client_print_users", NULL},
    [_client_print_teams] = {"client_print_teams", NULL},
    [_client_team_print_channels] = {"client_team_print_channels", NULL},
    [_client_channel_print_threads] = {"client_channel_print_threads", NULL},
    [_client_thread_print_replies] = {"client_thread_print_replies", NULL},
    [_client_private_message_print_messages] = {"client_private_message_print_messages", NULL},
    [_client_error_unknown_team] = {"client_error_unknown_team", NULL},
    [_client_error_unknown_channel] = {"client_error_unknown_channel", NULL},
    [_client_error_unknown_thread] = {"client_error_unknown_thread", NULL},
    [_client_error_unknown_user] = {"client_error_unknown_user", NULL},
    [_client_error_unauthorized] = {"client_error_unauthorized", NULL},
    [_client_error_already_exist] = {"client_error_already_exist", NULL},
    [_client_print_user] = {"client_print_user", NULL},
    [_client_print_team] = {"client_print_team", NULL},
    [_client_print_channel] = {"client_print_channel", NULL},
    [_client_print_thread] = {"client_print_thread", NULL},
    [_client_print_team_created] = {"client_print_team_created", NULL},
    [_client_print_channel_created] = {"client_print_channel_created", NULL},
    [_client_print_thread_created] = {"client_print_thread_created", NULL},
    [_client_print_reply_created] = {"client_print_reply_created", NULL},
    [_client_print_subscribed] = {"client_print_subscribed", NULL},
    [_client_print_unsubscribed] = {"client_print_unsubscribed", NULL}
};

int CLIENT_EVENT_LOGGED_IN(const char *user_uuid, const char *user_name)
{
    return ((int (*)(const char *, const char *)) cli_logging_func[_client_event_logged_in].method)(user_uuid, user_name);
}

int CLIENT_EVENT_LOGGED_OUT(const char *user_uuid, const char *user_name)
{
    return ((int (*)(const char *, const char *)) cli_logging_func[_client_event_logged_out].method)(user_uuid, user_name);
}

int CLIENT_EVENT_PRIVATE_MESSAGE_RECEIVED(const char *user_uuid, const char *message_body)
{
    return ((int (*)(const char *, const char *)) cli_logging_func[_client_event_private_message_received].method)(user_uuid, message_body);
}

int CLIENT_EVENT_THREAD_REPLY_RECEIVED(const char *team_uuid, const char *thread_uuid, const char *user_uuid, const char *reply_body)
{
    return ((int (*)(const char *, const char *, const char *, const char *)) cli_logging_func[_client_event_thread_reply_received].method)(team_uuid, thread_uuid, user_uuid, reply_body);
}

int CLIENT_EVENT_TEAM_CREATED(const char *team_uuid, const char *team_name, const char *team_description)
{
    return ((int (*)(const char *, const char *, const char *)) cli_logging_func[_client_event_team_created].method)(team_uuid, team_name, team_description);
}

int CLIENT_EVENT_CHANNEL_CREATED(const char *channel_uuid, const char *channel_name, const char *channel_description)
{
    return ((int (*)(const char *, const char *, const char *)) cli_logging_func[_client_event_channel_created].method)(channel_uuid, channel_name, channel_description);
}

int CLIENT_EVENT_THREAD_CREATED(const char *thread_uuid, const char *user_uuid, time_t thread_timestamp, const char *thread_title, const char *thread_body)
{
    return ((int (*)(const char *, const char *, time_t, const char *, const char *)) cli_logging_func[_client_event_thread_created].method)(thread_uuid, user_uuid, thread_timestamp, thread_title, thread_body);
}

int CLIENT_PRINT_USERS(const char *user_uuid, const char *user_name, int user_status)
{
    return ((int (*)(const char *, const char *, int)) cli_logging_func[_client_print_users].method)(user_uuid, user_name, user_status);
}

int CLIENT_PRINT_TEAMS(const char *team_uuid, const char *team_name, const char *team_description)
{
    return ((int (*)(const char *, const char *, const char *)) cli_logging_func[_client_print_teams].method)(team_uuid, team_name, team_description);
}

int CLIENT_TEAM_PRINT_CHANNELS(const char *channel_uuid, const char *channel_name, const char *channel_description)
{
    return ((int (*)(const char *, const char *, const char *)) cli_logging_func[_client_team_print_channels].method)(channel_uuid, channel_name, channel_description);
}

int CLIENT_CHANNEL_PRINT_THREADS(const char *thread_uuid, const char *user_uuid, time_t thread_timestamp, const char *thread_title, const char *thread_body)
{
    return ((int (*)(const char *, const char *, time_t, const char *, const char *)) cli_logging_func[_client_channel_print_threads].method)(thread_uuid, user_uuid, thread_timestamp, thread_title, thread_body);
}

int CLIENT_THREAD_PRINT_REPLIES(const char *thread_uuid, const char *user_uuid, time_t reply_timestamp, const char *reply_body)
{
    return ((int (*)(const char *, const char *, time_t, const char *)) cli_logging_func[_client_thread_print_replies].method)(thread_uuid, user_uuid, reply_timestamp, reply_body);
}

int CLIENT_PRIVATE_MESSAGE_PRINT_MESSAGES(const char *sender_uuid, time_t message_timestamp, const char *message_body)
{
    return ((int (*)(const char *, time_t, const char *)) cli_logging_func[_client_private_message_print_messages].method)(sender_uuid, message_timestamp, message_body);
}

int CLIENT_ERROR_UNKNOWN_TEAM(const char *team_uuid)
{
    return ((int (*)(const char *)) cli_logging_func[_client_error_unknown_team].method)(team_uuid);
}

int CLIENT_ERROR_UNKNOWN_CHANNEL(const char *channel_uuid)
{
    return ((int (*)(const char *)) cli_logging_func[_client_error_unknown_channel].method)(channel_uuid);
}

int CLIENT_ERROR_UNKNOWN_THREAD(const char *thread_uuid)
{
    return ((int (*)(const char *)) cli_logging_func[_client_error_unknown_thread].method)(thread_uuid);
}

int CLIENT_ERROR_UNKNOWN_USER(const char *user_uuid)
{
    return ((int (*)(const char *)) cli_logging_func[_client_error_unknown_user].method)(user_uuid);
}

int CLIENT_ERROR_UNAUTHORIZED(void)
{
    return ((int (*)(void)) cli_logging_func[_client_error_unauthorized].method)();
}

int CLIENT_ERROR_ALREADY_EXIST(void)
{
    return ((int (*)(void)) cli_logging_func[_client_error_already_exist].method)();
}

int CLIENT_PRINT_USER(const char *user_uuid, const char *user_name, int user_status)
{
    return ((int (*)(const char *, const char *, int)) cli_logging_func[_client_print_user].method)(user_uuid, user_name, user_status);
}

int CLIENT_PRINT_TEAM(const char *team_uuid, const char *team_name, const char *team_description)
{
    return ((int (*)(const char *, const char *, const char *)) cli_logging_func[_client_print_team].method)(team_uuid, team_name, team_description);
}

int CLIENT_PRINT_CHANNEL(const char *channel_uuid, const char *channel_name, const char *channel_description)
{
    return ((int (*)(const char *, const char *, const char *)) cli_logging_func[_client_print_channel].method)(channel_uuid, channel_name, channel_description);
}

int CLIENT_PRINT_THREAD(const char *thread_uuid, const char *user_uuid, time_t thread_timestamp, const char *thread_title, const char *thread_body)
{
    return ((int (*)(const char *, const char *, time_t, const char *, const char *)) cli_logging_func[_client_print_thread].method)(thread_uuid, user_uuid, thread_timestamp, thread_title, thread_body);
}

int CLIENT_PRINT_TEAM_CREATED(const char *team_uuid, const char *team_name, const char *team_description)
{
    return ((int (*)(const char *, const char *, const char *)) cli_logging_func[_client_print_team_created].method)(team_uuid, team_name, team_description);
}

int CLIENT_PRINT_CHANNEL_CREATED(const char *channel_uuid, const char *channel_name, const char *channel_description)
{
    return ((int (*)(const char *, const char *, const char *)) cli_logging_func[_client_print_channel_created].method)(channel_uuid, channel_name, channel_description);
}

int CLIENT_PRINT_THREAD_CREATED(const char *thread_uuid, const char *user_uuid, time_t thread_timestamp, const char *thread_title, const char *thread_body)
{
    return ((int (*)(const char *, const char *, time_t, const char *, const char *)) cli_logging_func[_client_print_thread_created].method)(thread_uuid, user_uuid, thread_timestamp, thread_title, thread_body);
}

int CLIENT_PRINT_REPLY_CREATED(const char *thread_uuid, const char *user_uuid, time_t reply_timestamp, const char *reply_body)
{
    return ((int (*)(const char *, const char *, time_t, const char *)) cli_logging_func[_client_print_reply_created].method)(thread_uuid, user_uuid, reply_timestamp, reply_body);
}

int CLIENT_PRINT_SUBSCRIBED(const char *user_uuid, const char *team_uuid)
{
    return ((int (*)(const char *, const char *)) cli_logging_func[_client_print_subscribed].method)(user_uuid, team_uuid);
}

int CLIENT_PRINT_UNSUBSCRIBED(const char *user_uuid, const char *team_uuid)
{
    return ((int (*)(const char *, const char *)) cli_logging_func[_client_print_unsubscribed].method)(user_uuid, team_uuid);
}
