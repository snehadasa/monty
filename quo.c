#include "monty.h"

/**
 * div - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void quo(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int quo_d = 0;

	if (!(*stack) && (*stack)->next != NULL)
		return;

	quo_d = (*stack)->n / ((*stack)->next)->n;

	((*stack)->next)->n = quo_d;

	pop(stack, line_number);
}
