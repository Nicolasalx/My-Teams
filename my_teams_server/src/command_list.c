/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** command_list
*/

#include "myteams_server.h"

const command_t command_list[] = {
    // {"USER", false, user_command, "214 USER <username> : Specify user for authentication.\r\n"},
    // {"PASS", false, pass_command, "214 PASS <password> : Specify password for authentication.\r\n"},
    // {"QUIT", false, quit_command, "214 QUIT : Disconnection.\r\n"},
    // {"HELP", true, help_command, "214 HELP [<string>] : List available commands.\r\n"},
    // {"NOOP", true, noop_command, "214 NOOP : Do nothing.\r\n"},
    // {"PWD", true, pwd_command, "214 PWD : Print working directory.\r\n"},
    // {"CWD", true, cwd_command, "214 CWD <pathname> : Change working directory.\r\n"},
    // {"CDUP", true, cdup_command, "214 CDUP : Change working directory to parent directory.\r\n"},
    // {"PASV", true, pasv_command, "214 PASV : Enable \"passive\" mode for data transfer.\r\n"},
    // {"PORT", true, port_command, "214 PORT <host-port> : Enable \"active\" mode for data transfer.\r\n"},
    // {"LIST", true, list_command, "214 LIST [<pathname>] : List files in the current working directory.\r\n"},
    // {"DELE", true, dele_command, "214 DELE <pathname> : Delete file on the server.\r\n"},
    // {"STOR", true, stor_command, "214 STOR <pathname> : Upload file from client to server.\r\n"},
    // {"RETR", true, retr_command, "214 RETR <pathname> : Download file from server to client.\r\n"},
    {NULL, false, NULL, NULL}
};
