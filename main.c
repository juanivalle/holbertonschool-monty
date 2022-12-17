#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monty.h"

stack_t **full_start;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1)
    {
        printf("%s", line);
    }

    free(line);
    fclose(fp);
    return EXIT_SUCCESS;
}
