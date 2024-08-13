#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
	char *token;
	char *wrdlen;

        printf("$ ");

        nread = getline(&line, &len, stdin);

        if (nread == -1)
        {
                exit(1);
        }
        else
        {
                printf("$ %s", line);
        }
	token = strtok(line, wrdlen);
	
	while (token != NULL)
	{
		printf("%s\n", token);
 		token = strtok(NULL, wrdlen);
	}
	free (line);
        return(0);
}

