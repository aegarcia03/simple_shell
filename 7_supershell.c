#include "main.h"

/**
 * main - run commands with their full path
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL, *token;
	char **command;
	size_t len = 0;
	ssize_t nread;
	pid_t child_pid;
	int status, i;
	char *delimeter = " :'\n''\t'";
	while (1)
	{
		write(STDOUT_FILENO, "SimpleShell$ ", 13);

		nread = getline(&line, &len, stdin);
	
		if (nread == -1)
		{
			perror("Exiting shell");
			exit(1);
		}
		token = strtok(line, delimeter);

		command = malloc(sizeof(char *) * 1024);
		i = 0;

		while (token != NULL)
		{	
			command[i] = strdup(token);
			token = strtok(NULL, " ");
			i++;
		}
		command[i] = NULL;

		child_pid = fork();
	
		if (!child_pid)
		{
			if (execve(command[0], command, NULL) == -1)
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
