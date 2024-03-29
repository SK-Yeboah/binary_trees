#include "binary_trees.h"

/**
 * is_bst_util - Utility function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @prev: Pointer to the previously visited node
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, const binary_tree_t *prev)
{
    if (tree == NULL)
        return (1);

    /* Check left subtree */
    if (!is_bst_util(tree->left, prev))
        return (0);

    /* Current node's value must be greater than the previous visited node's value */
    if (prev != NULL && tree->n <= prev->n)
        return (0);

    /* Update the previous visited node */
    prev = tree;

    /* Check right subtree */
    return (is_bst_util(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_bst_util(tree, NULL));
}
