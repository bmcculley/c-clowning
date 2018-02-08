/**
 * An example of using wait, the program starts a child process 
 * which prints a message and pauses. Then the parent process waits 
 * for it. You can interact with the child process in a seperate 
 * terminal. Try killing it, the parent process will keep restarting 
 * it.
 *
 * Created by bmcculley
 * Find this and other c snippets here:
 * https://github.com/bmcculley/c-clowning
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void child_process(void)
{
    printf("Child PID is %ld\n", (long) getpid());
    pause();
}

void parent_process(void) {
	pid_t  pid, w;
    int status;

    pid = fork();
    if (pid == -1) {
    	perror("fork"); exit(EXIT_FAILURE);
    }

    if (pid == 0) {
    	child_process();
    }
    else {
    	do {
    		w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
            if (w == -1) { 
            	perror("waitpid"); exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status)) {
                printf("exited, status=%d\n", WEXITSTATUS(status));
                parent_process();
            } else if (WIFSIGNALED(status)) {
                printf("killed by signal %d\n", WTERMSIG(status));
                parent_process();
            } else if (WIFSTOPPED(status)) {
                printf("stopped by signal %d\n", WSTOPSIG(status));
                parent_process();
            } else if (WIFCONTINUED(status)) {
                printf("continued\n");
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[])
{
	parent_process();
    return 0;
}
