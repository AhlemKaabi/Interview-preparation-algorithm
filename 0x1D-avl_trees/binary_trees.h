#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <limits.h>
/**
 * struct binary_tree_s - binary tree node
 *
 * @n: Integer
 * @parent: Pointer
 * @left: Pointer
 * @right: Pointer
 */
struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *);
int binary_tree_is_avl(const binary_tree_t *tree);
#endif
