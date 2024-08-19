#include "main.h"
/**
 * check_command - check if the command exists in the PATH 
 * @command: command to be checked
 */
void check_command(char *command)
{
	char *path, *full_path, *dir, *path_copy;
	struct stat st;

	path = getenv("PATH");
	if(!path)
	{
		perror("Path not found");
		exit(1);
	}
	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("Error: Memory allocation failed");
		exit(1);
	}

	dir = strtok(path_copy, ":");

	while(dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2); // +2 for '/' and '\0'
		if (!full_path)
		{
			perror("Error: Memory allocation failed");
			free(path_copy);	
			exit(1);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (stat(full_path, &st) == 0)
		{
			printf("%s: File found in %s\n", command, dir);
			free(full_path);
			free(path_copy);
			return;
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	printf("%s: File does not exist\n", command);
	free(path_copy);
}
/**
 * main - find a file in the PATH
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL, *token;
	size_t len = 0;
	ssize_t nread;
	const char *delimeter = " \n\t";

	while (1)
	{
		write(STDOUT_FILENO, "SimpleShell$ ", 13);
		nread = getline(&line, &len, stdin);
		
		if (nread == -1)
		{
			perror("Error reading line");
			free(line);
			exit(1);
		}
		token = strtok(line, delimeter);
		if (token && strcmp(token, "which") == 0)
		{
			token = strtok(NULL, delimeter);
			while (token)
			{
				check_command(token);
				token = strtok(NULL, delimeter);
			}
		}
		else
		{
		       	perror("Error: command does not exist");
			free(line);
			exit(1);
		}
	}
	free(line);
	return (0);
}

