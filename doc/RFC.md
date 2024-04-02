## RFC Document MyTeams

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
    - 32 bytes (pour le max name length) qui correspond au nom de l'utilisateur
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

**First method**

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 1072 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

**Second method**

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 1028 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

**Third method**

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 992 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

**Fourth method**

    - 4 bytes ayant pour valeur 10 (représente le numéro de la commande)
    - 4 bytes de padding
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid de la team
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du channel
    - 36 bytes (pour la taille de l'UUID) qui correspond à l'uuid du thread
    - 956 bytes de padding
    - 8 bytes qui définit la taille qui stocke le nombre d'arguments

### CREATE

**First method**

    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 4 bytes de padding
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom de la team
    - 255 bytes (pour la taille maximum de la description) qui correspond à la description de la team
    - 785 bytes de padding

    - 4 bytes ayant pour valeur 0 qui correspond à set le context à la valeur NO_CONTEXT

**Second method**

    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 4 bytes de padding
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom du channel
    - 255 bytes (pour la taille maximum de la description) qui correspond à la description de la team
    - 785 bytes de padding

    - 4 bytes ayant pour valeur 1 qui correspond à set le context à la valeur IN_TEAM

**Third method**

    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 4 bytes de padding
    - 32 bytes (pour la taille maximum du nom) qui correspond au nom du thread
    - 512 bytes (pour la taille maximum du body) qui correspond au corps du message
    - 528 bytes de padding

    - 4 bytes ayant pour valeur 2 qui correspond à set le context à la valeur IN_CHANNEL

**Fourth method**

    - 4 bytes ayant pour valeur 11 (représente le numéro de la commande)
    - 4 bytes de padding
    - 512 bytes (pour la taille maximum du body) qui correspond au corps du commentaire
    - 560 bytes de padding

    - 4 bytes ayant pour valeur 3 qui correspond à set le context à la valeur IN_THREAD

### LIST

**First method**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 0 qui correspond à set le context à la valeur NO_CONTEXT

**Second method**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 1 qui correspond à set le context à la valeur IN_TEAM

**Third method**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 2 qui correspond à set le context à la valeur IN_CHANNEL

**Fourth method**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 3 qui correspond à set le context à la valeur IN_THREAD


### INFO

**First method**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 0 qui correspond à set le context à la valeur NO_CONTEXT

**Second method**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 1 qui correspond à set le context à la valeur IN_TEAM

**Third method**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 2 qui correspond à set le context à la valeur IN_CHANNEL

**Fourth method**

    - 4 bytes ayant pour valeur 12 (représente le numéro de la commande)
    - 1076 bytes de padding

    - 4 bytes ayant pour valeur 3 qui correspond à set le context à la valeur IN_THREAD

