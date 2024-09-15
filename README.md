## MyTeams documentation

## Features

With myTeams you can:

- Create / Join / Leave a team
- Create a new user
- Create a channel in a team
- Create a thread in a team
- Create a comment in a thread
- Save and retrieve information on users, teams, channels, threads and associated comments even if you close and reopen your program
- Private discussions between two users
- Save and retrieve information from private discussions

## General information

All command variables are enclosed in quotation marks.
If a quotation mark is not closed, this is considered an error.

All message names, descriptions and bodies have a predefined size.

Here's an excel table showing the size of each variable for each command:

### For the various commands :

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/370b2190-376a-41d7-a6be-a61050c8c2f1)

### For the various log functions:

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/32b06268-9987-4d96-afcc-3ea562f937d9)

[Link of the excel](https://docs.google.com/spreadsheets/d/1H2t4_oshqHsgGL587w_E4KzidiC7-bOBTvqxcqb8ihA/edit?usp=sharing)

### Security:

Throughout the project, we use uuids to identify teams, users and other elements of the architecture.

- UUID stands for "Universally Unique IDentifier" and designates a globally unique, randomly generated identifier standard.

- In its canonical textual representation, the 16 bytes of a UUID are represented as 32 lower-case hexadecimal digits separated by 4 dashes in the following form:

- ![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/c784c68d-3e27-4631-95f5-fb119f7467de)


## Architecture

**Here's the UML architecture diagram:**

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/b40db3d1-e5c2-4bf2-b08a-b39605dcfe40)


[Link of the UML Diagram](https://lucid.app/lucidchart/a8e29117-268b-4242-990c-ea4ac505bb69/edit?viewport_loc=328%2C-140%2C2132%2C1061%2CL.BeP2~polPs&invitationId=inv_ba9770aa-35eb-4e9d-8abd-1a3ca333fedd)


## CLI client

The client handles the following commands from standard input:

- /help : displays information to help the user
- /login ["username"] : defines the username used by the client
- /logout : disconnects the client from the server
- /users : gets a list of all users on the domain
- /user ["user_uuid"] : obtain details of the requested user
- /send ["user_uuid"] ["message_body"] : send a message to a specific user
- /messages ["user_uuid"]: list all messages exchanged with the specified user
- /subscribe ["team_uuid"]: subscribe to events from a team and its subdirectories (allows you to receive all team events)
all team events)
- /subscribed ["team_uuid"]: list of all teams subscribed or list of all users subscribed to a team
- /unsubscribe ["team_uuid"]: unsubscribe from a team
- /use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"]: defines the context of the command to a team/channel/discussion.
- /create : depending on the context, creates the sub-resource (see below)
- /list : depending on the context, lists all sub-resources (see below).
- /info : depending on the context, displays details of the current resource (see below).



**This is how the client connects to the server:**

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/980f7648-9dce-4e26-824c-e96df78740f9)


### Client operation

The client connects to the server via an IP and a port.

The user must first log in.

Once this is done, the user can send commands.

## Server

The server is capable of managing several clients at the same time, using the select function to manage commands.
When the server is stopped, it saves its internal information in the current folder.
When the server starts, it checks whether the backup file exists and loads it if so.

**The server is initialized as follows:**

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/79f46fdd-1519-42ac-8d38-b46185c6eea4)

### Server operation

The server receives commands from the client, and takes care of executing the necessary actions (if a team is created, a channel is created, etc.).

Manage the **database**, which is made up of the team list, the user list and the private message list.

The database is laid out like this:

![image](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-thibaud.cathala/assets/114945623/03cc2444-25d4-4d82-a169-bfe04859938e)

## Logger

Events and data are printed using the "libmyteams.so" log lib.
There are many functions to call for both the server and the client.

### 1. For the client logger :

Functions whose name contains **"event "** are called when you receive something from the server, when it's not you who initiated the action.
Other functions are called in response to one of your actions.

I received a private message (I didn't do anything about it), so the function to call is the one whose name contains "event".

I asked the server to join a team (I initiated this action). The function to call is one that doesn't have event in its name.

**Example 1:**
A user logs on to the server with the login command. I call the function **"client_event_logged_in "** with:

- user_uuid The identifier of the user who logged in
- user_name The name of the user who logged in

```c++
int client_event_logged_in(char const *user_uuid, const char *user_name);
```

**Example 2:**
A logged-in user receives a private message with the send command, I call the **"client_event_private_message_received "** function with:
- user_uuid The identifier of the user who sent the private message
- message_body The body of the private message

```c++
int client_event_private_message_received(
    char const *user_uuid,
    char const *message_body);
```

### 2. For the server logger :

Since the server never initializes an action, all functions are called events.

**Example 1:**

The server has created a new team, so I call the function **"server_event_team_created "** with:
- team_uuid The identifier of the team that has been created
- team_name The name of the team that has been created
- user_uuid The identifier of the user who created the new team

```c++
int server_event_team_created(
    char const *team_uuid,
    char const *team_name,
    char const *user_uuid);
```

**Example 2:**

The server has created a new channel, so I call the function **"server_event_channel_created "** with:

- team_uuid The id of the team in which this channel is located
- channel_uuid The id of the created channel
- channel_name The name of the new channel

```c++
int server_event_channel_created(
    char const *team_uuid,
    char const *channel_uuid,
    char const *channel_name);
```
