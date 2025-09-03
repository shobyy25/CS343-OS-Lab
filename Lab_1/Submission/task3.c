#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int retime, rutime, stime, pid;

    // Test Case 1 - Simple CPU-bound Process
    if ((pid = fork()) == 0) {
        // Child process: CPU-bound task
        for (volatile int i = 0; i < 1000000000; i++);
        exit();
    } else {
        // Parent process waits for child
        wait2(&retime, &rutime, &stime);
        printf(1, "Test Case 1 - Simple CPU-bound Process\n");
        printf(1, "Child PID: %d\n", pid);
        printf(1, "Retime: %d\n", retime);
        printf(1, "Rutime: %d\n", rutime);
        printf(1, "Stime: %d\n", stime);
    }

    // Test Case 2 - I/O-bound Process (Sleep)
    if ((pid = fork()) == 0) {
        // Child process: I/O-bound task
        sleep(100);
        exit();
    } else {
        // Parent process waits for child
        wait2(&retime, &rutime, &stime);
        printf(1, "Test Case 2 - I/O-bound Process (Sleep)\n");
        printf(1, "Child PID: %d\n", pid);
        printf(1, "Retime: %d\n", retime);
        printf(1, "Rutime: %d\n", rutime);
        printf(1, "Stime: %d\n", stime);
    }

    // Test Case 3 - Mixed CPU-bound and I/O-bound Process
    if ((pid = fork()) == 0) {
        // Child process: Mixed CPU-bound and I/O-bound task
        for (volatile int i = 0; i < 500000000; i++);
        sleep(50);
        for (volatile int i = 0; i < 500000000; i++);
        exit();
    } else {
        // Parent process waits for child
        wait2(&retime, &rutime, &stime);
        printf(1, "Test Case 3 - Mixed CPU-bound and I/O-bound Process\n");
        printf(1, "Child PID: %d\n", pid);
        printf(1, "Retime: %d\n", retime);
        printf(1, "Rutime: %d\n", rutime);
        printf(1, "Stime: %d\n", stime);
    }

    // Test Case 4 - Multiple Processes
    int retime1, rutime1, stime1, pid1;
    int retime2, rutime2, stime2, pid2;

    if ((pid1 = fork()) == 0) {
        // Child 1: CPU-bound task
        for (volatile int i = 0; i < 1000000000; i++);
        exit();
    }

    if ((pid2 = fork()) == 0) {
        // Child 2: I/O-bound task
        sleep(100);
        exit();
    }

    // Parent process waits for both children
    wait2(&retime1, &rutime1, &stime1);
    wait2(&retime2, &rutime2, &stime2);

    printf(1, "Test Case 4 - Multiple Processes\n");
    printf(1, "Child 1 PID: %d\n", pid1);
    printf(1, "Retime: %d\n", retime1);
    printf(1, "Rutime: %d\n", rutime1);
    printf(1, "Stime: %d\n", stime1);
    printf(1, "Child 2 PID: %d\n", pid2);
    printf(1, "Retime: %d\n", retime2);
    printf(1, "Rutime: %d\n", rutime2);
    printf(1, "Stime: %d\n", stime2);

    // Test Case 5 - Two CPU-bound Processes with Different I/O Wait Times
    // Fork the first child process
    if ((pid1 = fork()) == 0) {
        // First child process: CPU-bound task
        for (volatile int i = 0; i < 1000000000; i++);
        sleep(10);  // Sleep to simulate some I/O wait
        exit();
    }

    // Fork the second child process
    if ((pid2 = fork()) == 0) {
        // Second child process: CPU-bound task
        for (volatile int i = 0; i < 1000000000; i++);
        sleep(20);  // Sleep to simulate some I/O wait
        exit();
    }

    // Parent process waits for the first child
    wait2(&retime, &rutime, &stime);
    printf(1, "Test Case 5 - Two CPU-bound Processes with Different I/O Wait Times\n");
    printf(1, "First Child PID: %d\n", pid1);
    printf(1, "Retime: %d\n", retime);
    printf(1, "Rutime: %d\n", rutime);
    printf(1, "Stime: %d\n", stime);

    // Parent process waits for the second child
    wait2(&retime, &rutime, &stime);
    printf(1, "Second Child PID: %d\n", pid2);
    printf(1, "Retime: %d\n", retime);
    printf(1, "Rutime: %d\n", rutime);
    printf(1, "Stime: %d\n", stime);

    exit();
}
