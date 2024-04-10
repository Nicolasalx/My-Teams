## RFC Document MyTeams

## Architecture for sending a command

A simple command is composed of this sequence:

```c++
cmd_data_t -> 1080 bytes

command_t type -> 4 bytes

padding byte -> 4;

cmd_arg1_u arg1 -> 513 bytes

cmd_arg2_u arg2 -> 513 bytes

cmd_arg3_u arg3 -> 37 bytes

padding byte -> 1;

cmd_arg4_u arg4 -> 8 bytes
```

### HELP

    - 4 bytes with value 0 (represents command number)
    - 1076 bytes padding

### LOGIN

    - 4 bytes with value 1 (represents the order number)
    - 4 bytes padding
    - 132 bytes (for max name length) corresponding to user name
    - 1040 bytes padding

### LOGOUT

    - 4 bytes with value 2 (represents the command number)
    - 1076 bytes padding

### USERS

    - 4 bytes with value 3 (represents order number)
    - 1076 bytes padding

### USER

    - 4 bytes with value 4 (represents order number)
    - 4 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 1036 bytes padding

#### SEND

    - 4 bytes with value 5 (represents command number)
    - 4 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 512 bytes (for maximum body size) corresponding to the body of the message sent
    - 524 bytes padding

### MESSAGES

    - 4 bytes with value 6 (represents the command number)
    - 4 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 1036 bytes padding

### SUBSCRIBE

    - 4 bytes with value 7 (represents command number)
    - 4 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 1036 bytes padding

### SUBSCRIBED

**First method**

    - 4 bytes with value 8 (represents the order number)
    - 1072 bytes padding
    - 8 bytes defines the size that stores the number of arguments

**Second method**

    - 4 bytes with value 8 (represents the command number)
    - 4 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 1028 bytes padding
    - 8 bytes which defines the size that stores the number of arguments


### UNSUBSCRIBE
    - 4 bytes with value 9 (represents the command number)
    - 4 bytes padding
    - 36 bytes (for the UUID size) corresponding to the team uuid
    - 1036 bytes padding

### USE

**Set context to NO_CONTEXT**

    - 4 bytes with value 10 (represents command number)
    - 1072 bytes of padding
    - 8 bytes which defines the size that stores the number of arguments

**Set context to IN_TEAM**

    - 4 bytes with value 10 (represents the command number)
    - 4 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 1028 bytes padding
    - 8 bytes which defines the size that stores the number of arguments

**Set context to IN_CHANNEL**

    - 4 bytes with value 10 (represents the command number)
    - 4 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 36 bytes (for UUID size) corresponding to channel uuid
    - 992 bytes padding
    - 8 bytes which defines the size that stores the number of arguments

**Set context to IN_THREAD**

    - 4 bytes with value 10 (represents the command number)
    - 4 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 36 bytes (for UUID size) corresponding to channel uuid
    - 36 bytes (for UUID size) corresponding to thread uuid
    - 956 bytes padding
    - 8 bytes which defines the size that stores the number of arguments

### CREATE

**Context value is NO_CONTEXT**


    - 4 bytes with value 11 (represents the order number)
    - 4 bytes padding
    - 32 bytes (for the maximum size of the name) corresponding to the team name
    - 255 bytes (for the maximum size of the description) corresponding to the team description
    - 785 bytes padding

**Context value is IN_TEAM**

    - 4 bytes with value 11 (represents the order number)
    - 4 bytes padding
    - 32 bytes (for maximum name size) corresponding to the channel name
    - 255 bytes (for maximum description size) corresponding to the team description
    - 785 bytes padding

**Context value is IN_CHANNEL**

    - 4 bytes with value 11 (represents the order number)
    - 4 bytes padding
    - 32 bytes (for maximum name size) corresponding to the thread name
    - 512 bytes (for the maximum body size) corresponding to the message body
    - 528 bytes padding

**Context value is IN_THREAD**

    - 4 bytes with value 11 (represents the command number)
    - 4 bytes padding
    - 512 bytes (for the maximum body size) corresponding to the comment body
    - 560 bytes padding

