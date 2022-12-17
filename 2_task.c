#include "monty.h"

/**
 *
 *
 *
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (**stack != NULL)
	{
		if ((**stack)->next == NULL)
			**stack = NULL;
		else
		{
			struct stack_t temp = **stack;
			while(temp->temp->next->next != NULL)
				temp = temp->next;

			struct stack_t last_node = temp->next;
			temp->next = NULL;
			free(last_node);
		}
	}
}

