#include "monty.h"

/**
 * add - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		free(globals.buffer);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + ((*stack)->next)->n;

	((*stack)->next)->n = sum;

	pop(stack, line_number);
}
