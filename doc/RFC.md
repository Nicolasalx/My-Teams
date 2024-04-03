## RFC Document MyTeams

## Architecture pour envoyer une commande

Une commande simple est composée de cette suite:

```c++
cmd_data_t -> 1080 bytes

command_e type -> 4 bytes

byte de padding -> 4;

cmd_arg1_u arg1 -> 513 bytes

cmd_arg2_u arg2 -> 513 bytes

cmd_arg3_u arg3 -> 37 bytes

byte de padding -> 1;

cmd_arg4_u arg4 -> 8 bytes
```

### HELP

    - 4 bytes ayant pour valeur 0 (représente le numéro de la commande)
    - 1076 bytes de padding

### LOGIN

    - 4 bytes ayant pour valeur 1 (représente le numéro de la commande)
    - 4 bytes de padding
    - 132 bytes (pour le max name length) qui correspond au nom de l'utilisateur
    - 1040 bytes de padding

### LOGOUT

    - 4 bytes ayant pour valeur 2 (représente le numéro de la commande)
    - 1076 bytes de padding

### USERS

    - 4 bytes ayant pour valeur 3 (représente le numéro de la commande)
    - 1076 bytes de padding

### USER

    - 4 bytes ayant pour valeur 4 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 1036 bytes de padding

#### SEND

    - 4 bytes ayant pour valeur 5 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 512 bytes (pour la taille maximum du body) qui correspond au body du message envoyé
    - 524 bytes de padding

### MESSAGES

    - 4 bytes ayant pour valeur 6 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 1036 bytes de padding

### SUBSCRIBE

    - 4 bytes ayant pour valeur 7 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 1036 bytes de padding

### SUBSCRIBED

**First method**

    - 4 bytes ayant pour valeur 8 (représente le numéro de la commande)
    - 1072 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

**Second method**

    - 4 bytes ayant pour valeur 8 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 1028 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments


### UNSUBSCRIBE
    - 4 bytes ayant pour valeur 9 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 1036 bytes de padding

### USE

**Set context to NO_CONTEXT**

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 1072 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

**Set context to IN_TEAM**

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 1028 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

**Set context to IN_CHANNEL**

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 992 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

**Set context to IN_THREAD**

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 956 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

### CREATE

**Context value is NO_CONTEXT**


    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 4 bytes de padding
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom de la team
    - 255 bytes (pour la taille maximum de la description) qui correspond à la description de la team
    - 785 bytes de padding

**Context value is IN_TEAM**

    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 4 bytes de padding
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom du channel
    - 255 bytes (pour la taille maximum de la description) qui correspond à la description de la team
    - 785 bytes de padding

**Context value is IN_CHANNEL**

    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 4 bytes de padding
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom du thread
    - 512 bytes (pour la taille maximum du body) qui correspond au corps du message
    - 528 bytes de padding

**Context value is IN_THREAD**

    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 4 bytes de padding
    - 512 bytes (pour la taille maximum du body) qui correspond au corps du commentaire
    - 560 bytes de padding

### LIST

**Context value is NO_CONTEXT**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 0 qui correspond à set le context à la valeur NO_CONTEXT

**Context value is IN_TEAM**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 1 qui correspond à set le context à la valeur IN_TEAM

**Context value is IN_CHANNEL**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 2 qui correspond à set le context à la valeur IN_CHANNEL

**Context value is IN_THREAD**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 3 qui correspond à set le context à la valeur IN_THREAD

### INFO

**Context value is NO_CONTEXT**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

**Context value is IN_TEAM**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

**Context value is IN_CHANNEL**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

**Context value is IN_THREAD**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding


## Architecture pour envoyer une réponse

Une commande simple est composée de cette suite:

```c++
reply_data_t -> 2120 bytes

reply_e -> 4 bytes

7 bytes de padding

reply_arg1_u -> 37 bytes

reply_arg2_u -> 520 bytes

reply_arg3_u -> 520 bytes

reply_arg4_u -> 513 bytes

reply_arg5_u -> 513 bytes

6 bytes de padding
```

### reply_login

    - 4 bytes ayant pour valeur 0 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom de la team
    - 2041 bytes de padding

### reply_logged_out

    - 4 bytes ayant pour valeur 1 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom de la team
    - 2041 bytes de padding

### private_msg_received

    - 4 bytes ayant pour valeur 2 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 512 bytes (pour la taille maximum du corps) qui correspond au corps du message
    - 1561 bytes de padding

### thread_reply

    - 4 bytes ayant pour valeur 3 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 512 bytes (pour la taille maximum du corps) qui correspond au corps de la réponse
    - 1525 bytes de padding

### new_team_created

    - 4 bytes ayant pour valeur 4 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom de la team
    - 255 bytes (pour la taille maximum du body) qui correspond à la description de la team
    - 1786 bytes de padding

