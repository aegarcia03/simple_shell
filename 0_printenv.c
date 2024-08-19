#include "main.h"
/**
 * main - prints the enviroment
 *
 * Return: always 0
 */
int main (int ac, char **av, char **environ)
{
	unsigned int i;
	
	i = 0;
	while(environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}
