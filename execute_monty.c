#include "monty.h"

/**
 *
 */

int is_integer(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}

	if (*str == '\0') // Check if there are digits after +/-
	{
		return 0;
	}

	while (*str)
	{
		if (!isdigit(*str))
		{
			return 0;
		}
		str++;
	}

	return 1;
}

void(execute(char *file_name))
{
	FILE *file = fopen(file_name, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode;
	char *arg = NULL;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \n\t");
			if (arg == NULL || !isdigit(*arg))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			int value = atoi(arg);
			push(&stack, line_number, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);
}
