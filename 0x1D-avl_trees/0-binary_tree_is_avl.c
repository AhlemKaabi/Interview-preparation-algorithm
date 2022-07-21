#include "binary_trees.h"

/**
 * is_valid_avl - tree is a valid avl
 * @tree: head
 * @min: minimun
 * @max: maximun
 * @height: height
 * Return: 1 ir 0
 */
int is_valid_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int h1 = 0, h2 = 0, avl1, avl2;

	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	avl1 = is_valid_avl(tree->left, min, tree->n, &h1);
	avl2 = is_valid_avl(tree->right, tree->n, max, &h2);
	if (avl1 == 0 || avl2 == 0)
		return (0);
	if (h1 > h2)
		*height = h1 + 1;
	else
		*height = h2 + 1;
	if (abs(h1 - h2) > 1)
		return (0);
	return (1);
}
/**
 * binary_tree_is_avl - tree is a valid AVL tree
 * @tree: head
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);
	return (is_valid_avl(tree, INT_MIN, INT_MAX, &height));
}
