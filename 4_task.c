#include "monty.h"

/**
 * add - add elements on the stack
 * @stack: 
 * @line_number: 
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L %u: can't aad, stack too short\n",
			line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

