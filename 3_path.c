#include "main.h"
/**
 * print_direcotries - prints one directoy per line
 */
void print_directories(void)
{
	char *path = getenv("PATH");
	char *path_copy;
	char *dir;

	if (!path)
	{
		perror("Error: PATH NOT FOUND\n");
		exit(1);
	}
	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("Error: Memory allocation failed");
			exit(1);
	}

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{	
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
}
/**
 * main - ..
 *
 * Return: ..
 */
int main (void)
{
	print_directories();
	return (0);
}