### new_channel_created

    - 4 bytes ayant pour valeur 5 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom du channel
    - 255 bytes (pour la taille maximum du body) qui correspond à la description du channel
    - 1786 bytes de padding

### new_thread_created

    - 4 bytes ayant pour valeur 6 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 8 bytes (pour la taille du temps)
    - 32 bytes pour la taille du thread_title
    - 512 bytes pour la taille du thread_body
    - 1485 bytes de padding

### reply_users

    - 4 bytes ayant pour valeur 7 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 32 bytes pour la taille maximum du nom
    - 8 bytes pour le status de l'utilisateur
    - 2033 bytes de padding

### reply_user

    - 4 bytes ayant pour valeur 8 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 32 bytes pour la taille maximum du nom
    - 8 bytes pour le status de l'utilisateur
    - 2033 bytes de padding

### reply_messages

    - 4 bytes ayant pour valeur 9 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du sender
    - 8 bytes pour la taille du message timestamp
    - 512 bytes pour la taille maximum du corps
    - 1553 bytes de padding

### reply_list_team

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 32 bytes (pour la taille maximum du nom de la team)
    - 255 bytes pour la taille maximum de la description de la team
    - 1786 bytes de padding

### reply_list_channel

    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 32 bytes (pour la taille maximum du nom du channel)
    - 255 bytes pour la taille maximum de la description du channel
    - 1786 bytes de padding

### reply_list_thread

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 8 bytes pour la taille du thread_timestamp
    - 32 bytes pour la taille du thread title
    - 512 bytes pour la taille du thread body
    - 1485 bytes de padding

### reply_list_reply

    - 4 bytes ayant pour valeur 13 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 8 bytes pour la taille du reply_timestamp
    - 512 bytes pour la taille du reply body
    - 1517 bytes de padding

### error_unknown_team

    - 4 bytes ayant pour valeur 14 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 2073 bytes de padding

### error_unknown_channel

    - 4 bytes ayant pour valeur 15 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 2073 bytes de padding

### error_unknown_thread

    - 4 bytes ayant pour valeur 16 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 2073 bytes de padding

### error_unknown_user

    - 4 bytes ayant pour valeur 17 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 2073 bytes de padding

### error_already_exist

    - 4 bytes ayant pour valeur 18 (représente le numéro de la commande)
    - 2116 bytes de padding

### reply_subscribe_cmd

    - 4 bytes ayant pour valeur 19 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 2037 bytes de padding

### reply_subscribed_team_cmd

    - 4 bytes ayant pour valeur 20 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 32 bytes pour le nom de la team
    - 255 bytes pour la description de la team
    - 1786 bytes de padding

### reply_subscribed_user_cmd

    - 4 bytes ayant pour valeur 21 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 32 bytes pour le nom de l'utilisateur
    - 8 bytes pour la taille du status de l'utilisateur
    - 2037 bytes de padding

### reply_unsubscribe_cmd

    - 4 bytes ayant pour valeur 22 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 2037 bytes de padding

### reply_info_user_cmd

    - 4 bytes ayant pour valeur 23 (représente le numéro de la commande)
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 32 bytes pour le nom de l'utilisateur
    - 8 bytes pour le status de l'utilisateur

### reply_info_team_cmd

    - 4 bytes ayant pour valeur 24 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 32 bytes pour le nom de la team
    - 255 bytes pour la description de la team
    - 1786 bytes de padding

### reply_info_channel_cmd

    - 4 bytes ayant pour valeur 25 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 32 bytes pour le nom du channel
    - 255 bytes pour la description du channel
    - 1786 bytes de padding

### reply_info_thread_cmd

    - 4 bytes ayant pour valeur 26 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 8 bytes pour la taille thread_timestamp
    - 32 bytes pour la taille du thread_title
    - 512 bytes pour la taille du thread_body
    - 1485 bytes de padding

### reply_create_team_cmd

    - 4 bytes ayant pour valeur 27 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 32 bytes pour le nom de la team
    - 255 bytes pour la description de la team
    - 1786 bytes de padding

### reply_create_channel_cmd

    - 4 bytes ayant pour valeur 28 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 32 bytes pour le nom du channel
    - 255 bytes pour la description du channel
    - 1786 bytes de padding

### reply_create_thread_cmd

    - 4 bytes ayant pour valeur 29 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 8 bytes pour la taille thread_timestamp
    - 32 bytes pour la taille du thread_title
    - 512 bytes pour la taille du thread_body
    - 1485 bytes de padding

### reply_create_reply_cmd

    - 4 bytes ayant pour valeur 30 (représente le numéro de la commande)
    - 7 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de l'utilisateur
    - 8 bytes pour la taille du reply_timestamp
    - 512 bytes pour la taille du reply_body
    - 1517 bytes de padding

### error_unauthorised

    - 4 bytes ayant pour valeur 31 (représente le numéro de la commande)
    - 2116 bytes de padding
