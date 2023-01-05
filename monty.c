#include "monty.h"

static instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", NULL},
		{NULL, NULL}
	};

/**
 * ops - select the operations.
 * @tokens: first member
 * @stack: second member
 *
 * Return: void.
 */
void ops(char **tokens, stack_t **stack)
{
	int i = 0;

	while (operations[i].opcode)
	{
		if (tokens[0][0] == '#')
			return;
		if (strcmp(tokens[0], operations[i].opcode) == 0)
		{
			if (operations[i].f)
				operations[i].f(stack, line_number);
			break;
		}
		i++;
	}

	if (strcmp(tokens[0], "push") == 0)
	{
		(*stack)->n = atoi(tokens[1]);
	}
	else if (!(operations[i].opcode))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number,
				tokens[0]);
		exit(EXIT_FAILURE);
	}
}

unsigned int line_number = 0;

/**
 * main - control program flow
 * @argc: argument count
 * @argv: argument list
 * Return: Nothing
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp = fopen(argv[1], "r+");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	char *token = NULL, **tokens = NULL, *line = NULL, **store;
	char *delim = " \t\r\n\a";
	stack_t *head = NULL; /* pointer to top of stack */
	size_t len;
	int idx = 3;
	ssize_t chars;

	while ((chars = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		token = strtok(line, delim);
		if (token == NULL)
		{
			free(token);
			return (0);
		}
		store = malloc(sizeof(char **) * chars);
		if (store == NULL)
		{
			fprintf(stderr, "Error: malloc failed"), free(line);
			exit(EXIT_FAILURE);
		}
		while (--idx)
			store[idx - 1] = NULL;
		while (token)
		{
			if (idx < 3)
				store[idx] = token;
			token = strtok(NULL, delim), idx++;
		}
		store[2] = NULL;
		tokens = store;
		if (tokens)
		{
			ops(tokens, &head);
			free(token);
			free(store);
		}
	}
	free(line), frees(&head), fclose(fp);
	return (0);
}

/**
 * frees - free the stack
 * @stack: ptr to stack
 * Return: Nothing
 */

void frees(stack_t **stack)
{
	stack_t *head = *stack;

	while (head)
	{
		if (!head->next)
		{
			free(head);
			break;
		}
		head = head->next;
		free(head->prev);
	}
}