### LIST

**Context value is NO_CONTEXT**

    - 4 bytes with value 12 (represents command number)
    - 1076 bytes of padding

    - 4 bytes with value 0 corresponding to set context value to NO_CONTEXT

**Context value is IN_TEAM**

    - 4 bytes with value 12 (represents command number)
    - 1076 bytes of padding

    - 4 bytes with a value of 1, which corresponds to setting the context value to IN_TEAM

**Context value is IN_CHANNEL**

    - 4 bytes with value 12 (represents command number)
    - 1076 bytes of padding

    - 4 bytes with value 2, which corresponds to setting the context value to IN_CHANNEL

**Context value is IN_THREAD**

    - 4 bytes with value 12 (represents command number)
    - 1076 bytes of padding

    - 4 bytes with value 3 corresponding to set context value IN_THREAD

### INFO

**Context value is NO_CONTEXT**

    - 4 bytes with value 12 (represents the order number)
    - 1076 bytes of padding

**Context value is IN_TEAM**

    - 4 bytes with value 12 (represents order number)
    - 1076 bytes of padding

**Context value is IN_CHANNEL**

    - 4 bytes with value 12 (represents order number)
    - 1076 bytes of padding

**Context value is IN_THREAD**

    - 4 bytes with value 12 (represents order number)
    - 1076 bytes of padding


## Architecture to send a response

A simple command is composed of this sequence:

```c++
reply_data_t -> 2120 bytes

reply_enum_t -> 4 bytes

7 bytes padding

reply_arg1_u -> 37 bytes

reply_arg2_u -> 520 bytes

reply_arg3_u -> 520 bytes

reply_arg4_u -> 513 bytes

reply_arg5_u -> 513 bytes

6 bytes padding
```

### reply_login

    - 4 bytes with value 0 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 32 bytes (for maximum name size) which corresponds to the team name
    - 2041 bytes padding

### reply_logged_out

    - 4 bytes with value 1 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 32 bytes (for maximum name size) corresponding to the team name
    - 2041 bytes padding

### private_msg_received

    - 4 bytes with value 2 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 512 bytes (for maximum body size) corresponding to the message body
    - 1561 bytes padding

