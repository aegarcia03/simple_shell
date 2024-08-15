#include "main.h"

/**
 * main - run commands with their full path
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	write(STDOUT_FILENO, "SimpleShell ", 13);
	return (0);
}
