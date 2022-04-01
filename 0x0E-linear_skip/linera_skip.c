#include <stdlib.h>
#include "search.h"

/**
 * init_express - Initializes the express lane of the linked list
 *
 * @list: pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return:  pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node;
	int start_inter = 0;
	int end_inter = 0;

	if (list == NULL || list->next == NULL)
	{
		return NULL;
	}

	node = list;
	if (node->n == value)
	{
		printf("test0 node->n : %i value!!", node->n);
		return (node);
	}

	start_inter = node->n;
	while(node!= NULL)
	{
		if (node->n == value)
		{
			printf("test1");
			return node;
		}
		if (node->express)
			end_inter = node->express->n;
		else if (node->next)
		{
			node = node->next;
			printf("Value checked at index [%li] = [%i]\n",  node->index, node->n);
			if (node->n == value)
				return node;
			else
				continue;
		}
		else
			return NULL;

		if (value > start_inter && value < end_inter)
		{

			printf("Value found between indexes [%li] and [%li]\n", node->index, node->express->index);
			node = node->next;
		}


		if (node->express)
		{
			node = node->express;
			start_inter = node->n;
			printf("Value checked at index [%li] = [%i]\n",  node->index, node->n);

		}
	}
	return NULL;
}
