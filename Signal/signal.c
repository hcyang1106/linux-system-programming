#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

static void int_handler(int s) {
    write(1, "!", 1);
}

int main() {
    int i;

//    signal(SIGINT, SIG_IGN); // pressing ctrl+C does not stop the program
    signal(SIGINT, int_handler); // pressing ctrl+C will execute int_handler

    for (i = 0; i < 10; i++) {
        write(1, "*", 1);
        sleep(1);
    }

    exit(0);
}