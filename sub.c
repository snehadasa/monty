#include "monty.h"

/**
 * sub - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int minus = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	minus = -((*stack)->n - ((*stack)->next)->n);

	((*stack)->next)->n = minus;

	free(*stack);

	pop(stack, line_number);
}
