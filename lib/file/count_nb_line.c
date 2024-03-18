/*
** EPITECH PROJECT, 2024
** count_nb_line
** File description:
** count_nb_line
*/

int count_nb_line(const char *str)
{
    int count = 0;
    int already_count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (already_count == 0) {
            ++ count;
            already_count = 1;
        }
        if (str[i] == '\n') {
            already_count = 0;
        }
    }
    return count;
}
