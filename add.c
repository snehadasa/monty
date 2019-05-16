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
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n  ((*stack)->next)->n;

	((*stack)->next)->n = sum;

	free(*stack);

	pop(stack, line_number);
}