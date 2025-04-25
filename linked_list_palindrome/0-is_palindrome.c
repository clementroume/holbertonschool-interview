#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the linked list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head;
	listint_t *prev = NULL, *temp;

	if (!head || !*head) // Empty list or NULL pointer is considered a palindrome
		return (1);

	/* Reverse the first half of the list while finding the middle using slow/fast pointers */
	while (fast && fast->next)
	{
		fast = fast->next->next; // Fast moves two steps at a time
		temp = slow->next;		 // Save next node
		slow->next = prev;		 // Reverse current node
		prev = slow;			 // Move prev forward
		slow = temp;			 // Move slow forward
	}

	if (fast) // If the list has an odd number of nodes, skip the middle one
		slow = slow->next;

	/* Compare the reversed first half with the second half */
	while (prev && slow)
	{
		if (prev->n != slow->n) // If mismatch found, not a palindrome
			return (0);
		prev = prev->next;
		slow = slow->next;
	}

	/* If all values matched, it's a palindrome */
	return (1);
}
