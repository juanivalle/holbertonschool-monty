#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number of the swap instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;
	(void) line_number;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		if (*stack)
			frees(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}

