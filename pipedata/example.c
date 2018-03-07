#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    
    if (!isatty(STDIN_FILENO)) {
    	char buf[BUFSIZ];
    	char msg[BUFSIZ];
    	while (fgets(buf, sizeof buf, stdin)) {
    		strcat(msg, buf);
    	}
	    if (msg[strlen(msg)-1] == '\n') {
	        printf("%s", msg);
	    }
	} else {
      puts("oops, no data piped in.");
    }

    return 0;
}
