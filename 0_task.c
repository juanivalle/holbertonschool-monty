#include "monty.h"

/**
 * push - add node
 * @stack: head of list
 * @line_number: line number.
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (!stack)
		return;

	if ()
	{
	printf("L%d: usage: push integer");
	exit(EXIT_FAILURE);
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

