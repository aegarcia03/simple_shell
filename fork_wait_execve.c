#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - executes command in 5 different child processes.
 *
 * Return: 0 on success
 */
int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	char *envp[] = {NULL};
	int i;
	
	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{	
			if(execve(argv[0], argv, envp) == -1)
			{
				perror("Error:");
				_exit(1);
			}
		}
		else
		{
			wait(&status);
			
		}
	}
	return (0);
}
