/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_command
*/

#include "myteams_client.h"

char *remove_space_out_quotes(const char *string)
{
    bool is_in_quote = false;
    size_t index = 0;
    char *result = NULL;

    result = malloc(sizeof(char) * (strlen(string)) + 1);
    if (result == NULL) {
        return NULL;
    }
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == '\"') {
            is_in_quote = !is_in_quote;
        }
        if (!is_in_quote && string[i] == ' ') {
            continue;
        } else {
            result[index] = string[i];
            ++index;
        }
    }
    return result;
}

void execute_command(client_t *client, char *command)
{
    const char *new_str = remove_space_out_quotes(command);
    const char *delimiter = "\"\n";
    int nb_word = count_nb_word(new_str, delimiter);
    int *size_word = count_size_word(new_str, delimiter, nb_word);
    char **array = my_str_to_word(new_str, delimiter, nb_word, size_word);

    for (int i = 0; array[i] != NULL; ++i) {
        printf("String : [%s]\n", array[i]);
    }

    if (send(client->fd, command, strlen(command), 0) == -1) {
        exit_client(84, RED("Fail to send message to server.\n"));
    }
}
