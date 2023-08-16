#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    FILE *fps, *fpd;
    char buf[BUFSIZE];
    int n;

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

    while((n = fread(buf, 20, BUFSIZE, fps)) > 0) {
        fwrite(buf, 20, n, fpd);
    }

    fclose(fpd);
    fclose(fps);
}