/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Gabe Limberg
 * 
 * Brief summary of modifications:
 */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_fault(int fault) { // handler for fault 
    if (fault == SIGSEGV) {
        printf("Segementation fault detected.\n");
    }
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    signal(SIGSEGV, handle_fault); // SIGSEGV is detected and is handled at handle_fault

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program, *is never reached due to the segmentation fault*
    return 0;
}