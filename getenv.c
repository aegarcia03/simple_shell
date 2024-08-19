#include "main.h"
/**
 * _getenv -  gets an environment variable
 * @name: name of the enviroment variable
 *
 * Return: a pointer to the value of the env
 * NULL if there is not match
 */
char *_getenv(const char *name)
{
	extern char **environ;
	size_t len = strlen(name);
	char **env = environ;

	while (*env)
	{	
		if (strncmp(*env, name, len) == 0 && 
			(*env)[len] == '=')
		{
			return (*env + len + 1);
		}
		env++;
	}
	return (NULL);
}
/*
 * main - ...
 */
int main (void)
{
	char *var_name = "PATH";
	char *value = _getenv(var_name);

	if (value)
	{	
		printf("Value of %s:  %s\n", var_name, value);
	}
	else 
	{
		printf("%s not found\n", var_name);
	}
	return (0);
}
