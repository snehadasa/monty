#include "monty.h"


/**
 * pop - delete node at given index.
 * @stack: head of the doubly linked list.
 * @line_number: line number.
 * Return: void.
 */
void pop(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *delete_node = NULL;

	if (!stack || (*stack == NULL))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		free(globals.buffer);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

		delete_node = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;

		free(delete_node);
}