### thread_reply

    - 4 bytes with value 3 (represents the command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 36 bytes (for UUID size) corresponding to thread uuid
    - 36 bytes (for UUID size) corresponding to user uuid
    - 512 bytes (for maximum body size) corresponding to the response body
    - 1525 bytes padding

### new_team_created

    - 4 bytes with value 4 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 32 bytes (for maximum name size) corresponding to the team name
    - 255 bytes (for the maximum body size) corresponding to the team description
    - 1786 bytes padding

### new_channel_created

    - 4 bytes with value 5 (represents the order number)
    - 7 bytes of padding
    - 36 bytes (for UUID size) corresponding to the channel uuid
    - 32 bytes (for maximum name size) which corresponds to the channel name
    - 255 bytes (for maximum body size) which corresponds to the channel description
    - 1786 bytes padding

### new_thread_created

    - 4 bytes with value 6 (represents the command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the thread uuid
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 8 bytes (for time size)
    - 32 bytes for thread_title size
    - 512 bytes for thread_body size
    - 1485 bytes padding

### reply_users

    - 4 bytes with value 7 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 32 bytes for maximum name size
    - 8 bytes for user status
    - 2033 bytes padding

### reply_user

    - 4 bytes with value 8 (represents the command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 32 bytes for maximum name size
    - 8 bytes for user status
    - 2033 bytes padding

### reply_messages

    - 4 bytes with value 9 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the sender uuid
    - 8 bytes for message size timestamp
    - 512 bytes for maximum body size
    - 1553 bytes padding

### reply_list_team

    - 4 bytes with a value of 10 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 32 bytes (for maximum team name size)
    - 255 bytes for the maximum size of the team description
    - 1786 bytes padding

### reply_list_channel

    - 4 bytes with value 11 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the channel uuid
    - 32 bytes (for maximum channel name size)
    - 255 bytes for maximum channel description size
    - 1786 bytes padding

### reply_list_thread

    - 4 bytes with value 12 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the thread uuid
    - 36 bytes (for UUID size) corresponding to user uuid
    - 8 bytes for thread_timestamp size
    - 32 bytes for thread title size
    - 512 bytes for thread body size
    - 1485 bytes padding

### reply_list_reply

    - 4 bytes with value 13 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the thread uuid
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 8 bytes for reply_timestamp size
    - 512 bytes for reply body size
    - 1517 bytes padding

### error_unknown_team

    - 4 bytes with value 14 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 2073 bytes padding

### error_unknown_channel

    - 4 bytes with value 15 (represents the command number)
    - 7 bytes of padding
    - 36 bytes (for the UUID size) corresponding to the channel uuid
    - 2073 bytes padding

### error_unknown_thread

    - 4 bytes with value 16 (represents the command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the thread uuid
    - 2073 bytes padding

### error_unknown_user

    - 4 bytes with value 17 (represents the command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 2073 bytes padding

### error_already_exist

    - 4 bytes with value 18 (represents the command number)
    - 2116 bytes of padding

### reply_subscribe_cmd

    - 4 bytes with value 19 (represents order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 36 bytes (for UUID size) corresponding to team uuid
    - 2037 bytes padding

### reply_subscribed_team_cmd

    - 4 bytes with value 20 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for the UUID size) corresponding to the team uuid
    - 32 bytes for team name
    - 255 bytes for team description
    - 1786 bytes padding

### reply_subscribed_user_cmd

    - 4 bytes with value 21 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 32 bytes for user name
    - 8 bytes for user status size
    - 2037 bytes padding

### reply_unsubscribe_cmd

    - 4 bytes with value 22 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 36 bytes (for UUID size) corresponding to team uuid
    - 2037 bytes padding

### reply_info_user_cmd

    - 4 bytes with value 23 (represents the command number)
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 32 bytes for user name
    - 8 bytes for user status

### reply_info_team_cmd

    - 4 bytes with value 24 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 32 bytes for team name
    - 255 bytes for team description
    - 1786 bytes padding

### reply_info_channel_cmd

    - 4 bytes with value 25 (represents command number)
    - 7 bytes padding
    - 36 bytes (for the UUID size) corresponding to the channel uuid
    - 32 bytes for channel name
    - 255 bytes for channel description
    - 1786 bytes padding

### reply_info_thread_cmd

    - 4 bytes with value 26 (represents the command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the thread uuid
    - 36 bytes (for UUID size) corresponding to user uuid
    - 8 bytes for thread_timestamp size
    - 32 bytes for thread_title size
    - 512 bytes for thread_body size
    - 1485 bytes padding

### reply_create_team_cmd

    - 4 bytes with value 27 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the team uuid
    - 32 bytes for team name
    - 255 bytes for team description
    - 1786 bytes padding

### reply_create_channel_cmd

    - 4 bytes with value 28 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for the UUID size) corresponding to the channel uuid
    - 32 bytes for channel name
    - 255 bytes for channel description
    - 1786 bytes padding

### reply_create_thread_cmd

    - 4 bytes with value 29 (represents the order number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the thread uuid
    - 36 bytes (for UUID size) corresponding to user uuid
    - 8 bytes for thread_timestamp size
    - 32 bytes for thread_title size
    - 512 bytes for thread_body size
    - 1485 bytes padding

### reply_create_reply_cmd

    - 4 bytes with value 30 (represents command number)
    - 7 bytes padding
    - 36 bytes (for UUID size) corresponding to the thread uuid
    - 36 bytes (for UUID size) corresponding to the user's uuid
    - 8 bytes for reply_timestamp size
    - 512 bytes for reply_body size
    - 1517 bytes padding

### error_unauthorised

    - 4 bytes with value 31 (represents command number)
    - 2116 bytes padding
