#include "monty.h"

static instructions_t instruction_s[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", NULL},
	{NULL, NULL},
};

/**
 * opcode - comparison of the token with the operation functions.
 * @stack:
 * @line_number:
 *
 */
void get_opcode(char **token, stack_t **stack)
{
	int index = 0;

	while (instruction_s[index].opcode)
	{
		if (strcmp(token[0], instruction_s[index].opcode) == 0)
		{
			if (instruction_s[index].f)
				instruction_s[index].f(stack, line_number);
			break;
		}
		index++;
	}

	if (!(instruction_s[index].opcode))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, token[0]);
		exit(EXIT_FAILURE);
	}
}

