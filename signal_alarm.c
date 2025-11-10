/**
 * File: signal_alarm.c
 * Modified by: Gabe Limberg
 * 
 * Brief summary of program:
 * Program will receive an alarm from the system using the alarm() function after 
 * 5 seconds. Reaching 5 seconds, the process will close. Process will print out the 
 * an integer every second to indicate where it is in terms of time before reaching 5
 * seconds.
 * 
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal(int output) {
    if (output == SIGALRM) { // handle signal will receive SIGALRM if triggered
        printf("Signal received after 5 seconds\n");
        exit(1); 
    }
}


int main(void) {
    int i = 1; // integer to keep track of how long process runs
    signal(SIGALRM, handle_signal);
    alarm(5); // secnds an alarm after 5 second

    while(1) { // prints an integer every second until reaching 5 seconds 
        printf("%d\n", i++);
        fflush(stdout); 
        sleep(1);
    }
}
