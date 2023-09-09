#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    printf("[%d] Begin!\n", getpid());

    pid = fork();
    if (pid < 0) {
        perror("fork()");
        exit(1);
    }

    if (pid == 0) {
        // child process
        printf("[%d] Child is working!\n", getpid());
    } else {
        // parent process, pid equals to the ID of the child process
        printf("[%d] Parent is working!\n", getpid());
    }

    exit(0);
}