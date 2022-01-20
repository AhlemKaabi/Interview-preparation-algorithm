#include "lists.h"
/**
 * length_list - count the length of a linked list
 * @head: pointer to pointer of first node of listint_t list
 * Return: lenght
 */
int length_list(listint_t **head)
{
	listint_t *current;
	int length;

	length = 1;
	current = *head;
	while (current->next != NULL)
	{
		length++;
		current = current->next;
	}
	return (length);
}
/**
 * is_pair - check if the length is pair
 * @length: length of a linked list
 * Return:  true if it is pair, false otherwise
 */
bool is_pair(int length)
{
	if (length % 2 == 0)
		return (true);
	else
		return (false);
}
/**
 * check - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * @length: length of a linked list
 * @pair: length pair or not
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int check(listint_t **head, int length, bool pair)
{
	listint_t *current;
	int j = 0, i = 0;
	int *array;

	current = *head;
	i = length / 2;
	array = malloc(i * sizeof(int));
	while (current->next != NULL)
	{
		if (j < i)
		{
			array[j] = current->n;
			current = current->next;
			j++;
			continue; }
		break; }
	while (current->next != NULL)
	{
		if (!pair)
		{
			current = current->next;
			j--;
		}
		else
			j--;
		if (array[j] == current->n)
		{
			if (pair)
				current = current->next;
			continue;
		}
		else
		{
			free(array);
			return (0);
		}
	}
	free(array);
	return (1);
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int length = 1;
	bool pair;

	if (*head == NULL)
		return (0);
	length = length_list(head);
	pair = is_pair(length);


	return (check(head, length, pair));
}
