/**
 * An example loading animation.
 *
 * Created by bmcculley
 * Find this and other c snippets here:
 * https://github.com/bmcculley/c-sampling
 */
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Loading");
    fflush(stdout);
    for (int i = 0; i < 4; i++) {
        sleep(1);
        printf(".");
        fflush(stdout);
    }
    printf("\n");
    return 0;
}