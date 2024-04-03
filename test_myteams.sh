#!/bin/bash

RETURN_VALUE=0

rm -f myteams.save
make > /dev/null

export LD_LIBRARY_PATH=$(realpath ./libs/myteams/)

test_is_empty()
{
    if [ -s cli_out ]; then
        echo -e "[\e[91mFAIL\e[0m]"
        RETURN_VALUE=1
    else
        echo -e "[\e[92mPASS\e[0m]"
    fi
}

test_is_not_empty()
{
    if [ -s cli_out ]; then
        echo -e "[\e[92mPASS\e[0m]"
    else
        echo -e "[\e[91mFAIL\e[0m]"
        RETURN_VALUE=1
    fi
}

test_nb_of_line()
{
    if [ "$(wc -l < cli_out)" -eq "$1" ]; then
        echo -e "[\e[92mPASS\e[0m]"
    else
        echo -e "[\e[91mFAIL\e[0m]"
        RETURN_VALUE=1
    fi
}

i_test=1

test_name()
{
    echo -e "Test[\e[95m$i_test\e[0m]: $1"
    ((i_test++))
}

test_name "Anonymous login"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 2

test_name "Anonymous login with empty quote"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"\"" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 2

test_name "Basic login"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hello\"" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 2

test_name "Invalid login 1"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login Hello" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_is_empty

test_name "Invalid login 2"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login aa aa" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_is_empty

test_name "Invalid login 3"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hello\" aaaa" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_is_empty

test_name "Invalid login 4"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hello\" \"aaaa\"" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_is_empty

test_name "Invalid login 5"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "login \"Hello\"" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_is_empty

test_name "logout"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hello\"\n/logout" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 2

test_name "users"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hi\"\n/users" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 4

test_name "Invalid user uuid 1"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hi\"\n/user" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 2

test_name "Invalid user uuid 2"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hi\"\n/user \"\"" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 3

test_name "Invalid user uuid 3"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hi\"\n/user \"sqdqdsqd\"" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 3

test_name "Invalid user uuid 4"
export LD_LIBRARY_PATH=$(realpath ./libs/myteams/) && echo -e "/login \"Hi\"\n/user \"51e432a9-c1b3-4792-9a8a-1d78e4bf2dd4\"" | ./myteams_cli localhost 4242 2> cli_out ; cat cli_out
test_nb_of_line 3

exit $RETURN_VALUE
