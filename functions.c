#include "full_monty.h"

/**
 * 
 *
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}


/**
 * 
 *
 */

void push(**stack_t, unsigned int line_number, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprint(stderr, "Error, Error ")
	}
}