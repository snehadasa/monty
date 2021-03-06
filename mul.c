#include "monty.h"

/**
 * mul - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n * ((*stack)->next)->n;

	((*stack)->next)->n = result;

	pop(stack, line_number);
}
