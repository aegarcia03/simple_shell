#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	
	while (1)
	{
		printf("$ ");
		
		ssize_t nread = getline(&line, &len, stdin);
	
		if (nread == -1) {
			break;
		}

		printf("%s", line);
	}
	free (line);
	return (0);
}	
