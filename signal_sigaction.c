/**
 * File: signal_sigaction.c
 * Modified by: Gabe Limberg
 * 
 * Brief summary of program:
 * Handles a signal from SIUSR1 and returns the PID of the sender and receiver
 */

#define _POSIX_C_SOURCE 200809L // need to include for definitions of sig_action
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void handle_usr1(int signo, siginfo_t *info, void *ctx) {
    if (signo == SIGUSR1) {
        siginfo_t sig = *info;      
        printf("Received SIGUSR1 from PID: %d\n", sig.si_pid); // printing out PID of the sender then returns
    }
}

int main(void) {
    struct sigaction sa;
    sa.sa_sigaction = handle_usr1;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    // Register the SIGUSR1 handler
    sigaction(SIGUSR1, &sa, NULL);
    // Command to send SIGUSR1 to this process:
    // kill -USR1 <PID>

    printf("Process waiting for SIGUSR1 (PID: %d)\n", getpid());

    // Wait indefinitely for incoming signals
    while (1) {
        pause();
    }

    return 0;
}