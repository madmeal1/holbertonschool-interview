#include <stdlib.h>
#include "lists.h"

/**
* insert_node - inserts a new node in a sorted singly linked list
* @head: double pointer to the head of the list
* @number: number to insert in the new node
*
* Return: address of the new node, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new, *current;

new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);

new->n = number;
new->next = NULL;

/* Cas 1 : insertion en tête ou liste vide */
if (*head == NULL || number < (*head)->n)
{
new->next = *head;
*head = new;
return (new);
}

/* Cas 2 : insertion au milieu ou à la fin */
current = *head;
while (current->next != NULL && current->next->n < number)
current = current->next;

new->next = current->next;
current->next = new;

return (new);
}
