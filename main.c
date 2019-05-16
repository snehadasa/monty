#include "monty.h"
#include <unistd.h>
#include <fcntl.h>

int n = 0;

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
		{"nop", NULL},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		/*{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},*/
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

FILE *open_file(int aycee, char *av_one)
{
	FILE *file;

	if (aycee != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av_one, "r");
	if (!file)
	{
		fprintf(stderr, "Can't open file %s\n", av_one);
		exit(EXIT_FAILURE);
	}
	return (file);
}

int main(int ac, char **av)
{
	FILE *file;
	char *buffer = NULL;
	size_t bufsize = 0;
	int gl_status;
	char *opcode = NULL, *n_str = NULL;
	int line_number = 0;
	stack_t *top = NULL;

	file = open_file(ac, av[1]);

	while (1)
	{
		line_number++;
		gl_status = getline(&buffer, &bufsize, file);
		if (gl_status == EOF)
		{
			free(buffer);
			buffer = NULL;
			break;
		}
		opcode = strtok(buffer, " \t\n");
		/*printf("opcode: %s\n", opcode);*/
		if (get_op(opcode))
		{
			if (opcode)
			{
				n_str = strtok(NULL, " \t\n");
				if (n_str)
					n = atoi(n_str);
				else
					n = line_number;
			}
			get_op(opcode)(&top, n);
		}
	}
	if (buffer)
		free(buffer);
	free_stack(top);
	fclose(file);
	return (0);
}

