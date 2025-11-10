/**
 * File: send_signal.c
 * Modified by: Gabe Limberg
 * 
 * Brief summary of program:
 * Sends SIGUSR1 to the given PID using sigqueue, attaching a random int.
 */

#define _POSIX_C_SOURCE 200809L // need to include for definitions of sig_action
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("No pid presented\n");
        return 1;
    }

    pid_t target = (pid_t)atoi(argv[1]); // pid to be targeted
    srand((unsigned)time(NULL)); // generating random time 
    int rnd = rand();  // assigning random number to rnd

    union sigval sv; // union for use in sigqueue
    sv.sival_int = rnd; // attaching paylod to union

    printf("Sender PID: %d  Sending value: %d to PID: %d\n", getpid(), rnd, target);

    if (sigqueue(target, SIGUSR1, sv) == -1) {
        printf("Failed to send\n");
        return 1;
    }

    return 0;
}