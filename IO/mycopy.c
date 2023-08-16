#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fps, *fpd;
    int currCh;

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

    while(1) {
        currCh = fgetc(fps);
        if(currCh == EOF) {
            break;
        }

        fputc(currCh, fpd);
    }

    fclose(fpd);
    fclose(fps);
}