#include "monty.h"

/**
 * pint - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	 printf("%d\n", current->n);
}
