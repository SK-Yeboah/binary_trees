#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_levelorder_recursive(tree, func);
}

/**
 * binary_tree_levelorder_recursive - Recursively goes through a binary tree
 * using level-order traversal
 * @tree: Pointer to the current node in the traversal
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder_recursive(const binary_tree_t *tree, void (*func)(int))
{
    int level = binary_tree_height(tree);

    for (int i = 1; i <= level; i++)
        print_given_level(tree, func, i);
}

/**
 * print_given_level - Prints nodes at a given level of the binary tree
 * @tree: Pointer to the current node in the traversal
 * @func: Pointer to a function to call for each node
 * @level: Level of the tree to print
 */
void print_given_level(const binary_tree_t *tree, void (*func)(int), int level)
{
    if (tree == NULL)
        return;
    if (level == 1)
        func(tree->n);
    else if (level > 1)
    {
        print_given_level(tree->left, func, level - 1);
        print_given_level(tree->right, func, level - 1);
    }
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if tree is NULL
 */
int binary_tree_height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}
