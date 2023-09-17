#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    alarm(10);
    alarm(1);
    alarm(5); // will only wait for five seconds

    while (1);

    exit(0);
}