/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_linkedlist
*/

#ifndef MY_LINKEDLIST_H_
    #define MY_LINKEDLIST_H_

    ////////////////////////////////////////////////////////////
    /// \brief Get the data of a given node
    ///
    ////////////////////////////////////////////////////////////
    #define GET_DATA(node, type) ((type *)(node)->data)

typedef struct node_t node_t;
struct node_t {
    void *data;
    node_t *next;
    node_t *prev;
};

////////////////////////////////////////////////////////////
/// \brief Create a node that point on a data
///
/// \param data The data on which the node will point
///
////////////////////////////////////////////////////////////
node_t *create_node(void *data);

////////////////////////////////////////////////////////////
/// \brief Append a node at the end of the list
///
/// \param head The head of the list
/// \param node The node to append
///
////////////////////////////////////////////////////////////
void append_node(node_t **head, node_t *node);

////////////////////////////////////////////////////////////
/// \brief Insert a node in the list
///
/// \param head The head of the list
/// \param prev_node The node that will be the previous of the node to insert
///                  (NULL if you want the node to be the new head of the list)
/// \param node The node to insert
///
////////////////////////////////////////////////////////////
void insert_node(node_t **head, node_t *prev_node, node_t *node);

////////////////////////////////////////////////////////////
/// \brief Remove a node from the list
///
/// \param head The head of the list
/// \param node The node to remove
///
/// \return The node that was removed
///
////////////////////////////////////////////////////////////
node_t *remove_node(node_t **head, node_t *node);

////////////////////////////////////////////////////////////
/// \brief Remove a node from the list, free it and his data
///
/// \param head The head of the list
/// \param node The node to delete
///
////////////////////////////////////////////////////////////
void delete_node(node_t **head, node_t *node);

////////////////////////////////////////////////////////////
/// \brief Free the list and the data of the list
///
/// \param head The head of the list
///
////////////////////////////////////////////////////////////
void free_linked_list(node_t **head);

////////////////////////////////////////////////////////////
/// \brief Compute the list len
///
/// \param head The head of the list
///
/// \return The list len
///
////////////////////////////////////////////////////////////
int my_listlen(const node_t *head);

////////////////////////////////////////////////////////////
/// \brief Remove a node from the list,
///        free it and his data with the given method
///
/// \param head   The head of the list
/// \param node   The node to delete
/// \param method A function to free the data of the node
///
////////////////////////////////////////////////////////////
void delete_node_wm(node_t **head, node_t *node, void (*method)(void *));

////////////////////////////////////////////////////////////
/// \brief Free the list and the data of the list with the given method
///
/// \param head   The head of the list
/// \param method A function to free the data of a node
///
////////////////////////////////////////////////////////////
void free_linked_list_wm(node_t **head, void (*method)(void *));

////////////////////////////////////////////////////////////
/// \brief Print the linked list data with the given method
///
/// \param head   The head of the list
/// \param method A function to print the data of a node
///
////////////////////////////////////////////////////////////
void print_linked_list_wm(const node_t *head, void (*method)(void *),
    char *end);

////////////////////////////////////////////////////////////
/// \brief For each node of the list call the method function
///
/// \param head   The head of the list
/// \param method A function that take the current node as arg
///
////////////////////////////////////////////////////////////
void for_each_node(node_t *head, void (*method)(node_t *));

#endif /* !MY_LINKEDLIST_H_ */
