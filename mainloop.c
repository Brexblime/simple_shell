#include "shell.h"

void main_loop(void)
{
	char *prompt = "($) ", *line = malloc(BUFFER_SIZE * sizeof(char *)), **args;
	size_t line_length;
	int status = 1;

	if (line == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	do {
		write(STDERR_FILENO, prompt, _strlen(prompt));
		line = read_line();
		args = parse_line(line);

		if (args[0] != NULL && strcmp(args[0], "exit") == 0)
		{
			free(line);
			free(args);
			exit(EXIT_SUCCESS);
		}
		execute_command(args);
		free(line);
		free(args);
	} while (status);
}
