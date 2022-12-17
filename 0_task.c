#include "monty.h"

/**
 * push - add node
 * @stack: head of list
 * @line_number: line number.
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t temp;
	stack_t new_node;

	new_node = malloc(sizeof(stack_t **stack));
	new_node->data = line_number;
	new_node->next = NULL;

	if (**stack == NULL)
	{
		**stack = new_node;
		printf("L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = **stack;
		while (temp->next != NULL)
		{
			temp->next = temp;
		}
		temp->next = new_node;
	}
}

/**
 * pall - print nodes
 * @stack: head of list
 * @line_number: line number.
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}

}

