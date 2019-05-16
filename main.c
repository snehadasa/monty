#include "monty.h"
#include <unistd.h>
#include <fcntl.h>

globals_t globals;

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

/**
 * check_args - checks arguments
 * @ac: number of input arguments
 * @file: input file
 * Return: void
 */
void check_args(int ac, char *file)
{
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(file, R_OK))
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - main function
 * @ac: number of input arguments
 * @av: array of arguments
 * Return: 0 if success, 1 if failure
 */
int main(int ac, char **av)
{
	/*FILE *file;*/
	/*char *buffer = NULL;*/
	size_t bufsize = 0;
	int gl_status, line_number = 0;
	char *opcode = NULL;
	stack_t *top = NULL;

	check_args(ac, av[1]);
	globals.file = fopen(av[1], "r");
	while (1)
	{
		line_number++;
		gl_status = getline(&(globals.buffer), &bufsize, globals.file);
		if (gl_status == EOF)
			break;
		opcode = strtok(globals.buffer, " \t\n");
		if (!strcmp(opcode, "nop"))
			continue;
		if (get_op(opcode))
		{
			globals.n_str = strtok(NULL, " \t\n");
			get_op(opcode)(&top, line_number);
		}
		else
		{
			dprintf(
			STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
			free(globals.buffer);
			free_stack(top);
			fclose(globals.file);
			return (EXIT_FAILURE);
		}
	}
	if (globals.buffer)
		free(globals.buffer);
	free_stack(top);
	fclose(globals.file);
	return (0);
}
