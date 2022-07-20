#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	/** +1 to get the height of the tree recursivly **/
	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;
	return ((left_height > right_height) ? left_height : right_height);
}
/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: a pointer to the node to check
 * Return: If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	else
		return (1);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *pleft, *pright;

	if (tree == NULL)
	{
		return (0);
	}
	pleft = tree->left;
	pright = tree->right;
	if (binary_tree_is_leaf(tree))
	{
		return (1);
	}
	if (binary_tree_height(pleft) == binary_tree_height(pright))
	{
		if (binary_tree_is_perfect(pleft) && binary_tree_is_perfect(pright))
		{
			return (1);
		}
	}
	return (0);
}
