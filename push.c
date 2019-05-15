#include "monty.h"

int n;

/**
 * push - to add the node at the beginning of the list.
 * @stack: head of the doubly linked list.
 * @line_number: number to be added.
 * Return: void.
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->n = n;

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

	if (current == NULL)
	{
		return;
	}

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
