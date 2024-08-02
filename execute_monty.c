#include "monty.h"

void (execute(char *file_name))
{
	FILE *file = fopen(file_name, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode;
	int value = atoi(arg);

	if (file == NULL)
	{
		fprint(stderr, "Error: can't open file %s\n, file_name");
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcomp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \n\t");
			if (arg == NULL || !isdigit(*arg))
			{
				fprint(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, line_number, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprint(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);
}
