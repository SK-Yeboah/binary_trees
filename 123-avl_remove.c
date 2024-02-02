#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    /* Perform standard BST delete */
    if (value < root->n)
    {
        root->left = avl_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = avl_remove(root->right, value);
    }
    else
    {
        /* Node with only one child or no child */
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;

            /* No child case */
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else /* One child case */
            {
                *root = *temp; /* Copy the contents of the non-empty child */
            }
            free(temp);
        }
        else
        {
            /* Node with two children: Get the in-order successor (smallest
               in the right subtree) */
            avl_t *temp = root->right;
            while (temp && temp->left != NULL)
                temp = temp->left;

            /* Copy the in-order successor's content to this node */
            root->n = temp->n;

            /* Delete the in-order successor */
            root->right = avl_remove(root->right, temp->n);
        }
    }

    /* If the tree had only one node then return */
    if (root == NULL)
        return root;

    /* Update height of the current node */
    root->height = 1 + max(binary_tree_height(root->left), binary_tree_height(root->right));

    /* Get balance factor and perform rotations if needed */
    int balance = binary_tree_balance(root);

    /* Left-Left case (LL) */
    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return binary_tree_rotate_right(root);

    /* Left-Right case (LR) */
    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return binary_tree_rotate_right(root);
    }

    /* Right-Right case (RR) */
    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return binary_tree_rotate_left(root);

    /* Right-Left case (RL) */
    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return binary_tree_rotate_left(root);
    }

    return root;
}
