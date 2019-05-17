#include "monty.h"

/**
 * pint - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		free(globals.buffer);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	printf("%d\n", current->n);
}
