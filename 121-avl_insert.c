#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return NULL;

    /* Perform standard BST insert */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (*tree == NULL)
            return NULL;
        return *tree;
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
    }
    else
    {
        /* Duplicate values are not allowed */
        return NULL;
    }

    /* Update height of the current node */
    /* Here, we compute the height dynamically */
    int left_height = binary_tree_height((*tree)->left);
    int right_height = binary_tree_height((*tree)->right);
    (*tree)->height = 1 + (left_height > right_height ? left_height : right_height);

    /* Get balance factor and perform rotations if needed */
    int balance = binary_tree_balance(*tree);

    /* Left-Left case (LL) */
    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);

    /* Right-Right case (RR) */
    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);

    /* Left-Right case (LR) */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }

    /* Right-Left case (RL) */
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }

    return *tree;
}
