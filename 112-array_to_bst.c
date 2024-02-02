#include "binary_trees.h"
#include <stdlib.h>

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (array_to_bst_helper(array, 0, size - 1, NULL));
}

/**
 * array_to_bst_helper - Helper function to build a BST from an array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to the parent node
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst_helper(int *array, size_t start, size_t end, bst_t *parent)
{
    size_t mid;
    bst_t *root;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    /* Create the root node */
    root = binary_tree_node(parent, array[mid]);
    if (root == NULL)
        return (NULL);

    /* Recursively construct the left and right subtrees */
    root->left = array_to_bst_helper(array, start, mid - 1, root);
    root->right = array_to_bst_helper(array, mid + 1, end, root);

    return (root);
}
