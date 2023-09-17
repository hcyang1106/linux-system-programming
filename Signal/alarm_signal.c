#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

static int loop = 1;

static void alarm_handler(int s) {
    loop = 0;
}

int main() {
    int64_t count = 0;

    alarm(5);
    signal(SIGALRM, alarm_handler);

    while (loop) {
        count++;
    }

//    Code below will be a lot slower, since it checks the time each iteration
//    time_t end;
//    end = time(NULL) + 5;
//    while (time(NULL) <= end) {
//        count++;
//    }

    printf("%lld\n", count);

    exit(0);
}