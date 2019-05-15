#include "monty.h"

/**
 * sub - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void sub(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int minus = 0;

	if (!(*stack) && (*stack)->next != NULL)
		return;

	minus = -((*stack)->n - ((*stack)->next)->n);

	((*stack)->next)->n = minus;

	pop(stack, line_number);
}
