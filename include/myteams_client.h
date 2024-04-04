/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** myteams_client
*/

#ifndef MYTEAMS_CLIENT_H_
    #define MYTEAMS_CLIENT_H_

    #include "my_importall.h"
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <string.h>
    #include <stdlib.h>
    #include "command_list.h"
    #include "reply_list.h"

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CMD_BUFFER_SIZE 4096

typedef struct {
    int fd;
    fd_set set;
    unsigned short port;
    struct sockaddr_in server_address;
    char *cmd_buffer;
    void *handle;
} client_t;

extern void (*const reply_handler[])(reply_data_t *);

extern context_e context;
extern is_login_e isLogin;

void check_arg_validity(int argc, const char **argv, client_t *client);
void init_logging_func(client_t *client);
void create_client(client_t *client);
client_t *get_client(client_t *client);
void init_client_set(client_t *client, int *max_fd);
void monitor_input(client_t *client, int max_fd);

void execute_command(client_t *client, char *command);
void handle_new_input(client_t *client);
void handle_new_message(client_t *client);
void handle_server_reply(reply_data_t *reply_data);

command_type_e init_user(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_help(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_login(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_logout(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_users(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_send(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_messages(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_subscribe(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_subscribed(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_unsubscribe(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_use(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_create(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_list(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_info(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);

command_type_e init_tree(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);

is_login_e user_is_login(void);

void reply_error_unauthorized(reply_data_t *reply_data);
void reply_error_already_exist(reply_data_t *reply_data);
void reply_error_unknow_channel(reply_data_t *reply_data);
void reply_error_unknow_team(reply_data_t *reply_data);
void reply_error_unknow_thread(reply_data_t *reply_data);
void reply_info_channel_cmd(reply_data_t *reply_data);
void reply_info_team_cmd(reply_data_t *reply_data);
void reply_info_thread_cmd(reply_data_t *reply_data);
void reply_info_user_cmd(reply_data_t *reply_data);
void reply_list_channel_cmd(reply_data_t *reply_data);
void reply_list_reply_cmd(reply_data_t *reply_data);
void reply_list_team_cmd(reply_data_t *reply_data);
void reply_list_thread_cmd(reply_data_t *reply_data);
void reply_login(reply_data_t *reply_data);
void reply_logout(reply_data_t *reply_data);
void reply_msg_cmd(reply_data_t *reply_data);
void reply_thread_reply(reply_data_t *reply_data);
void reply_new_channel_created(reply_data_t *reply_data);
void reply_new_team_created(reply_data_t *reply_data);
void reply_new_thread_created(reply_data_t *reply_data);
void reply_subscribe_cmd(reply_data_t *reply_data);
void reply_subscribed_team_cmd(reply_data_t *reply_data);
void reply_subscribed_user_cmd(reply_data_t *reply_data);
void reply_msg_received(reply_data_t *reply_data);
void reply_unknow_user(reply_data_t *reply_data);
void reply_unsubscribe_cmd(reply_data_t *reply_data);
void reply_user_cmd(reply_data_t *reply_data);
void reply_users_cmd(reply_data_t *reply_data);
void reply_create_team_cmd(reply_data_t *reply_data);
void reply_create_channel_cmd(reply_data_t *reply_data);
void reply_create_thread_cmd(reply_data_t *reply_data);
void reply_create_reply_cmd(reply_data_t *reply_data);
void reply_string(reply_data_t *reply_data);

void lauch_client(client_t *client);
void delete_client(client_t *client);
void exit_client(int exit_value, const char *message);

typedef struct {
    char *name;
    void *method;
} cli_logging_t;

enum cli_logging_e {
    _client_event_logged_in,
    _client_event_logged_out,
    _client_event_private_message_received,
    _client_event_thread_reply_received,
    _client_event_team_created,
    _client_event_channel_created,
    _client_event_thread_created,
    _client_print_users,
    _client_print_teams,
    _client_team_print_channels,
    _client_channel_print_threads,
    _client_thread_print_replies,
    _client_private_message_print_messages,
    _client_error_unknown_team,
    _client_error_unknown_channel,
    _client_error_unknown_thread,
    _client_error_unknown_user,
    _client_error_unauthorized,
    _client_error_already_exist,
    _client_print_user,
    _client_print_team,
    _client_print_channel,
    _client_print_thread,
    _client_print_team_created,
    _client_print_channel_created,
    _client_print_thread_created,
    _client_print_reply_created,
    _client_print_subscribed,
    _client_print_unsubscribed,
    _nb_func_cli
};

extern cli_logging_t cli_logging_func[];

int CLIENT_EVENT_LOGGED_IN(const char *user_uuid, const char *user_name);
int CLIENT_EVENT_LOGGED_OUT(const char *user_uuid, const char *user_name);
int CLIENT_EVENT_PRIVATE_MESSAGE_RECEIVED(const char *user_uuid, const char *message_body);
int CLIENT_EVENT_THREAD_REPLY_RECEIVED(const char *team_uuid, const char *thread_uuid, const char *user_uuid, const char *reply_body);
int CLIENT_EVENT_TEAM_CREATED(const char *team_uuid, const char *team_name, const char *team_description);
int CLIENT_EVENT_CHANNEL_CREATED(const char *channel_uuid, const char *channel_name, const char *channel_description);
int CLIENT_EVENT_THREAD_CREATED(const char *thread_uuid, const char *user_uuid, time_t thread_timestamp, const char *thread_title, const char *thread_body);
int CLIENT_PRINT_USERS(const char *user_uuid, const char *user_name, int user_status);
int CLIENT_PRINT_TEAMS(const char *team_uuid, const char *team_name, const char *team_description);
int CLIENT_TEAM_PRINT_CHANNELS(const char *channel_uuid, const char *channel_name, const char *channel_description);
int CLIENT_CHANNEL_PRINT_THREADS(const char *thread_uuid, const char *user_uuid, time_t thread_timestamp, const char *thread_title, const char *thread_body);
int CLIENT_THREAD_PRINT_REPLIES(const char *thread_uuid, const char *user_uuid, time_t reply_timestamp, const char *reply_body);
int CLIENT_PRIVATE_MESSAGE_PRINT_MESSAGES(const char *sender_uuid, time_t message_timestamp, const char *message_body);
int CLIENT_ERROR_UNKNOWN_TEAM(const char *team_uuid);
int CLIENT_ERROR_UNKNOWN_CHANNEL(const char *channel_uuid);
int CLIENT_ERROR_UNKNOWN_THREAD(const char *thread_uuid);
int CLIENT_ERROR_UNKNOWN_USER(const char *user_uuid);
int CLIENT_ERROR_UNAUTHORIZED(void);
int CLIENT_ERROR_ALREADY_EXIST(void);
int CLIENT_PRINT_USER(const char *user_uuid, const char *user_name, int user_status);
int CLIENT_PRINT_TEAM(const char *team_uuid, const char *team_name, const char *team_description);
int CLIENT_PRINT_CHANNEL(const char *channel_uuid, const char *channel_name, const char *channel_description);
int CLIENT_PRINT_THREAD(const char *thread_uuid, const char *user_uuid, time_t thread_timestamp, const char *thread_title, const char *thread_body);
int CLIENT_PRINT_TEAM_CREATED(const char *team_uuid, const char *team_name, const char *team_description);
int CLIENT_PRINT_CHANNEL_CREATED(const char *channel_uuid, const char *channel_name, const char *channel_description);
int CLIENT_PRINT_THREAD_CREATED(const char *thread_uuid, const char *user_uuid, time_t thread_timestamp, const char *thread_title, const char *thread_body);
int CLIENT_PRINT_REPLY_CREATED(const char *thread_uuid, const char *user_uuid, time_t reply_timestamp, const char *reply_body);
int CLIENT_PRINT_SUBSCRIBED(const char *user_uuid, const char *team_uuid);
int CLIENT_PRINT_UNSUBSCRIBED(const char *user_uuid, const char *team_uuid);

#endif /* !MYTEAMS_CLIENT_H_ */
