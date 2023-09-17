#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i;

    signal(SIGINT, SIG_IGN); // pressing ctrl C does not stop the program

    for (i = 0; i < 10; i++) {
        write(1, "*", 1);
        sleep(1);
    }

    exit(0);
}