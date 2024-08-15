#include "main.h"

/**
 * main - run commands with their full path
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argc;(void)argv;
	char *line = NULL, *token;
	char **array;
	size_t len = 0;
	ssize_t nread;
	pid_t child_pid;
	int status, i;

	while (1)
	{
		write(STDOUT_FILENO, "SimpleShell$ ", 13);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			perror("Exiting shell");
			exit(1);
		}

		token = strtok(line, "\n");
		
		array = malloc(sizeof(char *) * 1024);
		i = 0;
		while (token)
		{	
			array[i] = token;
			token = strtok(NULL, "\n");
			i++;
		}
		array[i] = NULL; 
		child_pid = fork();
	
		if (child_pid == -1)
		{
			perror("Failed to create");
			exit(1);
		}
		if (child_pid == 0)
		{	
			if (execve(array[0], array, NULL) == -1)
			{	
				perror("Could not execute");
				exit(1);
			}
	
		}
		else
		{	
			wait(&status);
		}
	}
	free (line);
	return (0);
}
