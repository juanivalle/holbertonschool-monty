#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @n: the line number of the pint instruction
 */
void pint(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

