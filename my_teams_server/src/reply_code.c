/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** reply_code
*/

#include "myteams_server.h"

const char *reply_code[] = {
    [C150_OPEN_DATA_CONNECTION] = "150 File status okay; about to open data connection.\r\n",
    [C200_COMMAND_OK] = "200 Command okay.\r\n",
    [C214_HELP_MESSAGE] = "214 Help message. "
        "On how to use the server or the meaning of a particular "
        "non-standard command. "
        "This reply is useful only to the human user.\r\n",
    [C220_SERVICE_READY] = "220 Service ready for new user.\r\n",
    [C221_LOGOUT] = "221 Service closing control connection. "
        "Logged out if appropriate.\r\n",
    [C226_CLOSING_DATA_CONNECTION] = "226 Closing data connection. Requested file action successful.\r\n",
    [C227_ENTERING_PASSIVE_MODE] = "227 Entering Passive Mode (%s,%d,%d).\r\n",
    [C230_USER_LOGGED_IN_PROCEED] = "230 User logged in, proceed.\r\n",
    [C250_REQUEST_FILE_ACTION_OK] = "250 Requested file action okay, completed.\r\n",
    [C257_PATH_CREATED] = "257 \"%s\" created.\r\n",
    [C331_USERNAME_OK] = "331 User name okay, need password.\r\n",
    [C332_NEED_ACCOUNT] = "332 Need account for login.\r\n",
    [C425_CANT_OPEN_DATA_CONNECTION] = "425 Can\'t open data connection.\r\n",
    [C426_TRANSFER_ABORTED] = "426 Connection closed, transfer aborted.\r\n",
    [C451_LOCAL_ERROR_IN_PROCESSING] = "451 Requested action aborted: local error in processing.\r\n",
    [C500_SYNTAX_ERROR] = "500 Syntax error, command unrecognized. "
        "This may include errors such as command line too long.\r\n",
    [C501_ARGUMENT_ERROR] = "501 Syntax error in parameters or arguments.\r\n",
    [C503_BAD_SEQUENCE] = "503 Bad sequence of commands.\r\n",
    [C530_NOT_LOGGED_IN] = "530 Not logged in.\r\n",
    [C550_FILE_UNAVAILABLE] = "550 Requested action not taken. "
        "File unavailable (e.g., file not found, no access).\r\n",
    [C553_FILE_NAME_NOT_ALLOWED] = "553 Requested action not taken. File name not allowed.\r\n"
};
