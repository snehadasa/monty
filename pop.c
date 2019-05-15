#include "monty.h"


/**
 * pop - delete node at given index.
 * @head: head of the doubly linked list.
 * @index: index at which the node should be deleted.
 * Return: 1 if succeeded, -1 if failed.
 */
void pop(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *delete_node = *stack;
	unsigned int idx;

	if (!stack || (*stack == NULL))
		return;

	if (idx == 0)
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(delete_node);
		return;
	}
}
