#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 *
 */

int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token, *copy;
    printf("$ ");

    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        perror("getline");
        exit(1);
    }
    copy = strdup(line);
    token = strtok(copy, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    free(copy);
    free(line);
    return 0;
}
