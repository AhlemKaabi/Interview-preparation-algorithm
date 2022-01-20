#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lists.h"
/**
 * length_list - count the length of a linked list
 * @head: pointer to pointer of first node of listint_t list
 * Return: lenght
 */
int length_list(listint_t **head)
{
	listint_t *current;
	int length = 1;

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
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int j, i = 0, length = 1;
	bool pair;

	if (*head == NULL)
		return (0);
	length = length_list(head);
	pair = is_pair(length);
	int intarray[length / 2];

	current = *head;
	j = 0;
	while (current->next != NULL)
	{
		if (j < i)
		{
			intarray[j] = current->n;
			current = current->next;
			j++;
			continue; }
		break; }
	while (current->next != NULL)
	{
		if (pair)
		{
			if (intarray[j - 1] == current->n)
			{
				current = current->next;
				j--;
				continue; }
			else
				return (0); }
		if (!pair)
		{
			current = current->next;
			j--;
			if (intarray[j] == current->n)
				continue;
			else
				return (0); }
	}
	if (pair)
		if (current->n == intarray[j - 1])
			return (1);
	return (1);
}
