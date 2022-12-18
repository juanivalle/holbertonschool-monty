#include "monty.h"

/**
 * opcode - comparison of the token with the operation functions.
 * @stack:
 * @line_number:
 *
 */
void _opcode(stack_t **stack, unsigned int line_number)
{
	_opcode_t _opcode_s[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};

	int index = 0;

	while (_opcode_s[i].f != NULL)
	{
		if (strcmp(token, _opcode_s[i].opcode) == 0)
			return (_opcode_s[i].f);
		index++;
	}
	return (NULL);
}

