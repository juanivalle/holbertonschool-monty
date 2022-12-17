#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number of the swap instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	temp = first->n;
	first->n = second->n;
	second->n = temp;
}

