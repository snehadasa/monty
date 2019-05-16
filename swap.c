#include "monty.h"

/**
 * swap - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void swap(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	unsigned int temp;

	if (!(*stack) || !(*stack)->next || !stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		free(globals.buffer);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
