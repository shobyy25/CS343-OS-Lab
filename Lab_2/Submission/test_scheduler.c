// test_scheduler.c
#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_CHILDREN 5

void cpu_bound_work(int iterations) {
    int i, j;
    for (i = 0; i < iterations; i++) {
        for (j = 0; j < 1000000; j++) {
            // CPU intensive work
        }
    }
}

void io_bound_work(int iterations) {
    int i;
    for (i = 0; i < iterations; i++) {
        sleep(1);  // Simulate I/O operation
    }
}

int main(void) {
    int pid;
    int start_time, end_time;
    int burst_times[NUM_CHILDREN] = {10, 5, 15, 8, 12};
    
    printf(1, "Starting scheduler test...\n");
    
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid = fork();
        if (pid == 0) {  // Child process
            set_burst_time(burst_times[i]);
            start_time = uptime();
            
            if (i % 2 == 0) {
                cpu_bound_work(burst_times[i] * 10);
            } else {
                io_bound_work(burst_times[i]);
            }
            
            end_time = uptime();
            printf(1, "Child %d (burst time %d) finished. Runtime: %d\n", 
                   i, burst_times[i], end_time - start_time);
            exit();
        }
    }
    
    // Parent process
    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait();
    }
    
    printf(1, "All children finished.\n");
    exit();
}