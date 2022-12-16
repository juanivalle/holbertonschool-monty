#include "lists.h"

/**
 * add_nodeint_end - Short description.
 * @head: first member.
 * @n: second member.
 *
 * Return: new_node.
 */

void add_node_end(struct stack_s, int n)
{
	struct stack_s *new_node, *temp;

	new_node = malloc(sizeof(struct stack_s));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*stack_s == NULL)
		*stack_s = new_node;
	else
	{
		temp = *stack_s;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

