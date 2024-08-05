#include "monty.h"

/**
 * 
 *
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execute(argv[1]);

	return (0);
}