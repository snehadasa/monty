#include "monty.h"

/**
 * pint - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		return;
	}

	 printf("%d\n", current->n);
}
