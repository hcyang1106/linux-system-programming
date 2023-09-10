#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen()");
        exit(1);
    }

    char *linebuf = NULL;
    size_t linesize = 0;

    while (getline(&linebuf, &linesize, fp) > 0) {
        printf("%zu\n", strlen(linebuf));
        printf("%zu\n", linesize);
    }

    fclose(fp);
}