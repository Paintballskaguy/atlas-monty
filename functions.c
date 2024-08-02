#include "monty.h"

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
	stack_t *stack = NULL;

	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprint(stderr, "Error, Error, malloc bad\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack).prev = new_node;

	*stack = new_node;
}


/**
 * 
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}
