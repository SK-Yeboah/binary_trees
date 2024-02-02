#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as t he left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: value stored in the new node
 * Return: Pointer to the created node, or NULL on failure 
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    /*Allocate memory for the new node*/
    new_node =malloc(sizeof(binary_tree_t));
    
    if (new_node == NULL)
        return (NULL);
    
    /*initialize the new node */
    new_node -> n = value;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> parent = parent;

    /*if the parent already has a left child, set new_node as the left child 
     * and set the old left child as the left of the new node*/
    if(parent->left != NULL)
    {
        new_node -> left =   parent -> left;
        new_node -> left -> parent = new_node;
    }

    /* Set new_node as the left child of the parent*/
    parent -> left = new_node;

    return (new_node);

    

}