#include "monty.h"

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
	char *line = NULL, *token = NULL, *store = NULL;
	size_t len = 0;

	line = malloc(sizeof(char) * 3);
	if (!line)
	{
		free(line);
		return (0);
	}

	while ((getline(&line, &len, fp)) != -1)
	{
		token = strtok(line, DELIMS);
		if (!token)
			return (0);

		store = malloc(sizeof(char **) * 3);
		if (!store)
		{
			fprintf(stderr, "Error: malloc failed"), free(line);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(fp);
	return (0);
}


/**
 *
 *
 *
 *
 */
/*
char _token(char *line)
{
	char *token = NULL, *store = NULL;

	token = strtok(line, DELIMS);
	if (!token)
		return (NULL);

	store = malloc(sizeof(char **) * 3);
	if (!store)
	{
		fprintf(stderr, "Error: malloc failed");
		free(line);
		exit(EXIT_FAILURE);
	}

	while (token)
	{
		token = strtok(NULL, DELIMS);
	}
	return (store);
}
*/
