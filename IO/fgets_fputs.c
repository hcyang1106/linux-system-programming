#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    FILE *fps, *fpd;
    char buf[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }

    fps = fopen(argv[1], "r");
    if (fps == NULL) {
        perror("fopen() source");
        exit(1);
    }

    fpd = fopen(argv[2], "w");
    if (fpd == NULL) {
        fclose(fps); // avoid memory leak
        perror("fopen() dest");
        exit(1);
    }

    while(fgets(buf, BUFSIZE, fps) != NULL) {
        fputs(buf, fpd);
    }

    fclose(fpd);
    fclose(fps);
}