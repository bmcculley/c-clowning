/**
 * An example fork usage, just prints a message and exits.
 *
 * Created by bmcculley
 * Find this and other c snippets here:
 * https://github.com/bmcculley/c-sampling
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void child_process(void)
{
     printf("Hello, this is the child process (pid: %d).\n", getpid());
}

void parent_process(void)
{
     printf("Hello, this is the parent process (pid: %d).\n", getpid());
}

int main(void)
{
     pid_t  pid;

     pid = fork();
     if (pid == 0) {
          child_process();
     }
     else {
          parent_process();
     }
     return 0;
}
