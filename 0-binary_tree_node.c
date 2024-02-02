#include "binary_trees.h"


/**
 * binary_tree_node - Create a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 * Return: Pointer to the newnode, or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /*Allocate memory for the new node*/
    new_node = malloc(sizeof(binary_tree_t));

    if (new_node == NULL)
    {
        return (NULL);
    }

    /*initialize the new node*/
    new_node -> n = value;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> parent = parent;

    return (new_node);
}