#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL or if node has
 *         no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return (NULL);

    /* Determine if the parent of node is the left or right child of its parent */
    if (node->parent->parent->left == node->parent)
        return (node->parent->parent->right); /* Return the right child */
    else
        return (node->parent->parent->left);  /* Return the left child */
}
