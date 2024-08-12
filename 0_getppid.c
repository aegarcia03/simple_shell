#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
/**
 * main - prints the PID of the parent process.
 *
 * Return: always 0
 */
int main(void)
{
	pid_t parentpid; 
	parentpid = getppid();

	printf("%u\n", parentpid);
	return (0);
}
