#include "monty.h"
#include <unistd.h>
#include <fcntl.h>

int n;

/**
 * get_op - selects correct function for format
 * @s: input format identifier
 *
 * Return: pointer to matching function
 */
void (*get_op(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t function[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
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

/**
 * free_stack - free stack.
 * @stack: head of the linked list.
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	stack = NULL;
}

int main(int ac, char **av)
{
	FILE *file;
	char *buffer = NULL;
	size_t bufsize = 0;
	int gl_status, line_number = 0;
	char *opcode = NULL, *n_str = NULL;
	stack_t *top = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (access(av[1], R_OK))
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	while (1)
	{
		line_number++;
		gl_status = getline(&buffer, &bufsize, file);
		if (gl_status == EOF)
			break;
		opcode = strtok(buffer, " \t\n");
		if (!strcmp(opcode, "nop"))
			continue;
		if (get_op(opcode))
		{
			n_str = strtok(NULL, " \t\n");
			if (n_str)
				n = atoi(n_str);
			get_op(opcode)(&top, line_number);
		}
		else
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
			return (EXIT_FAILURE);
		}
	}
	if (buffer)
		free(buffer);
	free_stack(top);
	fclose(file);
	return (0);
}
