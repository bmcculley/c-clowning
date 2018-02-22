/**
 * An example of using popen to run a system command and 
 * getting the return value.
 *
 * Created by bmcculley
 * Find this and other c snippets here:
 * https://github.com/bmcculley/c-sampling
 */
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char** argv)
{
    FILE *fp;
    char rstr[1035];
    
    fp = popen("cat /proc/version", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }
    
    while(fgets(rstr, sizeof(rstr)-1, fp) != NULL) {
        printf("%s", rstr);
    }
    
    pclose(fp);
    
    return 0;
}