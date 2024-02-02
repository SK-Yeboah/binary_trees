#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current, *parent;

    if (tree == NULL)
        return (NULL);

    /* If the tree is empty, create a new node as the root */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    current = *tree;
    parent = NULL;

    /* Find the appropriate position to insert the new node */
    while (current != NULL)
    {
        if (value == current->n)
            return (NULL); /* Value already exists, ignore */

        parent = current;

        if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }

    /* Create the new node */
    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* Insert the new node as left or right child of the parent */
    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    return (new_node);
}
