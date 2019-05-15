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
                printf("L%u: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/*	if (!(*stack) || !(*stack)->next || !stack)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->prev = (*stack)->next;
	(*stack)->next = temp->next;

	temp->prev = NULL;

	if (temp->next)
		temp->next->prev = *stack;

	temp->next = *stack;

	*stack = temp;
}

	stack_t *temp;

	/*if (temp)
		temp->next = (*stack)->next;
	(*stack)->next->prev = temp;

	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next;
	(*stack)->next->next = (*stack);
	
	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;

	if (((*stack)->next)->next)
	{
		temp = (*stack)->next->next;
		(*stack)->next = temp;
		(*stack)->prev = temp->prev;
		(temp->prev)->prev = NULL;
		(temp->prev)->next = *stack;
		temp->prev = *stack;
		*stack = (*stack)->prev;
	}
	else if ((*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->prev = temp;
		(*stack)->next = NULL;
		temp->next = (*stack);
		temp->prev = NULL;
		(*stack) = temp;
	}
	else
	{
		printf("L%d: can't swap, stack too short", line_number);
	}
}*/
