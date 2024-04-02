## Documentation MyTeams

## Fonctionnalités

Grace à notre myTeams il est possible de:

- Créer / Rejoindre / Quitter une équipe
- Créer un nouvel utilisateur
- Créer un channel dans une équipe
- Créer un thread dans une équipe
- Créer un commentaire dans un thread
- Sauvegarder et récupérer les informations des utilisateurs, des équipes, des channels, des threads ainsi que des commentaires associées meme si on ferme notre programme et on le réouvre
- Discussions privées entre deux utilisateurs
- Sauvegarder et récupérer les informations des discussions privées

## Informations générales

Toutes les variables des commandes sont envoyées entre guillemets.
Si un guillement n'est pas fermée alors ceci est considéré comme une erreur.

Tous les noms, les descriptions et les corps de chaque messages ont une taille prédéfinies.

Voici un tableau excel représentant la taille de chaque variable pour chaque commande:

### Pour les différentes commandes :

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/370b2190-376a-41d7-a6be-a61050c8c2f1)

### Pour les différentes fonctions de log:

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/32b06268-9987-4d96-afcc-3ea562f937d9)

[Lien du excel](https://docs.google.com/spreadsheets/d/1H2t4_oshqHsgGL587w_E4KzidiC7-bOBTvqxcqb8ihA/edit?usp=sharing)


### Sécurité:

Tout au long du projet nous utilisons des uuid pour identifier les équipes, les utilisateurs et tout autre éléments de l'architecture.

- UUID signifie "Universally Unique IDentifier" et désigne un standard d'identifiant généré aléatoirement et globalement unique.

- Dans sa représentation textuelle canonique, les 16 octets d'un UUID sont représentés comme 32 chiffres hexadécimaux en minuscules séparés par 4 tirets sous la forme suivante:

- ![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/c784c68d-3e27-4631-95f5-fb119f7467de)




## Architecture



**Voici le diagramme UML de l'architecture :**

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/b40db3d1-e5c2-4bf2-b08a-b39605dcfe40)


[Lien du diagramme UML](https://lucid.app/lucidchart/a8e29117-268b-4242-990c-ea4ac505bb69/edit?viewport_loc=328%2C-140%2C2132%2C1061%2CL.BeP2~polPs&invitationId=inv_ba9770aa-35eb-4e9d-8abd-1a3ca333fedd)


## CLI client

Le client gère les commandes suivantes depuis la standard input:

- /help : affiche des informations pour aider l'utilisateur
- /login ["nom_utilisateur"] : définit le nom d'utilisateur utilisé par le client
- /logout : déconnecte le client du serveur
- /users : obtient la liste de tous les utilisateurs qui existent sur le domaine
- /user ["user_uuid"] : obtenir des détails sur l'utilisateur demandé
- /send ["user_uuid"] ["message_body"] : envoyer un message à un utilisateur spécifique
- /messages ["user_uuid"] : liste tous les messages échangés avec l'utilisateur spécifié
- /subscribe ["team_uuid"] : s'abonner aux événements d'une équipe et de ses sous-répertoires (permet de recevoir tous les événements d'une équipe)
tous les événements d'une équipe)
- /subscribed ?["team_uuid"] : liste de toutes les équipes abonnées ou liste de tous les utilisateurs abonnés à une équipe
- /unsubscribe ["team_uuid"] : se désinscrire d'une équipe
- /use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"] : définit le contexte de la commande à une équipe/un canal/une discussion.
- /create : en fonction du contexte, crée la sous-ressource (voir ci-dessous)
- /list : en fonction du contexte, liste toutes les sous-ressources (voir ci-dessous)
- /info : en fonction du contexte, affiche les détails de la ressource courante (voir ci-dessous)



**Le client se connecte de cette manière au serveur:**

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/980f7648-9dce-4e26-824c-e96df78740f9)


### Fonctionnement du client

Le client se connecte au serveur grace à une IP et à un port.

L'utilisateur doit d'abord ce login.

Une fois cela fait, il peut ensuite envoyer des commandes.

## Serveur

Le serveur est capable de gérer plusieurs clients en même temps en utilisant la fonction select pour la gestion des commandes.
Lorsque le serveur est arrêté, il sauvegarde ses informations internes dans le dossier en cours.
Lorsque le serveur démarre, il vérifie si le fichier de sauvegarde existe et le charge si c'est le cas.

**Le serveur est initialiser de cette manière:**

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/79f46fdd-1519-42ac-8d38-b46185c6eea4)

### Fonctionnement du serveur

Le serveur recoit les commandes du client, il s'occupe d'exécuter les actions nécessaires (si une team est créer, un channel est créer, etc...).

Gérer la **base de données** qui est composée de la liste des équipes, la liste des utilisateurs ainsi que de la list des messages privés.

La base de données est disposé comme cela:

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/03cc2444-25d4-4d82-a169-bfe04859938e)


## Logger

Les évènements ainsi que les data sont print grace à la lib de log "libmyteams.so".
Il y a de nombreuses fonctions à appeler pour le serveur ainsi que pour le client.

### 1. Pour la partie logger du client :

Les fonctions dont le nom contient **"event"** sont appelées lorsque vous recevez quelque chose du serveur, lorsque ce n'est pas vous qui avez initié l'action.
Les autres fonctions sont appelées en réponse à l'une de vos actions.

J'ai reçu un message privé (je n'ai rien fait pour cela) donc la fonction à appeler est celle dont le nom contient "event".

J'ai demandé au serveur de rejoindre une équipe (j'ai initié cette action). La fonction à appeler est une fonction qui n'a pas event dans son nom.

**Exemple 1:**
Un utilisateur se connecte au serveur grace à la commande login, j'appelle la fonction **"client_event_logged_in"** avec:

- user_uuid L'identifiant de l'utilisateur qui s'est connecté
- user_name Le nom de l'utilisateur qui s'est connecté

```c++
int client_event_logged_in(char const *user_uuid, const char *user_name);
```

**Exemple 2:**
Un utilisateur connecté recoit un message privé grace à la commande send, j'appelle la fonction **"client_event_private_message_received"** avec:
- user_uuid L'identifiant de l'utilisateur qui a envoyé le message privé
- message_body Le corps du message privé

```c++
int client_event_private_message_received(
    char const *user_uuid,
    char const *message_body);
```

### 2. Pour la partie logger du serveur :

Comme le serveur n'initialise jamais d'action, toutes les fonctions sont appelées événements.

**Exemple 1:**

Le serveur à créer une nouvelle équipe donc j'appelle la fonction **"server_event_team_created"** avec:
- team_uuid L'identifiant de l'équipe qui a été créée
- team_name Le nom de l'équipe qui a été créée
- user_uuid L'identifiant de l'utilisateur qui a créé la nouvelle équipe

```c++
int server_event_team_created(
    char const *team_uuid,
    char const *team_name,
    char const *user_uuid);
```

**Exemple 2:**

Le server à créer un nouveau channel donc j'appelle la fonction **"server_event_channel_created"** avec:

- team_uuid L'identifiant de l'équipe dans laquelle se trouve ce canal
- channel_uuid L'identifiant du canal créé
- channel_name Le nom du nouveau canal

```c++
int server_event_channel_created(
    char const *team_uuid,
    char const *channel_uuid,
    char const *channel_name);
```
