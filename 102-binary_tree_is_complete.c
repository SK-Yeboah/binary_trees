#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_complete_recursive(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete_recursive - Checks if a binary tree is complete recursively
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @nodes: Total number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, size_t index, size_t nodes)
{
    if (tree == NULL)
        return (1);

    if (index >= nodes)
        return (0);

    return (is_complete_recursive(tree->left, 2 * index + 1, nodes) &&
            is_complete_recursive(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the binary tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
