#include "monty.h"

/**
 * rem - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void rem(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int result = 0;

	if (!(*stack) && (*stack)->next != NULL)
		return;

	result = (*stack)->n % ((*stack)->next)->n;

	((*stack)->next)->n = result;

	pop(stack, line_number);
}
