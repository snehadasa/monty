/*Given a .m file...
Check if ac = 2
Check if file exists
Open file and assign it to an fd var
Use fgets to read the file*/

#include "monty.h"
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	FILE *file;
	char **buffer = malloc(256);
	size_t bufsize = 256;
	int gl_status;

	if (ac != 2)
		printf("Wrong number of args, try again dipass\n");
	while (gl_status != EOF)
	{
		if (!access(av[1], R_OK)
				file = fopen(av[1], "r");
		gl_status = getline(buffer, &bufsize, file);
		printf("%s", *buffer);
		printf("getline returned %d\n", gl_status);
	}
	if (!access(av[1], R_OK))
	{
		file = fopen(av[1], "r");
	/*	while (gl_status != EOF)
		{
			gl_status = getline(buffer, &bufsize, file);
			printf("%s", *buffer);
			printf("getline returned %d\n", gl_status);
		}*/
	}
	return (0);
}

