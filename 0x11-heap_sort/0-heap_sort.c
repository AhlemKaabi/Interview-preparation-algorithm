# include "sort.h"
#include <math.h>

/**
 * swap_ - Swap between two elements in an array
 * @elem1: Pointer to element 1
 * @elem2: Pointer to the element 2
 */
void swap_(int *elem1, int *elem2)
{
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}
/**
 * heapify - Put elements of 'a' in heap order, in-place
 *
 * @array: input: an unordered array
 * @size: the length of the input array
 */
void heapify(int *array, size_t size)
{
	double iParent_size_i;
	int start;

	iParent_size_i = floor((((int)size - 1) - 1) / 2);
	start = (int)iParent_size_i;
	/**
	 * start is assigned the index in 'a' of the last parent node
	 * the last element in a 0-based array is at index count-1;
	 * find the parent of that element
	 */
	while (start > 0 || start == 0)
	{
		/**
		 * sift down the node at index 'start' to the proper place
		 * such that all nodes below the start index are in heap order
		 */
		siftDown(array, start, (int)size - 1, size);
		/**
		 * go to the next parent node
		 */
		start = start - 1;
		/**
		 * after sifting down the root all nodes/elements are in heap order
		 */
	}
}
/**
 * siftDown - Repair the heap whose root element is at index 'start',
 * assuming the heaps rooted at its children are valid.
 * @a: input: an unordered array
 * @start: root element index
 * @end: the last index of the array
 * @size: size of the array
 */
void siftDown(int *a, int start, int end, size_t size)
{
	int root, iLeftChild_root, child = 0, swap;

	root = start;
	/* While the root has at least one child */
	while ((2 * root + 1 < end) || (2 * root + 1 == end))
	{
		iLeftChild_root = 2 * root + 1;
		/* Left child of root */
		child = iLeftChild_root;
		/* Keeps track of child to swap with */
		swap = root;
		/* If there is a right child and that child is greater*/
		if (a[swap] < a[child])
			swap = child;
		if (((child + 1 < end) || (child + 1 == end)) && (a[swap] < a[child + 1]))
			swap = child + 1;
		/**
		 * The root holds the largest element.
		 * Since we assume the heaps rooted at the children are valid,
		 * this means that we are done.
		 */
		if (swap == root)
			return;
		swap_(&a[root], &a[swap]);
		print_array(a, size);
		/* repeat to continue sifting down the child now.*/
		root = swap;
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order.
 * @array: input: an unordered array
 * @size: the length of the input array
 */
void heap_sort(int *array, size_t size)
{
	int end;

	if (size == 0)
		return;
	/* Build the heap in array a so that largest value is *at the root* */
	heapify(array, size);

	/**
	 * The following loop maintains the invariants that a[0:end] is a heap
	 * and every element beyond end is greater than everything before it
	 * (so a[end:count] is in sorted order)
	 */
	end = (int)size - 1;
	while (end > 0)
	{
		/**
		 * a[0] is the root and largest value. The swap moves it in front
		 * of the sorted elements.
		 */
		swap_(&array[end], &array[0]);
		print_array(array, size);
		/* the heap size is reduced by one */
		end = end - 1;
		/* the swap ruined the heap property, so restore it */
		siftDown(array, 0, end, size);
	}
}
