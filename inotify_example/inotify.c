/**
 * An example usage of the inotify api,
 *
 * Created by bmcculley
 * Find this and other c snippets here:
 * https://github.com/bmcculley/c-clowning
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <string.h>
#include <unistd.h>

#define EVENT_SIZE    (sizeof (struct inotify_event))
#define BUF_LEN         (1024 * ( EVENT_SIZE + 16 ))

void help(char *name)
{
 printf("Usage: %s --path <path/to/monitor>\n", name);
 exit(0);
}

int main(int argc, char **argv) 
{
    int length;
    int fd;
    int wd;
    char buffer[BUF_LEN];
    char wpath[256];

    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
    }
    else {
        for (int c = 1; c < argc; c++) {
            if (strcmp(argv[c], "--path") == 0) {
                c++;
                strcpy(wpath, argv[c]);
            }
            else {
                printf("Oops, I don't understand that.\n");
                help(argv[0]);
            }
        }

    }

    fd = inotify_init();

    if (fd < 0) {
        perror("inotify_init");
    }

    wd = inotify_add_watch(fd, wpath, 
        IN_MODIFY | IN_CREATE | IN_DELETE);

    while (1) {
        int i = 0;
        length = read(fd, buffer, BUF_LEN);

        if (length < 0) {
            perror("read");
        }    

        while ( i < length ) {
            struct inotify_event *event = (struct inotify_event *) &buffer[i];
            if (event->len) {
                if (event->mask & IN_CREATE || event->mask & IN_MODIFY) {
                    printf("The file %s was created or modified.\n", event->name);
                }
            }
            i += EVENT_SIZE + event->len;
        }
    }
    (void) inotify_rm_watch(fd, wd);
    (void) close(fd);

    exit(0);
}