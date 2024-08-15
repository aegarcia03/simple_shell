#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 *
 * path_to_file - gets the full path of the file
 * @file_name: argument
 *
 * Return: the path of the file
 */
char *get_file_path(char *file_name)
{
	char *path = getenv("PATH");
	char *full_path;

	if (!path)
	{
		perror("Error path not found");
		return (NULL);
	}
	if (full_path == NULL)
	{
		perror("Full path not found");
		return (NULL);
	}

	return (full_path);
}
