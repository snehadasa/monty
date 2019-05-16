#include "monty.h"

void add(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int to_add = (*stack)->n;

	(*stack)->next->n += to_add;
	pop(stack, line_number);
}
