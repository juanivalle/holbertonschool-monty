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
	ssize_t read;

	line = malloc(sizeof(char) * 10000);

	if (!line)
	{
		free(line);
		return (0);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
/*		line_number++;*/
		token = strtok(line, DELIMS);
		if (!token)
			return (EXIT_FAILURE);

		store = malloc(sizeof(char **) * len);
		if (!store)
		{
			fprintf(stderr, "Error: malloc failed");
			free(line);
			exit(EXIT_FAILURE);
		}
		
		free(line);
		return (EXIT_SUCCESS);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}

