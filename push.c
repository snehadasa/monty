#include "monty.h"
#include <ctype.h>

/**
 * is_digit_string - Check if string is all digits
 * @s: String to check
 *
 * Return: 1 if string only has digits, 0 otherwise
 */
int is_digit_string(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (isalpha(s[i]))
			return (0);
	}
	return (1);
}

/**
 * push - to add the node at the beginning of the list.
 * @stack: head of the doubly linked list.
 * @line_number: number to be added.
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!globals.n_str || !is_digit_string(globals.n_str))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		free(globals.buffer);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->n = atoi(globals.n_str);

	temp->next = *stack;
	temp->prev = NULL;

	if (*stack)
		(*stack)->prev = temp;

	*stack = temp;
}

/**
 * pall - prints elements present in the list.
 * @stack: list to be printed
 * @line_number: the current pointing line
 * Return: elements in the list "h".
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
