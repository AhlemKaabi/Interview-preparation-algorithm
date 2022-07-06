#include "sort.h"
/**
 * current_digit_sort - sort by current digit
 * @array: array
 * @size: size of the array
 * @tmp: temporary array
 * @exp: exponential
 * Return: array
 */
int current_digit_sort(int *array, size_t size, int *tmp, long exp)
{
	size_t i, j, x;
	int aux[10] = {0};

	for (i = 0; i < size; i++)
		aux[(array[i] / exp) % 10]++, tmp[i] = 0;
	for (j = 1; j < 10; j++)
		aux[j] += aux[j - 1];
	for (j = size - 1; j >= 0; j--)
		tmp[--aux[(array[j] / exp) % 10]] = array[j];
	for (x = 0; x < size; x++)
		array[x] = tmp[x];
	return (0);
}
/**
 * radix_sort - RADIX sort function
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	long exp = 1;
	int *temp, max = INT_MIN;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int *) * size);
	if (!temp)
		return;

	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;

	while (max / exp > 0)
	{
		current_digit_sort(array, size, temp, exp);
		print_array(array, size);
		exp *= 10;
	}
	free(temp);
}