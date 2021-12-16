#include "lists.h"
/**
 * insert_node - function that inserts a number into a
 * sorted singly linked list.
 * @head: pointer to head of list
 * @number: the number to insert
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *aux;
	listint_t *tmp;
	/* Create the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	/* edge cases */
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (*head);
	}
	/* Case 1: insert at the beginning: number < *head->n */
	if ((*head)->n > number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	/* the rest of the cases */
	tmp = *head;

	while (tmp->next != NULL && tmp->next->n <= number)
		tmp = tmp->next;

	aux = tmp->next;
	tmp->next = new_node;
	new_node->next = aux;
	return (new_node);
}
