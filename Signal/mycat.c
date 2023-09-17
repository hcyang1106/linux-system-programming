#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 8

int main(int argc, char *argv[]) {
    int sfd, dfd = 1;
    char buf[16];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    sfd = open(argv[1], O_RDONLY);
    if (sfd < 0) {
        perror("open()");
        exit(1);
    }

    while(1) {
        int len = read(sfd, buf, BUFSIZE);
        if(len < 0) {
            perror("read()");
            break;
        }

        if (len == 0) {
            break;
        }

        printf("len = %d\n", len);

        int pos = 0;
        while (len > 0) {
            int ret = write(dfd, buf + pos, len);
            if (ret < 0) {
                perror("write()");
                exit(1);
            }

            pos += ret;
            len -= ret;
        }
    }

    close(sfd);
}