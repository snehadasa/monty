#include "monty.h"

/**
 * get_op - selects correct function for format
 * @s: input format identifier
 *
 * Return: pointer to matching function
 */
int *get_op(const char *s)
{
	instruction_t function[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	int i = 0;

	while (function[i].opcode)
	{
		if (!strcmp(s, function[i].opcode))
			break;
		i++;
	}

	return (function[i].f);
}
