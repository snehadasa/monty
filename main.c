/*Given a .m file...
Check if ac = 2
Check if file exists
Open file and assign it to an fd var
Use fgets to read the file*/

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
		{"sub", sub},
		{"quo", quo},
		{"product", product},
		{"rem", rem},
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

/*void free_stack(stack_t *stack)
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
}*/

int main(int ac, char **av)
{
	FILE *file;
	char **buffer = malloc(256);
	size_t bufsize = 256;
	int gl_status;
	char *opcode = NULL, *n_str = NULL;
	int line_number = 0;
	stack_t *top = NULL;

	if (ac != 2)
		printf("Wrong number of args, try again dipass\n");
	if (access(av[1], R_OK))
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(av[1], "r");
		while (1)
		{
			line_number++;
			gl_status = getline(buffer, &bufsize, file);
			if (gl_status == EOF)
				break;
			opcode = strtok(*buffer, " \t\n");
			printf("opcode: %s\n", opcode);
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
	}
	return (0);
}

