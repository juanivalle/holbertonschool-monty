#include "monty.h"

stack_t **full_start;

/**
 * main - entry point.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	char *line = NULL; /**token = NULL*/
	size_t len = 0;
	ssize_t read;

	line = malloc(sizeof(char) * 10000);

	if (!line)
	{
		free(line);
		return (0);
	}
/*	token = strtok(line, DELIMS);*/

	while ((read = getline(&line, &len, fp)) != -1)
	{
		free(line);
/*		printf("L %s: unknow instruction %s\n", line, token);*/
		return (EXIT_SUCCESS);
	}

	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
