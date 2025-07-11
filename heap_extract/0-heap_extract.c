#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root of the tree.
 * Return: The size of the tree, or 0 if tree is NULL.
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * find_last_node - Finds the last level-order node in a heap.
 * @root: Pointer to the root.
 * @index: Index of the current node in the traversal.
 * @size: Total size of the heap.
 * Return: Pointer to the last node.
 */
heap_t *find_last_node(heap_t *root, size_t index, size_t size)
{
	if (!root)
		return (NULL);

	if (index == size)
		return (root);

	heap_t *left = find_last_node(root->left, 2 * index + 1, size);
	if (left)
		return (left);

	return (find_last_node(root->right, 2 * index + 2, size));
}

/**
 * sift_down - Repairs the heap by sifting down the root node.
 * @root: Double pointer to the root of the heap.
 */
void sift_down(heap_t **root)
{
	heap_t *node = *root, *child;
	int temp;

	while (node->left)
	{
		child = node->left;
		if (node->right && node->right->n > child->n)
			child = node->right;

		if (node->n >= child->n)
			break;

		temp = node->n;
		node->n = child->n;
		child->n = temp;

		node = child;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root of the heap.
 * Return: The value of the extracted node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node, *old_root;
	size_t size;

	if (!root || !*root)
		return (0);

	old_root = *root;
	extracted_value = old_root->n;
	size = tree_size(old_root);

	if (size == 1)
	{
		free(old_root);
		*root = NULL;
		return (extracted_value);
	}

	last_node = find_last_node(old_root, 0, size - 1);

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	last_node->parent = NULL;

	last_node->left = old_root->left;
	last_node->right = old_root->right;

	if (old_root->left)
		old_root->left->parent = last_node;
	if (old_root->right)
		old_root->right->parent = last_node;

	*root = last_node;
	free(old_root);

	sift_down(root);

	return (extracted_value);
}
