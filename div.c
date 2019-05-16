#include "monty.h"

/**
 * _div - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next)->n / (*stack)->n;

	((*stack)->next)->n = result;

	free(*stack);

	pop(stack, line_number);
}
