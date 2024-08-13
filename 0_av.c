#include<stdio.h>
/**
 * main - prints all command-line arguments
 * @ac: argument count, parameter unused
 * @av: argument vector
 *
 * Return: 0 on success
 */

int main(__attribute__((unused)) int ac, char **av)
{
	int i;

	for (i = 1; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	
	}
	return (0);
}
