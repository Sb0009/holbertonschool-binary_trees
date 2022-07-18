#include "binary_trees.h"
#include <stdlib.h>

/**
 *void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int)) /
 -goes through a binary tree using inorder traversal
 *@tree: a pointer to the root node of the tree to traverse
 *@func: a pointer to a function to call for each node
 *Return: nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || (*func) == NULL)
    {
        return;
    }
    (func)(tree->n);
    binary_tree_inorder(tree->left, (*func));
    binary_tree_inorder(tree->right, (*func));
}
