#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main () {
    FILE *fp;
    int count = 0;

    while(1) {
        fp = fopen("tmp", "r");
        if (fp == NULL) {
            perror("fopen()");
            break;
        }

        count++;
    }

    printf("count= %d\n", count);

    exit(0);
}